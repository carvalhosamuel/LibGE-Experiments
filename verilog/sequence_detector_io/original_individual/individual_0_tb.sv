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
		reset = 1;
		i = 0;
		#7;
		reset = 1;
		i = 1;
		#20
		reset = 1;
		i = 0;
		#20
		reset = 1;
		i = 0;
		#20
		reset = 1;
		i = 1;
		#20
		reset = 1;
		i = 1;
		#20
		reset = 1;
		i = 0;
		#20
		reset = 1;
		i = 1;
		#20
		reset = 1;
		i = 1;
		#20
		reset = 1;
		i = 1;
		#20
		reset = 1;
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
		i = 1;
		#20
		reset = 0;
		i = 0;
		
		 
	  	$finish;
	
	
	
	end
	
      
endmodule
