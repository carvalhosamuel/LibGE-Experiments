#!/bin/bash

# Define parameters
populations=(150)
generations=(100)
runs=30

# Use task to run simulations independently. Needed for parallelization
task(){
      echo "entered task"
      # Make temporary directory to store run
      tmp_dir=$(mktemp -d -t 360seed1SA_XXXXXXXXXX)

      # Make required folders
      mkdir -p $tmp_dir/log

      # Link necessary files to temporary directory
      ln -s $(realpath ./grammar) $tmp_dir/grammar
      ln -s $(realpath ./template) $tmp_dir/template
      ln -s $(realpath ./data) $tmp_dir/data
      cp -a $(realpath GEGCC) $tmp_dir/GEGCC

      # Change into the temporary directory - Needed to make log files be created in the temporary directory
      cd $tmp_dir

      # Run simulation
      #echo "$tmp_dir/GEGCC pop $1 gen $2 > $tmp_dir/log/shell_output.log"
      echo "pop $1 gen $2 run $3"
      $($tmp_dir/GEGCC pop $1 gen $2 > $tmp_dir/log/shell_output.log)

      # Return to calling directory
      cd - > /dev/null

      # Copy results to multirun
      $(mkdir -p multirun/log_pop_$1_gen_$2_run_$3)
      $(cp -a $tmp_dir/log/*.log multirun/log_pop_$1_gen_$2_run_$3)
      $(cp -a $tmp_dir/tmp/test_results* multirun/log_pop_$1_gen_$2_run_$3)

      # Remove temporary directory
      rm -rf $tmp_dir
}

# Export task so we can call it with GNU parallel
export -f task

# Create directory to store logs
$(mkdir -p ./multirun)

# Create a temporary directory for each run so we can parallelize the runs
for ((run = 1; run <= runs; run++))
do
  for population in ${populations[@]}
  do
    for generation in ${generations[@]}
    do
        sem --id libge -j+30 task ${population} ${generation} ${run}
    done
  done
done

# Wait for jobs to complete
sem --wait
echo "DONE"
