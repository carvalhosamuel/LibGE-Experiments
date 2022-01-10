// Include all individivuals
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
`include "tmp/individual_150.sv"
`include "tmp/individual_151.sv"
`include "tmp/individual_152.sv"
`include "tmp/individual_153.sv"
`include "tmp/individual_154.sv"
`include "tmp/individual_155.sv"
`include "tmp/individual_156.sv"
`include "tmp/individual_157.sv"
`include "tmp/individual_158.sv"
`include "tmp/individual_159.sv"
`include "tmp/individual_160.sv"
`include "tmp/individual_161.sv"
`include "tmp/individual_162.sv"
`include "tmp/individual_163.sv"
`include "tmp/individual_164.sv"
`include "tmp/individual_165.sv"
`include "tmp/individual_166.sv"
`include "tmp/individual_167.sv"
`include "tmp/individual_168.sv"
`include "tmp/individual_169.sv"
`include "tmp/individual_170.sv"
`include "tmp/individual_171.sv"
`include "tmp/individual_172.sv"
`include "tmp/individual_173.sv"
`include "tmp/individual_174.sv"
`include "tmp/individual_175.sv"
`include "tmp/individual_176.sv"
`include "tmp/individual_177.sv"
`include "tmp/individual_178.sv"
`include "tmp/individual_179.sv"
`include "tmp/individual_180.sv"
`include "tmp/individual_181.sv"
`include "tmp/individual_182.sv"
`include "tmp/individual_183.sv"
`include "tmp/individual_184.sv"
`include "tmp/individual_185.sv"
`include "tmp/individual_186.sv"
`include "tmp/individual_187.sv"
`include "tmp/individual_188.sv"
`include "tmp/individual_189.sv"
`include "tmp/individual_190.sv"
`include "tmp/individual_191.sv"
`include "tmp/individual_192.sv"
`include "tmp/individual_193.sv"
`include "tmp/individual_194.sv"
`include "tmp/individual_195.sv"
`include "tmp/individual_196.sv"
`include "tmp/individual_197.sv"
`include "tmp/individual_198.sv"
`include "tmp/individual_199.sv"

