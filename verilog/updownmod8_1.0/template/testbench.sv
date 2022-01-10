// Declare timescale
`timescale 1ms/1us

// Include all individivuals
<<<include>>>

// Definitions
`define POPULATION_SIZE <<<population_size>>>
`define TEST_COUNT <<<test_count>>>
`define PERIOD <<<period>>>
`define CYCLES_PER_TEST <<<cycles_per_test>>>

// Use parameter to pass population size to testbench
module testbench();
  // Use integer array to store fitness for all individuals
  integer fitness[`POPULATION_SIZE];
  integer run_test;

  // Define inputs and outputs to connect to the individuals
  reg clk;
  reg rst;
  <<<testbench_variables>>>

	// Array of testvectors to store expected values
	reg [<<<port_count>>>:0] testvectors[0:(`TEST_COUNT-1)];
	integer vectornum = 0;

	// Instantiate all the individuals
  <<<instantiate_individuals>>>

	// Create task to evaluate each testcase
	// Note that this evaluates the entire population for this testcase
	task testcase;
    <<<task_inputs>>>

		// Initialise inputs
    <<<assign_inputs>>>

    // Wait for signals to settle
		#0 for(int i = 0; i < `POPULATION_SIZE; i++) begin
      <<<testcase>>>
		end
	endtask

  // Load our test vectors on the negative edge so that we are ready to run
  // the tests on positive edge
	always @(negedge clk) begin
		if (rst == 0) begin
      // Run test if enough cycles have passed
      if(run_test == `CYCLES_PER_TEST) begin
			{<<<load_testbench_variables>>>} = testvectors[vectornum];
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
        testcase(<<<load_testbench_variables>>>);
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
