// Use parameter to pass population size to testbench
module jk_flipflop_tb();
  // Define inputs and outputs to connect to the individuals
  logic clk, rst;
  logic j, k;
  logic q_current[`POPULATION_SIZE],q_previous[`POPULATION_SIZE];

  // Use integer array to store fitness for all individuals
  integer fitness[`POPULATION_SIZE];

  // Array of testvectors to store expected values
  reg [4:0] testvectors[0:(`TEST_COUNT-1)];
  integer vectornum = 0;

  // Initialise q_previous to zero so we can check against it
  initial begin
    for(int i =0; i < `POPULATION_SIZE; i++) begin
      q_previous[i] = 1'b0;
    end
  end
