module individual_0(input logic clock, input logic reset, input logic i, output logic out);
reg [2:0]state = 3'b000; 
 reg [2:0]next = 3'b000; 
 parameter S0 = 3'b000; 
 parameter S1 = 3'b001;
 parameter S2 = 3'b011;
 parameter S3 = 3'b010;
parameter S4 = 3'b110; 
 always @ (state or i or reset) 
 case(state) 
  S0 : 
  if (reset == 1) 
 begin 
 next = S0; 
 end 
 else if(i == 1) 
 begin 
 next =  S3 ; 
 end 
 else if (i == 0) 
 begin 
 next =  S3 ; 
 end 
 
  S1 : 
  if (reset == 1) 
 begin 
 next = S0; 
 end 
 else if(i == 1) 
 begin 
 next =  S0 ; 
 end 
 else if (i == 0) 
 begin 
 next =  S4 ; 
 end 
 
  S2 : 
  if (reset == 1) 
 begin 
 next = S0; 
 end 
 else if(i == 1) 
 begin 
 next =  S3 ; 
 end 
 else if (i == 0) 
 begin 
 next =  S0 ; 
 end 
 
  S3 : 
  if (reset == 1) 
 begin 
 next = S0; 
 end 
 else if(i == 1) 
 begin 
 next =  S3 ; 
 end 
 else if (i == 0) 
 begin 
 next =  S3 ; 
 end 
  
   S4 : 
  if (reset == 1) 
 begin 
 next = S0; 
 end 
 else if(i == 1) 
 begin 
 next =  S4 ; 
 end 
 else if (i == 0) 
 begin 
 next =  S2 ; 
 end 
 
 endcase 
 
 always @ (posedge clock) 
 if (next == S4) 
 begin 
 $display("%b%b_%b%b", state, i, next, out); 
 state <= next; 
 out <=  "1"; 
 end 
 else 
 begin 
 $display("%b%b_%b%b", state, i, next, out); 
 state <= next; 
 out <= "0"; 
 end 

endmodule