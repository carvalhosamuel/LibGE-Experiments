logic [15:0] r0, r1, r2, r3; 
 always@(*) begin 
	 r0 = a0; r1 = a1; r2 = b0; r3 = b1; 
 	 r2 = ! a0 ;
 	 y3 = r3; y2 = r2; y1 = r1; y0 = r0; 
end