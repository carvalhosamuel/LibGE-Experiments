// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VTESTBENCH_H_
#define _VTESTBENCH_H_  // guard

#include "systemc.h"
#include "verilated_sc.h"
#include "verilated_heavy.h"

//==========

class Vtestbench__Syms;

//----------

SC_MODULE(Vtestbench) {
  public:
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ testbench__DOT__clk;
    CData/*0:0*/ testbench__DOT__rst;
    CData/*0:0*/ testbench__DOT__j;
    CData/*0:0*/ testbench__DOT__k;
    IData/*31:0*/ testbench__DOT__vectornum;
    IData/*31:0*/ testbench__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ testbench__DOT__unnamedblk3__DOT__i;
    IData/*31:0*/ testbench__DOT__unnamedblk4__DOT__i;
    CData/*0:0*/ testbench__DOT__q_current[200];
    CData/*0:0*/ testbench__DOT__q_previous[200];
    IData/*31:0*/ testbench__DOT__fitness[200];
    CData/*4:0*/ testbench__DOT__testvectors[8];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ testbench__DOT____Vcellout__dut_100__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_101__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_102__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_103__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_104__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_105__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_106__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_107__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_108__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_109__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_110__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_111__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_112__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_113__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_114__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_115__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_116__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_117__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_118__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_120__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_121__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_122__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_123__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_124__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_125__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_126__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_127__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_128__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_129__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_130__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_131__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_132__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_133__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_134__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_135__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_136__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_137__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_138__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_139__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_140__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_141__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_142__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_143__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_144__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_145__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_146__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_147__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_148__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_149__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_150__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_151__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_152__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_153__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_154__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_155__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_156__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_157__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_158__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_160__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_161__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_164__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_165__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_166__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_167__q;
    };
    struct {
        CData/*0:0*/ testbench__DOT____Vcellout__dut_168__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_169__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_170__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_171__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_172__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_173__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_174__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_176__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_177__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_178__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_179__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_180__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_181__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_184__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_185__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_186__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_187__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_188__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_189__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_190__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_191__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_192__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_193__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_194__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_195__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_196__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_197__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_198__q;
        CData/*0:0*/ testbench__DOT____Vcellout__dut_199__q;
        CData/*0:0*/ testbench__DOT____Vlvbound1;
        CData/*0:0*/ testbench__DOT____Vlvbound6;
        CData/*0:0*/ __VinpClk__TOP__testbench__DOT__clk;
        CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__testbench__DOT__clk;
        CData/*0:0*/ __Vchglast__TOP__testbench__DOT__clk;
        IData/*31:0*/ testbench__DOT____Vlvbound2;
        IData/*31:0*/ testbench__DOT____Vlvbound3;
        IData/*31:0*/ testbench__DOT____Vlvbound4;
        IData/*31:0*/ testbench__DOT____Vlvbound5;
        IData/*31:0*/ testbench__DOT____Vlvbound7;
    };
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vtestbench__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtestbench);  ///< Copying not allowed
  public:
    SC_CTOR(Vtestbench);
    virtual ~Vtestbench();
    
    // API METHODS
  private:
    void eval();
  public:
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vtestbench__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vtestbench__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtestbench__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__1(Vtestbench__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vtestbench__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vtestbench__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vtestbench__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__4(Vtestbench__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__3(Vtestbench__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vtestbench__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
