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

    // Set the clock high so we get posedges at 10,20,30 etc.
    //clk = 1;
    clk = 1; rst = 1;
    #(`PERIOD) rst = 0;

    // Set all scores to zero
    for(int i = 0; i < `POPULATION_SIZE; i++) begin
      fitness[i] = 0;
    end
     
    // Wait 8 clock cycles for test to complete
    #(`PERIOD*`TEST_COUNT);

    // Print all fitness scores to the console
    for(int i = 0; i < `POPULATION_SIZE; i++) begin
      //$display("%0d, %0d",$time, fitness[i]);
      $display("%0d",fitness[i]);
    end

    $finish;
  end
 endmodule
