// Include all individivuals
`include "tmp/individual_0.sv"
`include "tmp/individual_1.sv"
`include "tmp/individual_2.sv"
`include "tmp/individual_3.sv"
`include "tmp/individual_4.sv"
`include "tmp/individual_5.sv"
`include "tmp/individual_6.sv"
`include "tmp/individual_7.sv"
`include "tmp/individual_8.sv"
`include "tmp/individual_9.sv"
`include "tmp/individual_10.sv"
`include "tmp/individual_11.sv"
`include "tmp/individual_12.sv"
`include "tmp/individual_13.sv"
`include "tmp/individual_14.sv"
`include "tmp/individual_15.sv"
`include "tmp/individual_16.sv"
`include "tmp/individual_17.sv"
`include "tmp/individual_18.sv"
`include "tmp/individual_19.sv"
`include "tmp/individual_20.sv"
`include "tmp/individual_21.sv"
`include "tmp/individual_22.sv"
`include "tmp/individual_23.sv"
`include "tmp/individual_24.sv"
`include "tmp/individual_25.sv"
`include "tmp/individual_26.sv"
`include "tmp/individual_27.sv"
`include "tmp/individual_28.sv"
`include "tmp/individual_29.sv"
`include "tmp/individual_30.sv"
`include "tmp/individual_31.sv"
`include "tmp/individual_32.sv"
`include "tmp/individual_33.sv"
`include "tmp/individual_34.sv"
`include "tmp/individual_35.sv"
`include "tmp/individual_36.sv"
`include "tmp/individual_37.sv"
`include "tmp/individual_38.sv"
`include "tmp/individual_39.sv"
`include "tmp/individual_40.sv"
`include "tmp/individual_41.sv"
`include "tmp/individual_42.sv"
`include "tmp/individual_43.sv"
`include "tmp/individual_44.sv"
`include "tmp/individual_45.sv"
`include "tmp/individual_46.sv"
`include "tmp/individual_47.sv"
`include "tmp/individual_48.sv"
`include "tmp/individual_49.sv"
`include "tmp/individual_50.sv"
`include "tmp/individual_51.sv"
`include "tmp/individual_52.sv"
`include "tmp/individual_53.sv"
`include "tmp/individual_54.sv"
`include "tmp/individual_55.sv"
`include "tmp/individual_56.sv"
`include "tmp/individual_57.sv"
`include "tmp/individual_58.sv"
`include "tmp/individual_59.sv"
`include "tmp/individual_60.sv"
`include "tmp/individual_61.sv"
`include "tmp/individual_62.sv"
`include "tmp/individual_63.sv"
`include "tmp/individual_64.sv"
`include "tmp/individual_65.sv"
`include "tmp/individual_66.sv"
`include "tmp/individual_67.sv"
`include "tmp/individual_68.sv"
`include "tmp/individual_69.sv"
`include "tmp/individual_70.sv"
`include "tmp/individual_71.sv"
`include "tmp/individual_72.sv"
`include "tmp/individual_73.sv"
`include "tmp/individual_74.sv"
`include "tmp/individual_75.sv"
`include "tmp/individual_76.sv"
`include "tmp/individual_77.sv"
`include "tmp/individual_78.sv"
`include "tmp/individual_79.sv"
`include "tmp/individual_80.sv"
`include "tmp/individual_81.sv"
`include "tmp/individual_82.sv"
`include "tmp/individual_83.sv"
`include "tmp/individual_84.sv"
`include "tmp/individual_85.sv"
`include "tmp/individual_86.sv"
`include "tmp/individual_87.sv"
`include "tmp/individual_88.sv"
`include "tmp/individual_89.sv"
`include "tmp/individual_90.sv"
`include "tmp/individual_91.sv"
`include "tmp/individual_92.sv"
`include "tmp/individual_93.sv"
`include "tmp/individual_94.sv"
`include "tmp/individual_95.sv"
`include "tmp/individual_96.sv"
`include "tmp/individual_97.sv"
`include "tmp/individual_98.sv"
`include "tmp/individual_99.sv"
`include "tmp/individual_100.sv"
`include "tmp/individual_101.sv"
`include "tmp/individual_102.sv"
`include "tmp/individual_103.sv"
`include "tmp/individual_104.sv"
`include "tmp/individual_105.sv"
`include "tmp/individual_106.sv"
`include "tmp/individual_107.sv"
`include "tmp/individual_108.sv"
`include "tmp/individual_109.sv"
`include "tmp/individual_110.sv"
`include "tmp/individual_111.sv"
`include "tmp/individual_112.sv"
`include "tmp/individual_113.sv"
`include "tmp/individual_114.sv"
`include "tmp/individual_115.sv"
`include "tmp/individual_116.sv"
`include "tmp/individual_117.sv"
`include "tmp/individual_118.sv"
`include "tmp/individual_119.sv"
`include "tmp/individual_120.sv"
`include "tmp/individual_121.sv"
`include "tmp/individual_122.sv"
`include "tmp/individual_123.sv"
`include "tmp/individual_124.sv"
`include "tmp/individual_125.sv"
`include "tmp/individual_126.sv"
`include "tmp/individual_127.sv"
`include "tmp/individual_128.sv"
`include "tmp/individual_129.sv"
`include "tmp/individual_130.sv"
`include "tmp/individual_131.sv"
`include "tmp/individual_132.sv"
`include "tmp/individual_133.sv"
`include "tmp/individual_134.sv"
`include "tmp/individual_135.sv"
`include "tmp/individual_136.sv"
`include "tmp/individual_137.sv"
`include "tmp/individual_138.sv"
`include "tmp/individual_139.sv"
`include "tmp/individual_140.sv"
`include "tmp/individual_141.sv"
`include "tmp/individual_142.sv"
`include "tmp/individual_143.sv"
`include "tmp/individual_144.sv"
`include "tmp/individual_145.sv"
`include "tmp/individual_146.sv"
`include "tmp/individual_147.sv"
`include "tmp/individual_148.sv"
`include "tmp/individual_149.sv"

