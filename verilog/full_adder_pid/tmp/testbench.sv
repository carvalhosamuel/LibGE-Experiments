// Include all individivuals
`include "tmp/individual_0.sv"
`include "tmp/individual_1.sv"
`include "tmp/individual_2.sv"
`include "tmp/individual_3.sv"
`include "tmp/individual_4.sv"
`include "tmp/individual_5.sv"
`include "tmp/individual_6.sv"
`include "tmp/individual_7.sv"
`include "tmp/individual_8.sv"
`include "tmp/individual_9.sv"
`include "tmp/individual_10.sv"
`include "tmp/individual_11.sv"
`include "tmp/individual_12.sv"
`include "tmp/individual_13.sv"
`include "tmp/individual_14.sv"

// Definitions
`define POPULATION_SIZE 15
`define TEST_COUNT 2
`define PERIOD 10

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

	reg [15:0] a1;
	reg [15:0] a0;
	reg [15:0] b1;
	reg [15:0] b0;

	// Array of testvectors to store expected values
	reg [127:0] testvectors[0:(`TEST_COUNT-1)];
	integer vectornum = 0;

	// Instantiate all the individuals
  individual_0 dut_0(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[0]), .y2(y2_current[0]), .y1(y1_current[0]), .y0(y0_current[0]));
  individual_1 dut_1(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[1]), .y2(y2_current[1]), .y1(y1_current[1]), .y0(y0_current[1]));
  individual_2 dut_2(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[2]), .y2(y2_current[2]), .y1(y1_current[2]), .y0(y0_current[2]));
  individual_3 dut_3(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[3]), .y2(y2_current[3]), .y1(y1_current[3]), .y0(y0_current[3]));
  individual_4 dut_4(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[4]), .y2(y2_current[4]), .y1(y1_current[4]), .y0(y0_current[4]));
  individual_5 dut_5(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[5]), .y2(y2_current[5]), .y1(y1_current[5]), .y0(y0_current[5]));
  individual_6 dut_6(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[6]), .y2(y2_current[6]), .y1(y1_current[6]), .y0(y0_current[6]));
  individual_7 dut_7(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[7]), .y2(y2_current[7]), .y1(y1_current[7]), .y0(y0_current[7]));
  individual_8 dut_8(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[8]), .y2(y2_current[8]), .y1(y1_current[8]), .y0(y0_current[8]));
  individual_9 dut_9(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[9]), .y2(y2_current[9]), .y1(y1_current[9]), .y0(y0_current[9]));
  individual_10 dut_10(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[10]), .y2(y2_current[10]), .y1(y1_current[10]), .y0(y0_current[10]));
  individual_11 dut_11(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[11]), .y2(y2_current[11]), .y1(y1_current[11]), .y0(y0_current[11]));
  individual_12 dut_12(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[12]), .y2(y2_current[12]), .y1(y1_current[12]), .y0(y0_current[12]));
  individual_13 dut_13(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[13]), .y2(y2_current[13]), .y1(y1_current[13]), .y0(y0_current[13]));
  individual_14 dut_14(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[14]), .y2(y2_current[14]), .y1(y1_current[14]), .y0(y0_current[14]));

	// Create task to evaluate each testcase
	// Note that this evaluates the entire population for this testcase
	task testcase;
		input [15:0] a1_value;
input [15:0] a0_value;
input [15:0] b1_value;
input [15:0] b0_value;
input [15:0] y3_value;
input [15:0] y2_value;
input [15:0] y1_value;
input [15:0] y0_value;


		// Initialise inputs
		a1=a1_value;
		a0=a0_value;
		b1=b1_value;
		b0=b0_value;

		for(int i = 0; i < `POPULATION_SIZE; i++) begin
 // calculate hamming distance
 fitness[i]  = $countones(~(y3_current[i]  ^ y3_value)) + $countones(~(y2_current[i]  ^ y2_value)) + $countones(~(y1_current[i]  ^ y1_value)) + $countones(~(y0_current[i]  ^ y0_value));

		end
	endtask

	// We want to change our inputs on negedge so that we can run testcases at posedge
	always @(posedge clk) begin
		if (rst == 0) begin
			{a1, a0, b1, b0, y3_expected, y2_expected, y1_expected, y0_expected} = testvectors[vectornum];
			vectornum = vectornum + 1;
		end

	end

	always @(posedge clk) begin
		if (rst == 0) begin
			testcase(a1, a0, b1, b0, y3_expected, y2_expected, y1_expected, y0_expected);
		end

	end

  // We use a clock to load in our testvectors
  always begin
    #(`PERIOD/2) clk = ~clk;
  end

  // Run simulation
  initial begin
    // Set the clock high so we get posedges at 10,20,30 etc.
    //clk = 1;
    clk = 1; rst = 1;
    #(`PERIOD) rst = 0;

    // DEBUGGING - Dump to vcd file
    //$dumpfile("testbench_values.vcd");
    //$dumpvars(0,fulladder_tb);

    // Read in test vectors
    $readmemb("template/test_vectors.tv", testvectors);
    // test vectors
    $writememb("tmp/memory_b.txt",testvectors);
	
    // Set all scores to zero
    for(int i = 0; i < `POPULATION_SIZE; i++) begin
      fitness[i] = 0;
    end
     
    // Wait clock cycles for test to complete
    #(`PERIOD*`TEST_COUNT);
    
    // Print all fitness scores to the console
    for(int i = 0; i < `POPULATION_SIZE; i++) begin
      $display("%0d",fitness[i]);
    end

    $finish;
  end
 endmodule
