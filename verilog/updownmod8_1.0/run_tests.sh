#!/bin/bash

# Define parameters
simulators=('icarus' 'modelsim' 'vivado')
populations=(10 20)
generations=(2 5)

# Create directory to store logs
$(mkdir -p ./multirun)

# Run simulation for each value and copy logs to multirun
for population in ${populations[@]}
do
  for generation in ${generations[@]}
  do
    for simulator in ${simulators[@]}
    do
      # Run simulation
      echo "./GEGCC pop ${population} gen ${generation} sim ${simulator} > log/shell_output.log"
      $(./GEGCC pop ${population} gen ${generation} sim ${simulator} > log/shell_output.log)
      
      # Copy results to multirun
      $(mkdir -p multirun/log_pop_${population}_gen_${generation}_sim_${simulator})
      $(cp -a log/*.log multirun/log_pop_${population}_gen_${generation}_sim_${simulator})
    done
  done
done
