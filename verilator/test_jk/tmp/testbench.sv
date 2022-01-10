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
`include "tmp/individual_160.sv"
`include "tmp/individual_161.sv"
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
`include "tmp/individual_176.sv"
`include "tmp/individual_177.sv"
`include "tmp/individual_178.sv"
`include "tmp/individual_179.sv"
`include "tmp/individual_180.sv"
`include "tmp/individual_181.sv"
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
`define TEST_COUNT 8
`define PERIOD 10

// Use parameter to pass population size to testbench
module jk_flipflop_tb();
  // Define inputs and outputs to connect to the individuals
  logic clk, rst;
  logic j, k;
  logic q_current[`POPULATION_SIZE],q_previous[`POPULATION_SIZE];

  // Use integer array to store fitness for all individuals
  integer fitness[`POPULATION_SIZE];

  // Array of testvectors to store expected values
  reg [4:0] testvectors[0:(`TEST_COUNT-1)];
  integer vectornum = 0;

  // Initialise q_previous to zero so we can check against it
  initial begin
    for(int i =0; i < `POPULATION_SIZE; i++) begin
      q_previous[i] = 1'b0;
    end
  end
// Instantiate all the individuals
  individual_100 dut_100(.q(q_current[100]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_101 dut_101(.q(q_current[101]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_102 dut_102(.q(q_current[102]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_103 dut_103(.q(q_current[103]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_104 dut_104(.q(q_current[104]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_105 dut_105(.q(q_current[105]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_106 dut_106(.q(q_current[106]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_107 dut_107(.q(q_current[107]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_108 dut_108(.q(q_current[108]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_109 dut_109(.q(q_current[109]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_110 dut_110(.q(q_current[110]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_111 dut_111(.q(q_current[111]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_112 dut_112(.q(q_current[112]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_113 dut_113(.q(q_current[113]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_114 dut_114(.q(q_current[114]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_115 dut_115(.q(q_current[115]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_116 dut_116(.q(q_current[116]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_117 dut_117(.q(q_current[117]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_118 dut_118(.q(q_current[118]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_120 dut_120(.q(q_current[120]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_121 dut_121(.q(q_current[121]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_122 dut_122(.q(q_current[122]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_123 dut_123(.q(q_current[123]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_124 dut_124(.q(q_current[124]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_125 dut_125(.q(q_current[125]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_126 dut_126(.q(q_current[126]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_127 dut_127(.q(q_current[127]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_128 dut_128(.q(q_current[128]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_129 dut_129(.q(q_current[129]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_130 dut_130(.q(q_current[130]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_131 dut_131(.q(q_current[131]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_132 dut_132(.q(q_current[132]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_133 dut_133(.q(q_current[133]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_134 dut_134(.q(q_current[134]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_135 dut_135(.q(q_current[135]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_136 dut_136(.q(q_current[136]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_137 dut_137(.q(q_current[137]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_138 dut_138(.q(q_current[138]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_139 dut_139(.q(q_current[139]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_140 dut_140(.q(q_current[140]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_141 dut_141(.q(q_current[141]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_142 dut_142(.q(q_current[142]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_143 dut_143(.q(q_current[143]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_144 dut_144(.q(q_current[144]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_145 dut_145(.q(q_current[145]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_146 dut_146(.q(q_current[146]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_147 dut_147(.q(q_current[147]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_148 dut_148(.q(q_current[148]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_149 dut_149(.q(q_current[149]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_150 dut_150(.q(q_current[150]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_151 dut_151(.q(q_current[151]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_152 dut_152(.q(q_current[152]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_153 dut_153(.q(q_current[153]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_154 dut_154(.q(q_current[154]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_155 dut_155(.q(q_current[155]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_156 dut_156(.q(q_current[156]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_157 dut_157(.q(q_current[157]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_158 dut_158(.q(q_current[158]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_160 dut_160(.q(q_current[160]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_161 dut_161(.q(q_current[161]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_164 dut_164(.q(q_current[164]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_165 dut_165(.q(q_current[165]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_166 dut_166(.q(q_current[166]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_167 dut_167(.q(q_current[167]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_168 dut_168(.q(q_current[168]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_169 dut_169(.q(q_current[169]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_170 dut_170(.q(q_current[170]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_171 dut_171(.q(q_current[171]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_172 dut_172(.q(q_current[172]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_173 dut_173(.q(q_current[173]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_174 dut_174(.q(q_current[174]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_176 dut_176(.q(q_current[176]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_177 dut_177(.q(q_current[177]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_178 dut_178(.q(q_current[178]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_179 dut_179(.q(q_current[179]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_180 dut_180(.q(q_current[180]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_181 dut_181(.q(q_current[181]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_184 dut_184(.q(q_current[184]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_185 dut_185(.q(q_current[185]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_186 dut_186(.q(q_current[186]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_187 dut_187(.q(q_current[187]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_188 dut_188(.q(q_current[188]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_189 dut_189(.q(q_current[189]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_190 dut_190(.q(q_current[190]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_191 dut_191(.q(q_current[191]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_192 dut_192(.q(q_current[192]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_193 dut_193(.q(q_current[193]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_194 dut_194(.q(q_current[194]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_195 dut_195(.q(q_current[195]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_196 dut_196(.q(q_current[196]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_197 dut_197(.q(q_current[197]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_198 dut_198(.q(q_current[198]),.clk(clk),.rst(rst),.j(j),.k(k));
  individual_199 dut_199(.q(q_current[199]),.clk(clk),.rst(rst),.j(j),.k(k));

  // Create task to evaluate each testcase
  // Note that this evaluates the entire population for this testcase
  task testcase;
    input j_value,k_value;

    // Initialise inputs
    j = j_value; k = k_value;

    #(`PERIOD/2) // Wait till negative clock edge to check signals
    for(int i = 0; i < `POPULATION_SIZE; i++) begin
      // Hold State -> Qn = Q
      if(j == 0 && k == 0) begin
        if(q_current[i] == q_previous[i]) begin
          fitness[i] = fitness[i] + 1;
        end
      end

      // Reset -> Qn = 0
      if(j == 0 && k == 1) begin
        if(q_current[i] == 0) begin
          fitness[i] = fitness[i] + 1;
        end
      end

      // Set -> Qn = 1
      if(j == 1 && k == 0) begin
        if(q_current[i] == 1) begin
          fitness[i] = fitness[i] + 1;
        end
      end

      // Toggle -> Qn = ~Q
      if(j == 1 && k == 1) begin
        if(q_current[i] == ~(q_previous[i])) begin
          fitness[i] = fitness[i] + 1;
        end
      end

      // Set q_previous for next clock
      q_previous[i] = q_current[i];
    end
  endtask

  // We use a clock to load in our testvectors
  always begin
    #(`PERIOD/2) clk = ~clk;
  end

  // We want to change our inputs on negedge so that we can run testcases at
  // posedge
  always @(posedge clk) begin
    if(rst == 1) begin
      {j,k} = testvectors[vectornum];
      vectornum = vectornum + 1;
      testcase(j,k);
    end
  end

  // Run simulation
  initial begin
    // Create VCD file
    //$dumpfile("dump.vcd");
    //$dumpvars(0,jk_flipflop_tb);

    // Set the clock high so we get posedges at 10,20,30 etc.
    clk = 1; rst = 0;
    #(`PERIOD) rst = 1;

    // Read in test vectors
    $readmemb("src/example.tv", testvectors);

    // Set all scores to zero
    for(int i = 0; i < `POPULATION_SIZE; i++) begin
      fitness[i] = 0;
    end
    
    #(`PERIOD*`TEST_COUNT) // Wait 8 clock cycles for test to complete

    // Print all fitness scores to the console
    for(int i = 0; i < `POPULATION_SIZE; i++) begin
      $display("%0d",fitness[i]);
    end

    $finish;
  end
 endmodule
