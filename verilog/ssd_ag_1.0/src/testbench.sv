`include "tmp/individual.sv"
module testbench();
    logic [3:0] bcd;
    logic [6:0] seg;

    // design unit under test instantiation
    ssd dut(.bcd(bcd), .seg(seg));

    int number_correct = 0;

    initial begin
        // Test bcd code 0
        bcd = 4'h0;
        #10 // Allow for circuit to settle
        if(seg == 7'b1111110) begin
            number_correct++;
        end

        // Test bcd code 1
        bcd = 4'h1;
        #10 // Allow for circuit to settle
        if(seg == 7'b0110000) begin
            number_correct++;
        end

        // Test bcd code 2
        bcd = 4'h2;
        #10 // Allow for circuit to settle
        if(seg == 7'b1101101) begin
            number_correct++;
        end

        // Test bcd code 3
        bcd = 4'h3;
        #10 // Allow for circuit to settle
        if(seg == 7'b1111001) begin
            number_correct++;
        end

        // Test bcd code 4
        bcd = 4'h4;
        #10 // Allow for circuit to settle
        if(seg == 7'b0110011) begin
            number_correct++;
        end

        // Test bcd code 5
        bcd = 4'h5;
        #10 // Allow for circuit to settle
        if(seg == 7'b1011011) begin
            number_correct++;
        end

        // Test bcd code 6
        bcd = 4'h6;
        #10 // Allow for circuit to settle
        if(seg == 7'b1011111) begin
            number_correct++;
        end

        // Test bcd code 7
        bcd = 4'h7;
        #10 // Allow for circuit to settle
        if(seg == 7'b1110000) begin
            number_correct++;
        end

        // Test bcd code 8
        bcd = 4'h8;
        #10 // Allow for circuit to settle
        if(seg == 7'b1111111) begin
            number_correct++;
        end

        // Test bcd code 1
        bcd = 4'h9;
        #10 // Allow for circuit to settle
        if(seg == 7'b1111011) begin
            number_correct++;
        end

        // Display result
        $display("%0d", number_correct);
    end
endmodule
