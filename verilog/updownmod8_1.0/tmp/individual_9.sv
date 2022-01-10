module individual_9(input wire clk, input wire rst, input wire sel, output reg [2:0] q);
always @(posedge clk) begin
if(rst == 1) begin
q = 3'b000;
end
else begin
case(sel)
1'b0: q = q+1;
1'b1: q = q+1;
endcase
end
end
endmodule