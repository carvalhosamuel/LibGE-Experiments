module full_adder

  (

    input  logic[7:0] a, b, c,

	output logic[7:0] s, co

  );

  

 logic [7:0] r0, r1, r2; 
always@(*) begin 
	r0 = a; r1 = b; r2 = c;
 	 r1  ^=  a ;
 	 r0  ^=  r2 ;
 	 r0  |=  r0 ;
 	 r1  |=  r1 ;
 	 r0  |=  r1 ;
 	 r2  ^=  r1 ;
 	 r0  ^=  r2 ;
 	 r1  ^=  r0 ;
 	s = r2; co = r0; 
end






  

endmodule
