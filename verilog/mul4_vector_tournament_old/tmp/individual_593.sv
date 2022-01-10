module individual_593(input logic [15:0] a1, input logic [15:0] a0, input logic [15:0] b1, input logic [15:0] b0, output logic [15:0] y3, output logic [15:0] y2, output logic [15:0] y1, output logic [15:0] y0);
logic [15:0] r0, r1, r2, r3; 
 always@(*) begin 
	 r0 = a0; r1 = a1; r2 = b0; r3 = b1; 
 	 r0  |=  r2 ;
 	 r0  ^=  r1 ;
 	 r1  &=  a0 ;
 	 r2  |=  r0 ;
 	 r3 = ! r0 ;
 	 r1  ^=  b0 ;
 	 r2  |=  b1 ;
 	 r0 = ! b0 ;
 	 y3 = r3; y2 = r2; y1 = r1; y0 = r0; 
end
endmodule