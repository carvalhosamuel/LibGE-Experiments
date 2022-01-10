#!/bin/bash

# Define parameters
minSizes=(15 20 25 30 35 40)
maxSizes=(50 60 70 80 90 100)
wraps=(0 5 10 25 50)
runs=30
n=0

# Use task to run simulations independently. Needed for parallelization
task(){
      echo "entered task"
      # Make temporary directory to store run
      tmp_dir=$(mktemp -d -t mcge30_gridsearch_XXXXXXXXXX)

      # Make required folders
      mkdir -p $tmp_dir/log

      # Link necessary files to temporary directory
      ln -s $(realpath ./grammar.bnf) $tmp_dir/grammar.bnf
      ln -s $(realpath ./*.c) $tmp_dir/
      ln -s $(realpath ./*.h) $tmp_dir/
      ln -s $(realpath ./*.cpp) $tmp_dir/
      #ln -s $(realpath ./data) $tmp_dir/data
      cp -a $(realpath GEGCC) $tmp_dir/GEGCC

      # Change into the temporary directory - Needed to make log files be created in the temporary directory
      cd $tmp_dir

      # Run simulation
     
      echo "INSIDE TASK min $1 max $2 wrap $3 run $4 current $5"
      $($tmp_dir/GEGCC min $1 max $2 wrap $3 seed 0 > $tmp_dir/log/shell_output.log)

      # Return to calling directory
      cd - > /dev/null

      # Copy results to multirun
      $(mkdir -p multirun/log_min_$1_max_$2_wrap_$3_run_$4_current_$5)
      $(cp -a $tmp_dir/log/*.log multirun/log_min_$1_max_$2_wrap_$3_run_$4_current_$5)
      #$(cp -a $tmp_dir/tmp/test_results* multirun/log_pop_$1_gen_$2_run_$3)

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
  for minSize in ${minSizes[@]}
  do
    for maxSize in ${maxSizes[@]}
    do
      for wrap in ${wraps[@]}
      do
         
    	 (( n += 1 )) 
    	 #echo "pop ${population} gen ${generation} mut ${mutation} xover ${crossover} run ${run} current ${n}" 
         sem --id libge -j0 task ${minSize} ${maxSize} ${wrap} ${run} ${n}
         #sem --id libge -j0 task ${population} ${generation} ${run} ${n}
    	 
      done
    done
  done
done

# Wait for jobs to complete
sem --wait
echo "DONE"
