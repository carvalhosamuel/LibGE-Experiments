module individual_177(input wire clk, input wire rst, input wire j, input wire k, output reg q);
always @(posedge clk) begin
if(rst == 1) begin
q = 0;
end
else begin
case({j,k})
2'b00: q = ~q;
2'b01: q = ~q;
2'b10: q = q;
2'b11: q = ~q;
endcase
end
end
endmodule