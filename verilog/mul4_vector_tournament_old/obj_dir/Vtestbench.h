// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTESTBENCH_H_
#define VERILATED_VTESTBENCH_H_  // guard

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
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ testbench__DOT__clk;
        CData/*0:0*/ testbench__DOT__rst;
        SData/*15:0*/ testbench__DOT__y3_expected;
        SData/*15:0*/ testbench__DOT__y2_expected;
        SData/*15:0*/ testbench__DOT__y1_expected;
        SData/*15:0*/ testbench__DOT__y0_expected;
        SData/*15:0*/ testbench__DOT__a1;
        SData/*15:0*/ testbench__DOT__a0;
        SData/*15:0*/ testbench__DOT__b1;
        SData/*15:0*/ testbench__DOT__b0;
        SData/*15:0*/ testbench__DOT__dut_0__DOT__r0;
        SData/*15:0*/ testbench__DOT__dut_0__DOT__r1;
        SData/*15:0*/ testbench__DOT__dut_0__DOT__r2;
        SData/*15:0*/ testbench__DOT__dut_0__DOT__r3;
        SData/*15:0*/ testbench__DOT__dut_1__DOT__r0;
        SData/*15:0*/ testbench__DOT__dut_1__DOT__r1;
        SData/*15:0*/ testbench__DOT__dut_1__DOT__r2;
        SData/*15:0*/ testbench__DOT__dut_1__DOT__r3;
        SData/*15:0*/ testbench__DOT__dut_2__DOT__r0;
        SData/*15:0*/ testbench__DOT__dut_2__DOT__r1;
        SData/*15:0*/ testbench__DOT__dut_2__DOT__r2;
        SData/*15:0*/ testbench__DOT__dut_2__DOT__r3;
        SData/*15:0*/ testbench__DOT__dut_3__DOT__r0;
        SData/*15:0*/ testbench__DOT__dut_3__DOT__r1;
        SData/*15:0*/ testbench__DOT__dut_3__DOT__r2;
        SData/*15:0*/ testbench__DOT__dut_3__DOT__r3;
        SData/*15:0*/ testbench__DOT__dut_4__DOT__r0;
        SData/*15:0*/ testbench__DOT__dut_4__DOT__r1;
        SData/*15:0*/ testbench__DOT__dut_4__DOT__r2;
        SData/*15:0*/ testbench__DOT__dut_4__DOT__r3;
        SData/*15:0*/ testbench__DOT__dut_5__DOT__r0;
        SData/*15:0*/ testbench__DOT__dut_5__DOT__r1;
        SData/*15:0*/ testbench__DOT__dut_5__DOT__r2;
        SData/*15:0*/ testbench__DOT__dut_5__DOT__r3;
        SData/*15:0*/ testbench__DOT__dut_6__DOT__r1;
        SData/*15:0*/ testbench__DOT__dut_6__DOT__r2;
        SData/*15:0*/ testbench__DOT__dut_6__DOT__r3;
        SData/*15:0*/ testbench__DOT__dut_7__DOT__r0;
        SData/*15:0*/ testbench__DOT__dut_7__DOT__r1;
        SData/*15:0*/ testbench__DOT__dut_7__DOT__r2;
        SData/*15:0*/ testbench__DOT__dut_7__DOT__r3;
        SData/*15:0*/ testbench__DOT__dut_8__DOT__r1;
        SData/*15:0*/ testbench__DOT__dut_8__DOT__r2;
        SData/*15:0*/ testbench__DOT__dut_8__DOT__r3;
        SData/*15:0*/ testbench__DOT__dut_9__DOT__r0;
        SData/*15:0*/ testbench__DOT__dut_9__DOT__r1;
        SData/*15:0*/ testbench__DOT__dut_9__DOT__r2;
        SData/*15:0*/ testbench__DOT__dut_9__DOT__r3;
        SData/*15:0*/ testbench__DOT__dut_10__DOT__r0;
        SData/*15:0*/ testbench__DOT__dut_10__DOT__r1;
        SData/*15:0*/ testbench__DOT__dut_10__DOT__r2;
        SData/*15:0*/ testbench__DOT__dut_10__DOT__r3;
        SData/*15:0*/ testbench__DOT__dut_11__DOT__r0;
        SData/*15:0*/ testbench__DOT__dut_11__DOT__r1;
        SData/*15:0*/ testbench__DOT__dut_11__DOT__r2;
        SData/*15:0*/ testbench__DOT__dut_11__DOT__r3;
        SData/*15:0*/ testbench__DOT__dut_12__DOT__r0;
        SData/*15:0*/ testbench__DOT__dut_12__DOT__r1;
        SData/*15:0*/ testbench__DOT__dut_12__DOT__r2;
        SData/*15:0*/ testbench__DOT__dut_12__DOT__r3;
        SData/*15:0*/ testbench__DOT__dut_13__DOT__r0;
        SData/*15:0*/ testbench__DOT__dut_13__DOT__r1;
        SData/*15:0*/ testbench__DOT__dut_13__DOT__r2;
        SData/*15:0*/ testbench__DOT__dut_13__DOT__r3;
    };
    struct {
        SData/*15:0*/ testbench__DOT__dut_14__DOT__r0;
        SData/*15:0*/ testbench__DOT__dut_14__DOT__r1;
        SData/*15:0*/ testbench__DOT__dut_14__DOT__r2;
        SData/*15:0*/ testbench__DOT__dut_14__DOT__r3;
        IData/*31:0*/ testbench__DOT__vectornum;
        VlUnpacked<IData/*31:0*/, 15> testbench__DOT__fitness;
        VlUnpacked<SData/*15:0*/, 15> testbench__DOT__y3_current;
        VlUnpacked<SData/*15:0*/, 15> testbench__DOT__y2_current;
        VlUnpacked<SData/*15:0*/, 15> testbench__DOT__y1_current;
        VlUnpacked<SData/*15:0*/, 15> testbench__DOT__y0_current;
        VlUnpacked<VlWide<4>/*127:0*/, 2> testbench__DOT__testvectors;
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __VinpClk__TOP__testbench__DOT__clk;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__testbench__DOT__clk;
    CData/*0:0*/ __Vchglast__TOP__testbench__DOT__clk;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_0__y0;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_0__y1;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_0__y2;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_0__y3;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_1__y0;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_1__y1;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_1__y2;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_1__y3;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_2__y0;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_2__y1;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_2__y2;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_2__y3;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_3__y0;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_3__y1;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_3__y2;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_3__y3;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_4__y0;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_4__y1;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_4__y2;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_4__y3;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_5__y0;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_5__y1;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_5__y2;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_5__y3;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_6__y1;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_6__y2;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_6__y3;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_7__y0;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_7__y1;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_7__y2;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_7__y3;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_8__y1;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_8__y2;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_8__y3;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_9__y0;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_9__y1;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_9__y2;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_9__y3;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_10__y0;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_10__y1;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_10__y2;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_10__y3;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_11__y0;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_11__y1;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_11__y2;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_11__y3;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_12__y0;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_12__y1;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_12__y2;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_12__y3;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_13__y0;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_13__y1;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_13__y2;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_13__y3;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_14__y0;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_14__y2;
    SData/*15:0*/ testbench__DOT____Vcellout__dut_14__y3;
    IData/*31:0*/ testbench__DOT____Vlvbound1;
    
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
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp();
  private:
    void eval() { eval_step(); }
    void eval_step();
  public:
    void final();
    
    // INTERNAL METHODS
    static void _eval_initial_loop(Vtestbench__Syms* __restrict vlSymsp);
    void __Vconfigure(Vtestbench__Syms* symsp, bool first);
  private:
    static QData _change_request(Vtestbench__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vtestbench__Syms* __restrict vlSymsp);
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
