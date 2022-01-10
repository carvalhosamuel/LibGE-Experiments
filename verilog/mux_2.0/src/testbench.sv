`include "tmp/individual.sv"
module testbench();
    logic [7:0] in;
    logic [2:0] select;
    logic out;

    // design unit under test instantiation
    mux dut(.out(out), .a0(select[0]), .a1(select[1]), .a2(select[2]), .d0(in[0]), .d1(in[1]), .d2(in[2]), .d3(in[3]), .d4(in[4]), .d5(in[5]), .d6(in[6]), .d7(in[7]));

    int low,high = 0;
    int number_correct = 0;

    initial begin
        // Test bit 0
        in = 8'b00000001; select = 3'b000;
        #10 // Allow for circuit to settle
        if(out == 1'b1) begin
            low = 1;
        end else begin
            low = 0;
        end
        in = 8'b11111110;
        #10 // Allow for circuit to settle
        if(out == 1'b0) begin
            high = 1;
        end else begin
            high = 0;
        end
        if(low == 1 && high == 1) begin
            number_correct++;
        end 

        // Test bit 1
        in = 8'b00000010; select = 3'b001; low = 0; high = 0;
        #10 // Allow for circuit to settle
        if(out == 1'b1) begin
            low = 1;
        end else begin
            low = 0;
        end
        in = 8'b11111101;
        #10 // Allow for circuit to settle
        if(out == 1'b0) begin
            high = 1;
        end else begin
            high = 0;
        end
        if(low == 1 && high == 1) begin
            number_correct++;
        end 

        // Test bit 2
        in = 8'b00000100; select = 3'b010; low = 0; high = 0;
        #10 // Allow for circuit to settle
        if(out == 1'b1) begin
            low = 1;
        end else begin
            low = 0;
        end
        in = 8'b11111011;
        #10 // Allow for circuit to settle
        if(out == 1'b0) begin
            high = 1;
        end else begin
            high = 0;
        end
        if(low == 1 && high == 1) begin
            number_correct++;
        end 

        // Test bit 3
        in = 8'b00001000; select = 3'b011; low = 0; high = 0;
        #10 // Allow for circuit to settle
        if(out == 1'b1) begin
            low = 1;
        end else begin
            low = 0;
        end
        in = 8'b11110111;
        #10 // Allow for circuit to settle
        if(out == 1'b0) begin
            high = 1;
        end else begin
            high = 0;
        end
        if(low == 1 && high == 1) begin
            number_correct++;
        end 

        // Test bit 4
        in = 8'b00010000; select = 3'b100; low = 0; high = 0;
        #10 // Allow for circuit to settle
        if(out == 1'b1) begin
            low = 1;
        end else begin
            low = 0;
        end
        in = 8'b11101111;
        #10 // Allow for circuit to settle
        if(out == 1'b0) begin
            high = 1;
        end else begin
            high = 0;
        end
        if(low == 1 && high == 1) begin
            number_correct++;
        end 

        // Test bit 5
        in = 8'b00100000; select = 3'b101; low = 0; high = 0;
        #10 // Allow for circuit to settle
        if(out == 1'b1) begin
            low = 1;
        end else begin
            low = 0;
        end
        in = 8'b11011111;
        #10 // Allow for circuit to settle
        if(out == 1'b0) begin
            high = 1;
        end else begin
            high = 0;
        end
        if(low == 1 && high == 1) begin
            number_correct++;
        end 

        // Test bit 6
        in = 8'b01000000; select = 3'b110; low = 0; high = 0;
        #10 // Allow for circuit to settle
        if(out == 1'b1) begin
            low = 1;
        end else begin
            low = 0;
        end
        in = 8'b10111111;
        #10 // Allow for circuit to settle
        if(out == 1'b0) begin
            high = 1;
        end else begin
            high = 0;
        end
        if(low == 1 && high == 1) begin
            number_correct++;
        end 

        // Test bit 7
        in = 8'b10000000; select = 3'b111; low = 0; high = 0;
        #10 // Allow for circuit to settle
        if(out == 1'b1) begin
            low = 1;
        end else begin
            low = 0;
        end
        in = 8'b01111111;
        #10 // Allow for circuit to settle
        if(out == 1'b0) begin
            high = 1;
        end else begin
            high = 0;
        end
        if(low == 1 && high == 1) begin
            number_correct++;
        end 

        // Display result
        $display("%0d", number_correct);
    end
endmodule
