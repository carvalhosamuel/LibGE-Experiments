// Declare timescale
`timescale 1ms/1us

// Include all individivuals
`include "tmp/individual_10.sv"
`include "tmp/individual_11.sv"
`include "tmp/individual_14.sv"
`include "tmp/individual_15.sv"
`include "tmp/individual_16.sv"
`include "tmp/individual_17.sv"
`include "tmp/individual_18.sv"
`include "tmp/individual_19.sv"


// Definitions
`define POPULATION_SIZE 20
`define TEST_COUNT 20
`define PERIOD 10
`define CYCLES_PER_TEST 1

// Use parameter to pass population size to testbench
module testbench();
  // Use integer array to store fitness for all individuals
  integer fitness[`POPULATION_SIZE];
  integer run_test;

  // Define inputs and outputs to connect to the individuals
  reg clk;
  reg rst;
  	reg sel;
	reg [2:0] q_expected;
	wire [2:0] q_current[`POPULATION_SIZE];


	// Array of testvectors to store expected values
	reg [4:0] testvectors[0:(`TEST_COUNT-1)];
	integer vectornum = 0;

	// Instantiate all the individuals
    individual_10 dut_10(.clk(clk), .rst(rst), .sel(sel), .q(q_current[10]));
  individual_11 dut_11(.clk(clk), .rst(rst), .sel(sel), .q(q_current[11]));
  individual_14 dut_14(.clk(clk), .rst(rst), .sel(sel), .q(q_current[14]));
  individual_15 dut_15(.clk(clk), .rst(rst), .sel(sel), .q(q_current[15]));
  individual_16 dut_16(.clk(clk), .rst(rst), .sel(sel), .q(q_current[16]));
  individual_17 dut_17(.clk(clk), .rst(rst), .sel(sel), .q(q_current[17]));
  individual_18 dut_18(.clk(clk), .rst(rst), .sel(sel), .q(q_current[18]));
  individual_19 dut_19(.clk(clk), .rst(rst), .sel(sel), .q(q_current[19]));


	// Create task to evaluate each testcase
	// Note that this evaluates the entire population for this testcase
	task testcase;
    input sel_value;
		input [2:0] q_value;


		// Initialise inputs
    		sel=sel_value;


    // Wait for signals to settle
		#0 for(int i = 0; i < `POPULATION_SIZE; i++) begin
            if(q_current[i] == q_value) begin
          fitness[i] = fitness[i] + 1;
      end


		end
	endtask

  // Load our test vectors on the negative edge so that we are ready to run
  // the tests on positive edge
	always @(negedge clk) begin
		if (rst == 0) begin
      // Run test if enough cycles have passed
      if(run_test == `CYCLES_PER_TEST) begin
			{sel, q_expected} = testvectors[vectornum];
			vectornum = vectornum + 1;
      run_test = 1;
      end
      else begin
        run_test++;
      end
    end
	end

  // Run tests on posedge
  always @(posedge clk) begin
		if (rst == 0) begin
      if(run_test == `CYCLES_PER_TEST) begin
        testcase(sel, q_expected);
      end
    end
  end

  // We use a clock to load in our testvectors
  always begin
    #(`PERIOD/2) clk = ~clk;
  end

  // Run simulation
  initial begin
    // DEBUGGING - Dump to vcd file
    $dumpfile("testbench_values.vcd");
    $dumpvars(0,testbench);

    // Read in test vectors
    $readmemb("template/test_vectors.tv", testvectors);

    // Set all scores to zero
    for(int i = 0; i < `POPULATION_SIZE; i++) begin
      fitness[i] = 0;
    end

    // Ensure that the tests run the first clock after reset goes low
    run_test = `CYCLES_PER_TEST;

    // Set the clock high so we get posedges at 10,20,30 etc.
    clk = 0; rst = 1;
    #(`PERIOD) rst = 0;
     
    // Wait 8 clock cycles for test to complete
    #(`PERIOD*`TEST_COUNT+1);

    // Print all fitness scores to the console
    for(int i = 0; i < `POPULATION_SIZE; i++) begin
      $display("%0d",fitness[i]);
    end

    // Finish Simulation
    $finish;
  end
 endmodule
