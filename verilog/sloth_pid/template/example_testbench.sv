// Example testbench - Not used by LibGE but makes the structure of the
// generated testbench easier to understand.

// Include all individivuals
`include "tmp/individual_0.sv"
`include "tmp/individual_1.sv"
`include "tmp/individual_2.sv"
`include "tmp/individual_3.sv"
`include "tmp/individual_4.sv"

// Definitions
`define population_size 20
`define test_count 8
`define period 10

// Use parameter to pass population size to testbench
module fulladder_tb();
  // Define inputs and outputs to connect to the individuals
  logic clk;
  logic a, b, ci, sum_expected, co_expected;
  logic sum[`population_size],co[`population_size];

  // Use integer array to store fitness for all individuals
  integer fitness[`population_size];

  // Array of testvectors to store expected values
  reg [4:0] testvectors[0:`test_count-1];
  integer vectornum = 0;
  
  // Instantiate all the individuals
  fulladder_0 dut0(.a(a),.b(b),.ci(ci),.sum(sum[0]),.co(co[0]));
  fulladder_1 dut1(.a(a),.b(b),.ci(ci),.sum(sum[1]),.co(co[1]));
  fulladder_2 dut2(.a(a),.b(b),.ci(ci),.sum(sum[2]),.co(co[2]));
  fulladder_3 dut3(.a(a),.b(b),.ci(ci),.sum(sum[3]),.co(co[3]));
  fulladder_4 dut4(.a(a),.b(b),.ci(ci),.sum(sum[4]),.co(co[4]));

  // Create task to evaluate each testcase
  // Note that this evaluates the entire population for this testcase
  task testcase;
    input a_value,b_value, ci_value, sum_value, co_value;

    // Initialise inputs
    a = a_value; b = b_value; ci = ci_value;

    #`period/2 // Wait till negative clock edge to check signals
    for(int i = 0; i < `population_size; i++) begin
      if(sum[i] == sum_value && co[i] == co_value) begin
        fitness[i] = fitness[i] + 1;
      end
    end
  endtask

  // We use a clock to load in our testvectors
  always begin
    #`period/2 clk = ~clk;
  end

  // We want to change our inputs on negedge so that we can run testcases at
  // posedge
  always @(posedge clk) begin
    {a,b,ci,sum_expected,co_expected} = testvectors[vectornum];
    vectornum = vectornum + 1;
    testcase(a,b,ci,sum_expected,co_expected);
  end

  // Run simulation
  initial begin
    // Set the clock high so we get posedges at 10,20,30 etc.
    clk = 1;

    // Read in test vectors
    $readmemb("src/example.tv", testvectors);

    // Set all scores to zero
    for(int i = 0; i < `population_size; i++) begin
      fitness[i] = 0;
    end
    
    #`period*8 // Wait 8 clock cycles for test to complete

    // Print all fitness scores to the console
    for(int i = 0; i < `population_size; i++) begin
      $display("%0d",fitness[i]);
    end

    $finish;
  end
 endmodule
