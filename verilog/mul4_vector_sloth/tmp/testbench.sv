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
  individual_150 dut_150(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[150]), .y2(y2_current[150]), .y1(y1_current[150]), .y0(y0_current[150]));
  individual_151 dut_151(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[151]), .y2(y2_current[151]), .y1(y1_current[151]), .y0(y0_current[151]));
  individual_152 dut_152(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[152]), .y2(y2_current[152]), .y1(y1_current[152]), .y0(y0_current[152]));
  individual_153 dut_153(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[153]), .y2(y2_current[153]), .y1(y1_current[153]), .y0(y0_current[153]));
  individual_154 dut_154(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[154]), .y2(y2_current[154]), .y1(y1_current[154]), .y0(y0_current[154]));
  individual_155 dut_155(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[155]), .y2(y2_current[155]), .y1(y1_current[155]), .y0(y0_current[155]));
  individual_156 dut_156(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[156]), .y2(y2_current[156]), .y1(y1_current[156]), .y0(y0_current[156]));
  individual_157 dut_157(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[157]), .y2(y2_current[157]), .y1(y1_current[157]), .y0(y0_current[157]));
  individual_158 dut_158(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[158]), .y2(y2_current[158]), .y1(y1_current[158]), .y0(y0_current[158]));
  individual_159 dut_159(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[159]), .y2(y2_current[159]), .y1(y1_current[159]), .y0(y0_current[159]));
  individual_160 dut_160(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[160]), .y2(y2_current[160]), .y1(y1_current[160]), .y0(y0_current[160]));
  individual_161 dut_161(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[161]), .y2(y2_current[161]), .y1(y1_current[161]), .y0(y0_current[161]));
  individual_162 dut_162(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[162]), .y2(y2_current[162]), .y1(y1_current[162]), .y0(y0_current[162]));
  individual_163 dut_163(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[163]), .y2(y2_current[163]), .y1(y1_current[163]), .y0(y0_current[163]));
  individual_164 dut_164(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[164]), .y2(y2_current[164]), .y1(y1_current[164]), .y0(y0_current[164]));
  individual_165 dut_165(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[165]), .y2(y2_current[165]), .y1(y1_current[165]), .y0(y0_current[165]));
  individual_166 dut_166(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[166]), .y2(y2_current[166]), .y1(y1_current[166]), .y0(y0_current[166]));
  individual_167 dut_167(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[167]), .y2(y2_current[167]), .y1(y1_current[167]), .y0(y0_current[167]));
  individual_168 dut_168(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[168]), .y2(y2_current[168]), .y1(y1_current[168]), .y0(y0_current[168]));
  individual_169 dut_169(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[169]), .y2(y2_current[169]), .y1(y1_current[169]), .y0(y0_current[169]));
  individual_170 dut_170(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[170]), .y2(y2_current[170]), .y1(y1_current[170]), .y0(y0_current[170]));
  individual_171 dut_171(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[171]), .y2(y2_current[171]), .y1(y1_current[171]), .y0(y0_current[171]));
  individual_172 dut_172(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[172]), .y2(y2_current[172]), .y1(y1_current[172]), .y0(y0_current[172]));
  individual_173 dut_173(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[173]), .y2(y2_current[173]), .y1(y1_current[173]), .y0(y0_current[173]));
  individual_174 dut_174(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[174]), .y2(y2_current[174]), .y1(y1_current[174]), .y0(y0_current[174]));
  individual_175 dut_175(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[175]), .y2(y2_current[175]), .y1(y1_current[175]), .y0(y0_current[175]));
  individual_176 dut_176(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[176]), .y2(y2_current[176]), .y1(y1_current[176]), .y0(y0_current[176]));
  individual_177 dut_177(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[177]), .y2(y2_current[177]), .y1(y1_current[177]), .y0(y0_current[177]));
  individual_178 dut_178(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[178]), .y2(y2_current[178]), .y1(y1_current[178]), .y0(y0_current[178]));
  individual_179 dut_179(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[179]), .y2(y2_current[179]), .y1(y1_current[179]), .y0(y0_current[179]));
  individual_180 dut_180(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[180]), .y2(y2_current[180]), .y1(y1_current[180]), .y0(y0_current[180]));
  individual_181 dut_181(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[181]), .y2(y2_current[181]), .y1(y1_current[181]), .y0(y0_current[181]));
  individual_182 dut_182(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[182]), .y2(y2_current[182]), .y1(y1_current[182]), .y0(y0_current[182]));
  individual_183 dut_183(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[183]), .y2(y2_current[183]), .y1(y1_current[183]), .y0(y0_current[183]));
  individual_184 dut_184(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[184]), .y2(y2_current[184]), .y1(y1_current[184]), .y0(y0_current[184]));
  individual_185 dut_185(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[185]), .y2(y2_current[185]), .y1(y1_current[185]), .y0(y0_current[185]));
  individual_186 dut_186(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[186]), .y2(y2_current[186]), .y1(y1_current[186]), .y0(y0_current[186]));
  individual_187 dut_187(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[187]), .y2(y2_current[187]), .y1(y1_current[187]), .y0(y0_current[187]));
  individual_188 dut_188(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[188]), .y2(y2_current[188]), .y1(y1_current[188]), .y0(y0_current[188]));
  individual_189 dut_189(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[189]), .y2(y2_current[189]), .y1(y1_current[189]), .y0(y0_current[189]));
  individual_190 dut_190(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[190]), .y2(y2_current[190]), .y1(y1_current[190]), .y0(y0_current[190]));
  individual_191 dut_191(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[191]), .y2(y2_current[191]), .y1(y1_current[191]), .y0(y0_current[191]));
  individual_192 dut_192(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[192]), .y2(y2_current[192]), .y1(y1_current[192]), .y0(y0_current[192]));
  individual_193 dut_193(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[193]), .y2(y2_current[193]), .y1(y1_current[193]), .y0(y0_current[193]));
  individual_194 dut_194(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[194]), .y2(y2_current[194]), .y1(y1_current[194]), .y0(y0_current[194]));
  individual_195 dut_195(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[195]), .y2(y2_current[195]), .y1(y1_current[195]), .y0(y0_current[195]));
  individual_196 dut_196(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[196]), .y2(y2_current[196]), .y1(y1_current[196]), .y0(y0_current[196]));
  individual_197 dut_197(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[197]), .y2(y2_current[197]), .y1(y1_current[197]), .y0(y0_current[197]));
  individual_198 dut_198(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[198]), .y2(y2_current[198]), .y1(y1_current[198]), .y0(y0_current[198]));
  individual_199 dut_199(.a1(a1), .a0(a0), .b1(b1), .b0(b0), .y3(y3_current[199]), .y2(y2_current[199]), .y1(y1_current[199]), .y0(y0_current[199]));

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
