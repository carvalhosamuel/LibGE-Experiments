(output logic q, input logic clk, rst, j, k);
  always @(posedge clk) begin
    if(rst == 0) begin
      q = 0;
    end
    else begin
      case({j,k})
