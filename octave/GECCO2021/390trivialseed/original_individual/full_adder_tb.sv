`timescale 1 ns/10 ps



module full_adder_testbench;

   // signal declaration

   //int misses_s;
   //int misses_co;
   int fitness;

   logic [7:0] test_a, test_b, test_c, test_s, test_co, misses_s, misses_co;



   // instantiate the circuit under test

   full_adder uut

      (.a(test_a), .b(test_b), .c(test_c), .s(test_s), .co(test_co));



   initial
 
   begin
	 
	
	 
	  // test vectors

      test_a = 8'b00001111;

      test_b = 8'b00110011;

	  test_c = 8'b01010101;

	  # 200;

	  // calculate hamming distance

	  misses_s = (test_s  ^ 8'b01101001);
	  misses_co = (test_co ^ 8'b00010111);

	  $display("misses_s = %b ", misses_s);
	  $display("NOT misses_s = %b ", ~misses_s);
	  
	  $display("misses_co = %b ", misses_co);
	  $display("NOT misses_co = %b ", ~misses_co);
	  
	  $display("test_s = %b ", test_s);
	  $display("test_co = %b ", test_co);
	  $display($countones(misses_s));
	  $display($countones(misses_co));
	  
	  
	  fitness  = $countones(~(test_s  ^  8'b01101001)) + $countones(~(test_co ^ 8'b00010111));
	  $display(fitness);

	  # 200;

      // stop simulation

      $finish;

   end

endmodule


