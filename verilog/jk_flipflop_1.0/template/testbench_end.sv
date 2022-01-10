  // We use a clock to load in our testvectors
  always begin
    #(`PERIOD/2) clk = ~clk;
  end

  // We want to change our inputs on negedge so that we can run testcases at
  // posedge
  always @(posedge clk) begin
    if(rst == 1) begin
      {j,k} = testvectors[vectornum];
      vectornum = vectornum + 1;
      testcase(j,k);
    end
  end

  // Run simulation
  initial begin
    // Create VCD file
    //$dumpfile("dump.vcd");
    //$dumpvars(0,jk_flipflop_tb);

    // Set the clock high so we get posedges at 10,20,30 etc.
    clk = 1; rst = 0;
    #(`PERIOD) rst = 1;

    // Read in test vectors
    $readmemb("src/example.tv", testvectors);

    // Set all scores to zero
    for(int i = 0; i < `POPULATION_SIZE; i++) begin
      fitness[i] = 0;
    end
    
    #(`PERIOD*`TEST_COUNT) // Wait 8 clock cycles for test to complete

    // Print all fitness scores to the console
    for(int i = 0; i < `POPULATION_SIZE; i++) begin
      $display("%0d",fitness[i]);
    end

    $finish;
  end
 endmodule
