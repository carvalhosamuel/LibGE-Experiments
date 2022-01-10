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

		// Wait 15 ns for global reset to finish
		#15;
        
		// Add stimulus here
		
		
		// RESETS
		
		reset = 1;
		i = 0;
		#20;
		
		//0000
		
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
		#20;
		
		reset = 1;
		i = 0;
		#20;
		
		//0001
		
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
		#20;
		
		reset = 1;
		i = 0;
		#20;
		
		//0010
		
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
		i = 0;
		#20
		
		// RESETS
		
		reset = 1;
		i = 0;
		#20;
		
		reset = 1;
		i = 0;
		#20;
		
		//0011
		
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
		
		// RESETS
		
		reset = 1;
		i = 0;
		#20;
		
		reset = 1;
		i = 0;
		#20;
		
		//0100
		
		reset = 0;
		i = 0;
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
		
		// RESETS
		
		reset = 1;
		i = 0;
		#20;
		
		reset = 1;
		i = 0;
		#20;
		
		//0101
		
		reset = 0;
		i = 0;
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
		#20;
		
		reset = 1;
		i = 0;
		#20;
		
		//0110
		
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
		
		// RESETS
		
		reset = 1;
		i = 0;
		#20;
		
		reset = 1;
		i = 0;
		#20;
		
		//0111
		
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
		i = 1;
		#20
		
		// RESETS
		
		reset = 1;
		i = 0;
		#20;
		
		reset = 1;
		i = 0;
		#20;
		
		//1000
		
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
		i = 0;
		#20
		
		// RESETS
		
		reset = 1;
		i = 0;
		#20;
		
		reset = 1;
		i = 0;
		#20;
		
		//1001
		
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
		
		// RESETS
		
		reset = 1;
		i = 0;
		#20;
		
		reset = 1;
		i = 0;
		#20;
		
		//1010
		
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
		i = 0;
		#20
		
		// RESETS
		
		reset = 1;
		i = 0;
		#20;
		
		reset = 1;
		i = 0;
		#20;
		
		//1011
		
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
		
		// RESETS
		
		reset = 1;
		i = 0;
		#20;
		
		reset = 1;
		i = 0;
		#20;
		
		//1100
		
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
		
		// RESETS
		
		reset = 1;
		i = 0;
		#20;
		
		reset = 1;
		i = 0;
		#20;
		
		//1101 THIS ONE
		
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
		#20;
		
		reset = 1;
		i = 0;
		#20;
		
		//1110 
		
		reset = 0;
		i = 1;
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
		
		// RESETS
		
		reset = 1;
		i = 0;
		#20;
		
		reset = 1;
		i = 0;
		#20;
		
		//1111 
		
		reset = 0;
		i = 1;
		#20
		
		reset = 0;
		i = 1;
		#20
		
		reset = 0;
		i = 1;
		#20
		
		reset = 0;
		i = 1;
		#20
		
		// RESETS
		
		reset = 1;
		i = 0;
		#20;
		
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
		
		
		
			 
	  	$finish;
	
	
	
	end
	
      
endmodule
