  // Create task to evaluate each testcase
  // Note that this evaluates the entire population for this testcase
  task testcase;
    input j_value,k_value;

    // Initialise inputs
    j = j_value; k = k_value;

    #(`PERIOD/2) // Wait till negative clock edge to check signals
    for(int i = 0; i < `POPULATION_SIZE; i++) begin
      // Hold State -> Qn = Q
      if(j == 0 && k == 0) begin
        if(q_current[i] == q_previous[i]) begin
          fitness[i] = fitness[i] + 1;
        end
      end

      // Reset -> Qn = 0
      if(j == 0 && k == 1) begin
        if(q_current[i] == 0) begin
          fitness[i] = fitness[i] + 1;
        end
      end

      // Set -> Qn = 1
      if(j == 1 && k == 0) begin
        if(q_current[i] == 1) begin
          fitness[i] = fitness[i] + 1;
        end
      end

      // Toggle -> Qn = ~Q
      if(j == 1 && k == 1) begin
        if(q_current[i] == ~(q_previous[i])) begin
          fitness[i] = fitness[i] + 1;
        end
      end

      // Set q_previous for next clock
      q_previous[i] = q_current[i];
    end
  endtask
