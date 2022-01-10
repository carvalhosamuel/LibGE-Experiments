module individual_49(output logic q, input logic clk, rst, j, k);
  always @(posedge clk) begin
    if(rst == 0) begin
      q = 0;
    end
    else begin
      case({j,k})

2'b00: q = ~q;
2'b01: q = 0;
2'b10: q = 1;
2'b11: q = q;

      endcase
    end
  end
endmodule
