`timescale 1 ns/10 ps



module mul4_testbench;

   // signal declaration

   //int misses_s;
   //int misses_co;
   int fitness;

   logic [15:0] test_a1, test_a0, test_b1, test_b0, test_y3, misses_y3, test_y2, misses_y2, test_y1, misses_y1, test_y0, misses_y0;



   // instantiate the circuit under test

   mul4 uut

      (.a1(test_a1), .a0(test_a0), .b1(test_b1), .b0(test_b0), .y3(test_y3), .y2(test_y2), .y1(test_y1), .y0(test_y0));



   initial
 
   begin
	 
	
	 
	  // test vectors

      test_a1 = 16'b0000000011111111;
      test_a0 = 16'b0000111100001111;

      test_b1 = 16'b0011001100110011;
      test_b0 = 16'b0101010101010101;

	  # 200;

	  // calculate hamming distance

	  misses_y3 = (test_y3  ^ 16'b0000000000000001);
	  misses_y2 = (test_y2  ^ 16'b0000000000110010);
	  misses_y1 = (test_y1  ^ 16'b0000001101010110);
	  misses_y0 = (test_y0  ^ 16'b0000010100000101);


	  $display("misses_y3 = %b ", misses_y3);
	  $display("misses_y2 = %b ", misses_y2);
	  $display("misses_y1 = %b ", misses_y1);
	  $display("misses_y0 = %b ", misses_y0);
	 
	  
	  
	  
	  fitness  = $countones(~misses_y3) + $countones(~misses_y2) + $countones(~misses_y1) + $countones(~misses_y0);
	  $display("fitness = %d", fitness);

	  # 200;

      // stop simulation

      $finish;

   end

endmodule


