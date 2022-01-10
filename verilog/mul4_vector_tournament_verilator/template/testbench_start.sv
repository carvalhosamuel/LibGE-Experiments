// Use parameter to pass population size to testbench
module testbench();
  // Use integer array to store fitness for all individuals
  integer fitness[`POPULATION_SIZE];

  // Define inputs and outputs to connect to the individuals
  reg clk;
  reg rst;
  reg [15:0] y3_current[`POPULATION_SIZE];
  reg [15:0] y3_expected;
  reg [15:0] y2_current[`POPULATION_SIZE];
  reg [15:0] y2_expected;
  reg [15:0] y1_current[`POPULATION_SIZE];
  reg [15:0] y1_expected;
  reg [15:0] y0_current[`POPULATION_SIZE];
  reg [15:0] y0_expected;