// Definitions
`define POPULATION_SIZE 200
`define TEST_COUNT 9
`define PERIOD 10

// Use parameter to pass population size to testbench
module testbench();
  // Use integer array to store fitness for all individuals
  integer fitness[`POPULATION_SIZE];

  // Define inputs and outputs to connect to the individuals
  reg clk;
  reg rst;
	reg j;
	reg k;
	reg q_expected;
	wire q_current[`POPULATION_SIZE];

	// Array of testvectors to store expected values
	reg [4:0] testvectors[0:(`TEST_COUNT-1)];
	integer vectornum = 0;

	// Instantiate all the individuals
  individual_100 dut_100(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[100]));
  individual_101 dut_101(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[101]));
  individual_102 dut_102(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[102]));
  individual_103 dut_103(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[103]));
  individual_104 dut_104(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[104]));
  individual_105 dut_105(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[105]));
  individual_106 dut_106(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[106]));
  individual_107 dut_107(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[107]));
  individual_108 dut_108(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[108]));
  individual_109 dut_109(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[109]));
  individual_110 dut_110(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[110]));
  individual_111 dut_111(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[111]));
  individual_112 dut_112(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[112]));
  individual_113 dut_113(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[113]));
  individual_114 dut_114(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[114]));
  individual_115 dut_115(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[115]));
  individual_116 dut_116(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[116]));
  individual_117 dut_117(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[117]));
  individual_118 dut_118(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[118]));
  individual_119 dut_119(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[119]));
  individual_120 dut_120(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[120]));
  individual_121 dut_121(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[121]));
  individual_122 dut_122(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[122]));
  individual_123 dut_123(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[123]));
  individual_124 dut_124(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[124]));
  individual_125 dut_125(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[125]));
  individual_126 dut_126(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[126]));
  individual_127 dut_127(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[127]));
  individual_128 dut_128(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[128]));
  individual_129 dut_129(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[129]));
  individual_130 dut_130(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[130]));
  individual_131 dut_131(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[131]));
  individual_132 dut_132(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[132]));
  individual_133 dut_133(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[133]));
  individual_134 dut_134(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[134]));
  individual_135 dut_135(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[135]));
  individual_136 dut_136(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[136]));
  individual_137 dut_137(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[137]));
  individual_138 dut_138(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[138]));
  individual_139 dut_139(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[139]));
  individual_140 dut_140(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[140]));
  individual_141 dut_141(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[141]));
  individual_142 dut_142(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[142]));
  individual_143 dut_143(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[143]));
  individual_144 dut_144(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[144]));
  individual_145 dut_145(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[145]));
  individual_146 dut_146(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[146]));
  individual_147 dut_147(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[147]));
  individual_148 dut_148(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[148]));
  individual_149 dut_149(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[149]));
  individual_150 dut_150(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[150]));
  individual_151 dut_151(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[151]));
  individual_152 dut_152(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[152]));
  individual_153 dut_153(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[153]));
  individual_154 dut_154(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[154]));
  individual_155 dut_155(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[155]));
  individual_156 dut_156(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[156]));
  individual_157 dut_157(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[157]));
  individual_158 dut_158(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[158]));
  individual_159 dut_159(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[159]));
  individual_160 dut_160(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[160]));
  individual_161 dut_161(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[161]));
  individual_162 dut_162(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[162]));
  individual_163 dut_163(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[163]));
  individual_164 dut_164(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[164]));
  individual_165 dut_165(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[165]));
  individual_166 dut_166(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[166]));
  individual_167 dut_167(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[167]));
  individual_168 dut_168(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[168]));
  individual_169 dut_169(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[169]));
  individual_170 dut_170(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[170]));
  individual_171 dut_171(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[171]));
  individual_172 dut_172(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[172]));
  individual_173 dut_173(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[173]));
  individual_174 dut_174(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[174]));
  individual_175 dut_175(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[175]));
  individual_176 dut_176(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[176]));
  individual_177 dut_177(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[177]));
  individual_178 dut_178(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[178]));
  individual_179 dut_179(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[179]));
  individual_180 dut_180(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[180]));
  individual_181 dut_181(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[181]));
  individual_182 dut_182(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[182]));
  individual_183 dut_183(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[183]));
  individual_184 dut_184(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[184]));
  individual_185 dut_185(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[185]));
  individual_186 dut_186(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[186]));
  individual_187 dut_187(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[187]));
  individual_188 dut_188(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[188]));
  individual_189 dut_189(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[189]));
  individual_190 dut_190(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[190]));
  individual_191 dut_191(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[191]));
  individual_192 dut_192(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[192]));
  individual_193 dut_193(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[193]));
  individual_194 dut_194(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[194]));
  individual_195 dut_195(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[195]));
  individual_196 dut_196(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[196]));
  individual_197 dut_197(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[197]));
  individual_198 dut_198(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[198]));
  individual_199 dut_199(.clk(clk), .rst(rst), .j(j), .k(k), .q(q_current[199]));

	// Create task to evaluate each testcase
	// Note that this evaluates the entire population for this testcase
	task testcase;
		input j_value;
input k_value;
input q_value;


		// Initialise inputs
		j=j_value;
		k=k_value;

		for(int i = 0; i < `POPULATION_SIZE; i++) begin
      if(q_current[i] == q_value) begin
          fitness[i] = fitness[i] + 1;
      end

		end
	endtask

	// We want to change our inputs on negedge so that we can run testcases at posedge
	always @(posedge clk) begin
		if (rst == 0) begin
			{j, k, q_expected} = testvectors[vectornum];
			vectornum = vectornum + 1;
		end

	end

	always @(posedge clk) begin
		if (rst == 0) begin
			testcase(j, k, q_expected);
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

    // Set all scores to zero
    for(int i = 0; i < `POPULATION_SIZE; i++) begin
      fitness[i] = 0;
    end
     
    // Wait 8 clock cycles for test to complete
    #(`PERIOD*`TEST_COUNT);

    // Print all fitness scores to the console
    for(int i = 0; i < `POPULATION_SIZE; i++) begin
      $display("%0d",fitness[i]);
    end

    $finish;
  end
 endmodule