// Definitions
`define POPULATION_SIZE 150
`define TEST_COUNT 2
`define PERIOD 10

// Use parameter to pass population size to testbench
module testbench();
  // Use integer array to store fitness for all individuals
  integer fitness[`POPULATION_SIZE];

  // Define inputs and outputs to connect to the individuals
  reg clk;
  reg rst;
  reg [15:0] y3_current[`POPULATION_SIZE];
  reg [15:0] y3_expected;
  reg [15:0] y2_current[`POPULATION_SIZE];
  reg [15:0] y2_expected;
  reg [15:0] y1_current[`POPULATION_SIZE];
  reg [15:0] y1_expected;
  reg [15:0] y0_current[`POPULATION_SIZE];
  reg [15:0] y0_expected;

	reg [15:0] a1;
	reg [15:0] a0;
	reg [15:0] b1;
	reg [15:0] b0;

	// Array of testvectors to store expected values
	reg [127:0] testvectors[0:(`TEST_COUNT-1)];
	integer vectornum = 0;

	// Instantiate all the individuals
  individual_0 dut_0(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[0]), .y2(y2_current[0]), .y1(y1_current[0]), .y0(y0_current[0]));
  individual_1 dut_1(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[1]), .y2(y2_current[1]), .y1(y1_current[1]), .y0(y0_current[1]));
  individual_2 dut_2(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[2]), .y2(y2_current[2]), .y1(y1_current[2]), .y0(y0_current[2]));
  individual_3 dut_3(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[3]), .y2(y2_current[3]), .y1(y1_current[3]), .y0(y0_current[3]));
  individual_4 dut_4(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[4]), .y2(y2_current[4]), .y1(y1_current[4]), .y0(y0_current[4]));
  individual_5 dut_5(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[5]), .y2(y2_current[5]), .y1(y1_current[5]), .y0(y0_current[5]));
  individual_6 dut_6(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[6]), .y2(y2_current[6]), .y1(y1_current[6]), .y0(y0_current[6]));
  individual_7 dut_7(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[7]), .y2(y2_current[7]), .y1(y1_current[7]), .y0(y0_current[7]));
  individual_8 dut_8(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[8]), .y2(y2_current[8]), .y1(y1_current[8]), .y0(y0_current[8]));
  individual_9 dut_9(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[9]), .y2(y2_current[9]), .y1(y1_current[9]), .y0(y0_current[9]));
  individual_10 dut_10(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[10]), .y2(y2_current[10]), .y1(y1_current[10]), .y0(y0_current[10]));
  individual_11 dut_11(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[11]), .y2(y2_current[11]), .y1(y1_current[11]), .y0(y0_current[11]));
  individual_12 dut_12(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[12]), .y2(y2_current[12]), .y1(y1_current[12]), .y0(y0_current[12]));
  individual_13 dut_13(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[13]), .y2(y2_current[13]), .y1(y1_current[13]), .y0(y0_current[13]));
  individual_14 dut_14(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[14]), .y2(y2_current[14]), .y1(y1_current[14]), .y0(y0_current[14]));
  individual_15 dut_15(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[15]), .y2(y2_current[15]), .y1(y1_current[15]), .y0(y0_current[15]));
  individual_16 dut_16(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[16]), .y2(y2_current[16]), .y1(y1_current[16]), .y0(y0_current[16]));
  individual_17 dut_17(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[17]), .y2(y2_current[17]), .y1(y1_current[17]), .y0(y0_current[17]));
  individual_18 dut_18(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[18]), .y2(y2_current[18]), .y1(y1_current[18]), .y0(y0_current[18]));
  individual_19 dut_19(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[19]), .y2(y2_current[19]), .y1(y1_current[19]), .y0(y0_current[19]));
  individual_20 dut_20(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[20]), .y2(y2_current[20]), .y1(y1_current[20]), .y0(y0_current[20]));
  individual_21 dut_21(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[21]), .y2(y2_current[21]), .y1(y1_current[21]), .y0(y0_current[21]));
  individual_22 dut_22(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[22]), .y2(y2_current[22]), .y1(y1_current[22]), .y0(y0_current[22]));
  individual_23 dut_23(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[23]), .y2(y2_current[23]), .y1(y1_current[23]), .y0(y0_current[23]));
  individual_24 dut_24(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[24]), .y2(y2_current[24]), .y1(y1_current[24]), .y0(y0_current[24]));
  individual_25 dut_25(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[25]), .y2(y2_current[25]), .y1(y1_current[25]), .y0(y0_current[25]));
  individual_26 dut_26(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[26]), .y2(y2_current[26]), .y1(y1_current[26]), .y0(y0_current[26]));
  individual_27 dut_27(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[27]), .y2(y2_current[27]), .y1(y1_current[27]), .y0(y0_current[27]));
  individual_28 dut_28(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[28]), .y2(y2_current[28]), .y1(y1_current[28]), .y0(y0_current[28]));
  individual_29 dut_29(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[29]), .y2(y2_current[29]), .y1(y1_current[29]), .y0(y0_current[29]));
  individual_30 dut_30(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[30]), .y2(y2_current[30]), .y1(y1_current[30]), .y0(y0_current[30]));
  individual_31 dut_31(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[31]), .y2(y2_current[31]), .y1(y1_current[31]), .y0(y0_current[31]));
  individual_32 dut_32(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[32]), .y2(y2_current[32]), .y1(y1_current[32]), .y0(y0_current[32]));
  individual_33 dut_33(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[33]), .y2(y2_current[33]), .y1(y1_current[33]), .y0(y0_current[33]));
  individual_34 dut_34(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[34]), .y2(y2_current[34]), .y1(y1_current[34]), .y0(y0_current[34]));
  individual_35 dut_35(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[35]), .y2(y2_current[35]), .y1(y1_current[35]), .y0(y0_current[35]));
  individual_36 dut_36(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[36]), .y2(y2_current[36]), .y1(y1_current[36]), .y0(y0_current[36]));
  individual_37 dut_37(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[37]), .y2(y2_current[37]), .y1(y1_current[37]), .y0(y0_current[37]));
  individual_38 dut_38(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[38]), .y2(y2_current[38]), .y1(y1_current[38]), .y0(y0_current[38]));
  individual_39 dut_39(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[39]), .y2(y2_current[39]), .y1(y1_current[39]), .y0(y0_current[39]));
  individual_40 dut_40(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[40]), .y2(y2_current[40]), .y1(y1_current[40]), .y0(y0_current[40]));
  individual_41 dut_41(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[41]), .y2(y2_current[41]), .y1(y1_current[41]), .y0(y0_current[41]));
  individual_42 dut_42(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[42]), .y2(y2_current[42]), .y1(y1_current[42]), .y0(y0_current[42]));
  individual_43 dut_43(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[43]), .y2(y2_current[43]), .y1(y1_current[43]), .y0(y0_current[43]));
  individual_44 dut_44(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[44]), .y2(y2_current[44]), .y1(y1_current[44]), .y0(y0_current[44]));
  individual_45 dut_45(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[45]), .y2(y2_current[45]), .y1(y1_current[45]), .y0(y0_current[45]));
  individual_46 dut_46(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[46]), .y2(y2_current[46]), .y1(y1_current[46]), .y0(y0_current[46]));
  individual_47 dut_47(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[47]), .y2(y2_current[47]), .y1(y1_current[47]), .y0(y0_current[47]));
  individual_48 dut_48(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[48]), .y2(y2_current[48]), .y1(y1_current[48]), .y0(y0_current[48]));
  individual_49 dut_49(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[49]), .y2(y2_current[49]), .y1(y1_current[49]), .y0(y0_current[49]));
  individual_50 dut_50(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[50]), .y2(y2_current[50]), .y1(y1_current[50]), .y0(y0_current[50]));
  individual_51 dut_51(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[51]), .y2(y2_current[51]), .y1(y1_current[51]), .y0(y0_current[51]));
  individual_52 dut_52(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[52]), .y2(y2_current[52]), .y1(y1_current[52]), .y0(y0_current[52]));
  individual_53 dut_53(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[53]), .y2(y2_current[53]), .y1(y1_current[53]), .y0(y0_current[53]));
  individual_54 dut_54(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[54]), .y2(y2_current[54]), .y1(y1_current[54]), .y0(y0_current[54]));
  individual_55 dut_55(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[55]), .y2(y2_current[55]), .y1(y1_current[55]), .y0(y0_current[55]));
  individual_56 dut_56(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[56]), .y2(y2_current[56]), .y1(y1_current[56]), .y0(y0_current[56]));
  individual_57 dut_57(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[57]), .y2(y2_current[57]), .y1(y1_current[57]), .y0(y0_current[57]));
  individual_58 dut_58(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[58]), .y2(y2_current[58]), .y1(y1_current[58]), .y0(y0_current[58]));
  individual_59 dut_59(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[59]), .y2(y2_current[59]), .y1(y1_current[59]), .y0(y0_current[59]));
  individual_60 dut_60(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[60]), .y2(y2_current[60]), .y1(y1_current[60]), .y0(y0_current[60]));
  individual_61 dut_61(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[61]), .y2(y2_current[61]), .y1(y1_current[61]), .y0(y0_current[61]));
  individual_62 dut_62(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[62]), .y2(y2_current[62]), .y1(y1_current[62]), .y0(y0_current[62]));
  individual_63 dut_63(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[63]), .y2(y2_current[63]), .y1(y1_current[63]), .y0(y0_current[63]));
  individual_64 dut_64(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[64]), .y2(y2_current[64]), .y1(y1_current[64]), .y0(y0_current[64]));
  individual_65 dut_65(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[65]), .y2(y2_current[65]), .y1(y1_current[65]), .y0(y0_current[65]));
  individual_66 dut_66(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[66]), .y2(y2_current[66]), .y1(y1_current[66]), .y0(y0_current[66]));
  individual_67 dut_67(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[67]), .y2(y2_current[67]), .y1(y1_current[67]), .y0(y0_current[67]));
  individual_68 dut_68(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[68]), .y2(y2_current[68]), .y1(y1_current[68]), .y0(y0_current[68]));
  individual_69 dut_69(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[69]), .y2(y2_current[69]), .y1(y1_current[69]), .y0(y0_current[69]));
  individual_70 dut_70(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[70]), .y2(y2_current[70]), .y1(y1_current[70]), .y0(y0_current[70]));
  individual_71 dut_71(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[71]), .y2(y2_current[71]), .y1(y1_current[71]), .y0(y0_current[71]));
  individual_72 dut_72(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[72]), .y2(y2_current[72]), .y1(y1_current[72]), .y0(y0_current[72]));
  individual_73 dut_73(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[73]), .y2(y2_current[73]), .y1(y1_current[73]), .y0(y0_current[73]));
  individual_74 dut_74(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[74]), .y2(y2_current[74]), .y1(y1_current[74]), .y0(y0_current[74]));
  individual_75 dut_75(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[75]), .y2(y2_current[75]), .y1(y1_current[75]), .y0(y0_current[75]));
  individual_76 dut_76(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[76]), .y2(y2_current[76]), .y1(y1_current[76]), .y0(y0_current[76]));
  individual_77 dut_77(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[77]), .y2(y2_current[77]), .y1(y1_current[77]), .y0(y0_current[77]));
  individual_78 dut_78(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[78]), .y2(y2_current[78]), .y1(y1_current[78]), .y0(y0_current[78]));
  individual_79 dut_79(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[79]), .y2(y2_current[79]), .y1(y1_current[79]), .y0(y0_current[79]));
  individual_80 dut_80(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[80]), .y2(y2_current[80]), .y1(y1_current[80]), .y0(y0_current[80]));
  individual_81 dut_81(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[81]), .y2(y2_current[81]), .y1(y1_current[81]), .y0(y0_current[81]));
  individual_82 dut_82(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[82]), .y2(y2_current[82]), .y1(y1_current[82]), .y0(y0_current[82]));
  individual_83 dut_83(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[83]), .y2(y2_current[83]), .y1(y1_current[83]), .y0(y0_current[83]));
  individual_84 dut_84(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[84]), .y2(y2_current[84]), .y1(y1_current[84]), .y0(y0_current[84]));
  individual_85 dut_85(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[85]), .y2(y2_current[85]), .y1(y1_current[85]), .y0(y0_current[85]));
  individual_86 dut_86(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[86]), .y2(y2_current[86]), .y1(y1_current[86]), .y0(y0_current[86]));
  individual_87 dut_87(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[87]), .y2(y2_current[87]), .y1(y1_current[87]), .y0(y0_current[87]));
  individual_88 dut_88(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[88]), .y2(y2_current[88]), .y1(y1_current[88]), .y0(y0_current[88]));
  individual_89 dut_89(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[89]), .y2(y2_current[89]), .y1(y1_current[89]), .y0(y0_current[89]));
  individual_90 dut_90(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[90]), .y2(y2_current[90]), .y1(y1_current[90]), .y0(y0_current[90]));
  individual_91 dut_91(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[91]), .y2(y2_current[91]), .y1(y1_current[91]), .y0(y0_current[91]));
  individual_92 dut_92(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[92]), .y2(y2_current[92]), .y1(y1_current[92]), .y0(y0_current[92]));
  individual_93 dut_93(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[93]), .y2(y2_current[93]), .y1(y1_current[93]), .y0(y0_current[93]));
  individual_94 dut_94(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[94]), .y2(y2_current[94]), .y1(y1_current[94]), .y0(y0_current[94]));
  individual_95 dut_95(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[95]), .y2(y2_current[95]), .y1(y1_current[95]), .y0(y0_current[95]));
  individual_96 dut_96(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[96]), .y2(y2_current[96]), .y1(y1_current[96]), .y0(y0_current[96]));
  individual_97 dut_97(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[97]), .y2(y2_current[97]), .y1(y1_current[97]), .y0(y0_current[97]));
  individual_98 dut_98(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[98]), .y2(y2_current[98]), .y1(y1_current[98]), .y0(y0_current[98]));
  individual_99 dut_99(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[99]), .y2(y2_current[99]), .y1(y1_current[99]), .y0(y0_current[99]));
  individual_100 dut_100(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[100]), .y2(y2_current[100]), .y1(y1_current[100]), .y0(y0_current[100]));
  individual_101 dut_101(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[101]), .y2(y2_current[101]), .y1(y1_current[101]), .y0(y0_current[101]));
  individual_102 dut_102(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[102]), .y2(y2_current[102]), .y1(y1_current[102]), .y0(y0_current[102]));
  individual_103 dut_103(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[103]), .y2(y2_current[103]), .y1(y1_current[103]), .y0(y0_current[103]));
  individual_104 dut_104(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[104]), .y2(y2_current[104]), .y1(y1_current[104]), .y0(y0_current[104]));
  individual_105 dut_105(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[105]), .y2(y2_current[105]), .y1(y1_current[105]), .y0(y0_current[105]));
  individual_106 dut_106(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[106]), .y2(y2_current[106]), .y1(y1_current[106]), .y0(y0_current[106]));
  individual_107 dut_107(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[107]), .y2(y2_current[107]), .y1(y1_current[107]), .y0(y0_current[107]));
  individual_108 dut_108(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[108]), .y2(y2_current[108]), .y1(y1_current[108]), .y0(y0_current[108]));
  individual_109 dut_109(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[109]), .y2(y2_current[109]), .y1(y1_current[109]), .y0(y0_current[109]));
  individual_110 dut_110(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[110]), .y2(y2_current[110]), .y1(y1_current[110]), .y0(y0_current[110]));
  individual_111 dut_111(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[111]), .y2(y2_current[111]), .y1(y1_current[111]), .y0(y0_current[111]));
  individual_112 dut_112(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[112]), .y2(y2_current[112]), .y1(y1_current[112]), .y0(y0_current[112]));
  individual_113 dut_113(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[113]), .y2(y2_current[113]), .y1(y1_current[113]), .y0(y0_current[113]));
  individual_114 dut_114(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[114]), .y2(y2_current[114]), .y1(y1_current[114]), .y0(y0_current[114]));
  individual_115 dut_115(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[115]), .y2(y2_current[115]), .y1(y1_current[115]), .y0(y0_current[115]));
  individual_116 dut_116(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[116]), .y2(y2_current[116]), .y1(y1_current[116]), .y0(y0_current[116]));
  individual_117 dut_117(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[117]), .y2(y2_current[117]), .y1(y1_current[117]), .y0(y0_current[117]));
  individual_118 dut_118(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[118]), .y2(y2_current[118]), .y1(y1_current[118]), .y0(y0_current[118]));
  individual_119 dut_119(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[119]), .y2(y2_current[119]), .y1(y1_current[119]), .y0(y0_current[119]));
  individual_120 dut_120(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[120]), .y2(y2_current[120]), .y1(y1_current[120]), .y0(y0_current[120]));
  individual_121 dut_121(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[121]), .y2(y2_current[121]), .y1(y1_current[121]), .y0(y0_current[121]));
  individual_122 dut_122(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[122]), .y2(y2_current[122]), .y1(y1_current[122]), .y0(y0_current[122]));
  individual_123 dut_123(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[123]), .y2(y2_current[123]), .y1(y1_current[123]), .y0(y0_current[123]));
  individual_124 dut_124(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[124]), .y2(y2_current[124]), .y1(y1_current[124]), .y0(y0_current[124]));
  individual_125 dut_125(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[125]), .y2(y2_current[125]), .y1(y1_current[125]), .y0(y0_current[125]));
  individual_126 dut_126(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[126]), .y2(y2_current[126]), .y1(y1_current[126]), .y0(y0_current[126]));
  individual_127 dut_127(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[127]), .y2(y2_current[127]), .y1(y1_current[127]), .y0(y0_current[127]));
  individual_128 dut_128(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[128]), .y2(y2_current[128]), .y1(y1_current[128]), .y0(y0_current[128]));
  individual_129 dut_129(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[129]), .y2(y2_current[129]), .y1(y1_current[129]), .y0(y0_current[129]));
  individual_130 dut_130(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[130]), .y2(y2_current[130]), .y1(y1_current[130]), .y0(y0_current[130]));
  individual_131 dut_131(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[131]), .y2(y2_current[131]), .y1(y1_current[131]), .y0(y0_current[131]));
  individual_132 dut_132(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[132]), .y2(y2_current[132]), .y1(y1_current[132]), .y0(y0_current[132]));
  individual_133 dut_133(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[133]), .y2(y2_current[133]), .y1(y1_current[133]), .y0(y0_current[133]));
  individual_134 dut_134(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[134]), .y2(y2_current[134]), .y1(y1_current[134]), .y0(y0_current[134]));
  individual_135 dut_135(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[135]), .y2(y2_current[135]), .y1(y1_current[135]), .y0(y0_current[135]));
  individual_136 dut_136(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[136]), .y2(y2_current[136]), .y1(y1_current[136]), .y0(y0_current[136]));
  individual_137 dut_137(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[137]), .y2(y2_current[137]), .y1(y1_current[137]), .y0(y0_current[137]));
  individual_138 dut_138(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[138]), .y2(y2_current[138]), .y1(y1_current[138]), .y0(y0_current[138]));
  individual_139 dut_139(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[139]), .y2(y2_current[139]), .y1(y1_current[139]), .y0(y0_current[139]));
  individual_140 dut_140(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[140]), .y2(y2_current[140]), .y1(y1_current[140]), .y0(y0_current[140]));
  individual_141 dut_141(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[141]), .y2(y2_current[141]), .y1(y1_current[141]), .y0(y0_current[141]));
  individual_142 dut_142(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[142]), .y2(y2_current[142]), .y1(y1_current[142]), .y0(y0_current[142]));
  individual_143 dut_143(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[143]), .y2(y2_current[143]), .y1(y1_current[143]), .y0(y0_current[143]));
  individual_144 dut_144(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[144]), .y2(y2_current[144]), .y1(y1_current[144]), .y0(y0_current[144]));
  individual_145 dut_145(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[145]), .y2(y2_current[145]), .y1(y1_current[145]), .y0(y0_current[145]));
  individual_146 dut_146(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[146]), .y2(y2_current[146]), .y1(y1_current[146]), .y0(y0_current[146]));
  individual_147 dut_147(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[147]), .y2(y2_current[147]), .y1(y1_current[147]), .y0(y0_current[147]));
  individual_148 dut_148(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[148]), .y2(y2_current[148]), .y1(y1_current[148]), .y0(y0_current[148]));
  individual_149 dut_149(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[149]), .y2(y2_current[149]), .y1(y1_current[149]), .y0(y0_current[149]));

	// Create task to evaluate each testcase
	// Note that this evaluates the entire population for this testcase
	task testcase;
		input [15:0] a1_value;
input [15:0] a0_value;
input [15:0] b1_value;
input [15:0] b0_value;
input [15:0] y3_value;
input [15:0] y2_value;
input [15:0] y1_value;
input [15:0] y0_value;


		// Initialise inputs
		a1=a1_value;
		a0=a0_value;
		b1=b1_value;
		b0=b0_value;

		for(int i = 0; i < `POPULATION_SIZE; i++) begin
 // calculate hamming distance
 fitness[i]  = $countones(~(y3_current[i]  ^ y3_value)) + $countones(~(y2_current[i]  ^ y2_value)) + $countones(~(y1_current[i]  ^ y1_value)) + $countones(~(y0_current[i]  ^ y0_value));

		end
	endtask

	// We want to change our inputs on negedge so that we can run testcases at posedge
	always @(posedge clk) begin
		if (rst == 0) begin
			{a1, a0, b1, b0, y3_expected, y2_expected, y1_expected, y0_expected} = testvectors[vectornum];
			vectornum = vectornum + 1;
		end

	end

	always @(posedge clk) begin
		if (rst == 0) begin
			testcase(a1, a0, b1, b0, y3_expected, y2_expected, y1_expected, y0_expected);
		end

	end

  // We use a clock to load in our testvectors
  always begin
    #(`PERIOD/2) clk = ~clk;
  end

  // Run simulation
  initial begin
    // Set the clock high so we get posedges at 10,20,30 etc.
    //clk = 1;
    clk = 1; rst = 1;
    #(`PERIOD) rst = 0;

    // DEBUGGING - Dump to vcd file
    //$dumpfile("testbench_values.vcd");
    //$dumpvars(0,fulladder_tb);

    // Read in test vectors
    $readmemb("template/test_vectors.tv", testvectors);
    // test vectors
    $writememb("tmp/memory_b.txt",testvectors);
	
    // Set all scores to zero
    for(int i = 0; i < `POPULATION_SIZE; i++) begin
      fitness[i] = 0;
    end
     
    // Wait clock cycles for test to complete
    #(`PERIOD*`TEST_COUNT);
    
    // Print all fitness scores to the console
    for(int i = 0; i < `POPULATION_SIZE; i++) begin
      $display("%0d",fitness[i]);
    end

    $finish;
  end
 endmodule
