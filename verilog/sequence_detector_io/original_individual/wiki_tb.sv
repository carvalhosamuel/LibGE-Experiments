`timescale 1ns / 1ns

module individual_0_tb;

	// Inputs
	reg i;
	reg clock;
	reg reset;

	// Outputs
	wire out;
	

	// Instantiate the Unit Under Test (UUT)
	individual_0 uut (
		.i(i), 
		.clock(clock), 
		.out(out),
		.reset(reset)
	
	);
	initial begin
		forever #10 clock = ~clock;
		
	end
	
	initial begin
		// Initialize Inputs
		i = 0;
		clock = 0;
		reset = 0;

		// Wait 10 ns for global reset to finish
		#10;
        
		// Add stimulus here
		
		#5;
		
		// RESETS
		
		reset = 1;
		i = 0;
		#20;
		
		//FIRST SEQUENCE 1101101
		
		reset = 0;
		i = 1;
		#20
		
		reset = 0;
		i = 1;
		#20
		
		reset = 0;
		i = 0;
		#20
		
		reset = 0;
		i = 1;
		#20
		
		reset = 0;
		i = 1;
		#20
		
		reset = 0;
		i = 0;
		#20
		
		reset = 0;
		i = 1;
		#20
				
		// RESETS 
		reset = 1;
		i = 0;
		#20
		
		reset = 1;
		i = 0;
		#20
		 
		// SECOND SEQUENCE 1001101	
		
		reset = 0;
		i = 1;
		#20
		
		reset = 0;
		i = 0;
		#20
		
		reset = 0;
		i = 0;
		#20
		
		reset = 0;
		i = 1;
		#20
		
		reset = 0;
		i = 1;
		#20
		
		reset = 0;
		i = 0;
		#20
		
		reset = 0;
		i = 1;
		#20
		
		// RESETS 
		reset = 1;
		i = 0;
		#20
		 
		reset = 1;
		i = 0;
		#20
		
		// THIRD SEQUENCE 1101 
		
		reset = 0;
		i = 1;
		#20
		
		reset = 0;
		i = 1;
		#20
		
		reset = 0;
		i = 0;
		#20
		
		reset = 0;
		i = 1;
		#20
		
		// RESETS 
		reset = 1;
		i = 0;
		#20
		 
		reset = 1;
		i = 0;
		#20
		
		// FOURTH SEQUENCE 0000 
		
		reset = 0;
		i = 0;
		#20
		
		reset = 0;
		i = 0;
		#20
		
		reset = 0;
		i = 0;
		#20
		
		reset = 0;
		i = 0;
		#20
		
		// RESETS 
		reset = 1;
		i = 0;
		#20
		 
		reset = 1;
		i = 0;
		#20
		
		// FIFTH SEQUENCE 0001 
		
		reset = 0;
		i = 0;
		#20
		
		reset = 0;
		i = 0;
		#20
		
		reset = 0;
		i = 0;
		#20
		
		reset = 0;
		i = 1;
		#20
		
		// RESETS 
		reset = 1;
		i = 0;
		#20
		 
		reset = 1;
		i = 0;
		#20
		
		// SIXTH SEQUENCE 1100 
		
		reset = 0;
		i = 1;
		#20
		
		reset = 0;
		i = 1;
		#20
		
		reset = 0;
		i = 0;
		#20
		
		reset = 0;
		i = 0;
		#20
			 
	  	$finish;
	
	
	
	end
	
      
endmodule
