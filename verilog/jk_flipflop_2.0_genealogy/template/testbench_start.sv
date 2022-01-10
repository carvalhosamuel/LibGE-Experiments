// Use parameter to pass population size to testbench
module testbench();
  // Use integer array to store fitness for all individuals
  integer fitness[`POPULATION_SIZE];

  // Define inputs and outputs to connect to the individuals
  reg clk;
  reg rst;
