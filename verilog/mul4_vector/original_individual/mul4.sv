module mul4

  (

    input  logic[15:0] a1, a0, b1, b0,

    output logic[15:0] y3, y2, y1, y0

  );

  

logic [15:0] r0, r1, r2, r3, r4, r5, r6, r7; 
 always@(*) begin 
	 r0 = a0; r1 = a1; r2 = b0; r3 = b1; 
 	 r7 = ! b1 ;
 	 r7  |=  a0 ;
 	 r7  &=  b0 ;
 	 r6 = ! a1 ;
 	 r1  |=  a0 ;
 	 r1  ^=  b1 ;
 	 r4 = ! b0 ;
 	 r5 = ! r3 ;
 	 r4 = ! r5 ;
 	 y3 = r4; y2 = r5; y1 = r6; y0 = r7; 
end







  

endmodule
