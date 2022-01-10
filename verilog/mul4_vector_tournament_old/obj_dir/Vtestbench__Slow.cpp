// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestbench.h for the primary calling header

#include "Vtestbench.h"
#include "Vtestbench__Syms.h"

//==========

Vtestbench::Vtestbench(sc_module_name) {
    Vtestbench__Syms* __restrict vlSymsp = __VlSymsp = new Vtestbench__Syms(nullptr, this, name());
    Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Sensitivities on all clocks and combo inputs
    SC_METHOD(eval);
    
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtestbench::__Vconfigure(Vtestbench__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

Vtestbench::~Vtestbench() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vtestbench::_settle__TOP__2(Vtestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_settle__TOP__2\n"); );
    Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->testbench__DOT__clk = (1U & (~ (IData)(vlTOPp->testbench__DOT__clk)));
    vlTOPp->testbench__DOT__y0_current[6U] = 0U;
    vlTOPp->testbench__DOT__y0_current[8U] = 0U;
    vlTOPp->testbench__DOT__y1_current[0xeU] = 0U;
    vlTOPp->testbench__DOT__dut_2__DOT__r3 = (1U & 
                                              (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->testbench__DOT__b1)))));
    vlTOPp->testbench__DOT__dut_2__DOT__r3 = (1U & 
                                              (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->testbench__DOT__dut_2__DOT__r3)))));
    vlTOPp->testbench__DOT____Vcellout__dut_2__y3 = vlTOPp->testbench__DOT__dut_2__DOT__r3;
    vlTOPp->testbench__DOT__dut_3__DOT__r1 = vlTOPp->testbench__DOT__a1;
    vlTOPp->testbench__DOT____Vcellout__dut_3__y1 = vlTOPp->testbench__DOT__dut_3__DOT__r1;
    vlTOPp->testbench__DOT__dut_3__DOT__r3 = vlTOPp->testbench__DOT__b1;
    vlTOPp->testbench__DOT____Vcellout__dut_3__y3 = vlTOPp->testbench__DOT__dut_3__DOT__r3;
    vlTOPp->testbench__DOT__dut_4__DOT__r3 = vlTOPp->testbench__DOT__b1;
    vlTOPp->testbench__DOT__dut_4__DOT__r3 = (1U & 
                                              (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->testbench__DOT__b1)))));
    vlTOPp->testbench__DOT__dut_4__DOT__r3 = (1U & 
                                              (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->testbench__DOT__dut_4__DOT__r3)))));
    vlTOPp->testbench__DOT____Vcellout__dut_4__y3 = vlTOPp->testbench__DOT__dut_4__DOT__r3;
    vlTOPp->testbench__DOT__dut_5__DOT__r1 = vlTOPp->testbench__DOT__a1;
    vlTOPp->testbench__DOT____Vcellout__dut_5__y1 = vlTOPp->testbench__DOT__dut_5__DOT__r1;
    vlTOPp->testbench__DOT__dut_5__DOT__r3 = vlTOPp->testbench__DOT__b1;
    vlTOPp->testbench__DOT____Vcellout__dut_5__y3 = vlTOPp->testbench__DOT__dut_5__DOT__r3;
    vlTOPp->testbench__DOT__dut_6__DOT__r3 = vlTOPp->testbench__DOT__b1;
    vlTOPp->testbench__DOT____Vcellout__dut_6__y3 = vlTOPp->testbench__DOT__dut_6__DOT__r3;
    vlTOPp->testbench__DOT__dut_7__DOT__r1 = vlTOPp->testbench__DOT__a1;
    vlTOPp->testbench__DOT____Vcellout__dut_7__y1 = vlTOPp->testbench__DOT__dut_7__DOT__r1;
    vlTOPp->testbench__DOT__dut_7__DOT__r3 = vlTOPp->testbench__DOT__b1;
    vlTOPp->testbench__DOT____Vcellout__dut_7__y3 = vlTOPp->testbench__DOT__dut_7__DOT__r3;
    vlTOPp->testbench__DOT__dut_8__DOT__r3 = vlTOPp->testbench__DOT__b1;
    vlTOPp->testbench__DOT____Vcellout__dut_8__y3 = vlTOPp->testbench__DOT__dut_8__DOT__r3;
    vlTOPp->testbench__DOT__dut_10__DOT__r1 = vlTOPp->testbench__DOT__a1;
    vlTOPp->testbench__DOT____Vcellout__dut_10__y1 
        = vlTOPp->testbench__DOT__dut_10__DOT__r1;
    vlTOPp->testbench__DOT__dut_10__DOT__r2 = vlTOPp->testbench__DOT__b0;
    vlTOPp->testbench__DOT____Vcellout__dut_10__y2 
        = vlTOPp->testbench__DOT__dut_10__DOT__r2;
    vlTOPp->testbench__DOT__dut_11__DOT__r3 = vlTOPp->testbench__DOT__b1;
    vlTOPp->testbench__DOT____Vcellout__dut_11__y3 
        = vlTOPp->testbench__DOT__dut_11__DOT__r3;
    vlTOPp->testbench__DOT__dut_12__DOT__r1 = vlTOPp->testbench__DOT__a1;
    vlTOPp->testbench__DOT____Vcellout__dut_12__y1 
        = vlTOPp->testbench__DOT__dut_12__DOT__r1;
    vlTOPp->testbench__DOT__dut_12__DOT__r3 = vlTOPp->testbench__DOT__b1;
    vlTOPp->testbench__DOT____Vcellout__dut_12__y3 
        = vlTOPp->testbench__DOT__dut_12__DOT__r3;
    vlTOPp->testbench__DOT__dut_13__DOT__r3 = vlTOPp->testbench__DOT__b1;
    vlTOPp->testbench__DOT____Vcellout__dut_13__y3 
        = vlTOPp->testbench__DOT__dut_13__DOT__r3;
    vlTOPp->testbench__DOT__dut_14__DOT__r2 = vlTOPp->testbench__DOT__b0;
    vlTOPp->testbench__DOT____Vcellout__dut_14__y2 
        = vlTOPp->testbench__DOT__dut_14__DOT__r2;
    vlTOPp->testbench__DOT__dut_14__DOT__r3 = vlTOPp->testbench__DOT__b1;
    vlTOPp->testbench__DOT____Vcellout__dut_14__y3 
        = vlTOPp->testbench__DOT__dut_14__DOT__r3;
    vlTOPp->testbench__DOT__dut_2__DOT__r1 = vlTOPp->testbench__DOT__a1;
    vlTOPp->testbench__DOT__dut_2__DOT__r1 = ((IData)(vlTOPp->testbench__DOT__dut_2__DOT__r1) 
                                              & (IData)(vlTOPp->testbench__DOT__b0));
    vlTOPp->testbench__DOT____Vcellout__dut_2__y1 = vlTOPp->testbench__DOT__dut_2__DOT__r1;
    vlTOPp->testbench__DOT__dut_4__DOT__r1 = vlTOPp->testbench__DOT__a1;
    vlTOPp->testbench__DOT__dut_4__DOT__r1 = ((IData)(vlTOPp->testbench__DOT__dut_4__DOT__r1) 
                                              & (IData)(vlTOPp->testbench__DOT__b0));
    vlTOPp->testbench__DOT____Vcellout__dut_4__y1 = vlTOPp->testbench__DOT__dut_4__DOT__r1;
    vlTOPp->testbench__DOT__dut_9__DOT__r1 = (1U & 
                                              (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->testbench__DOT__a0)))));
    vlTOPp->testbench__DOT____Vcellout__dut_9__y1 = vlTOPp->testbench__DOT__dut_9__DOT__r1;
    vlTOPp->testbench__DOT__dut_14__DOT__r0 = vlTOPp->testbench__DOT__a0;
    vlTOPp->testbench__DOT__dut_14__DOT__r1 = vlTOPp->testbench__DOT__a1;
    vlTOPp->testbench__DOT__dut_14__DOT__r0 = ((IData)(vlTOPp->testbench__DOT__dut_14__DOT__r0) 
                                               ^ (IData)(vlTOPp->testbench__DOT__dut_14__DOT__r1));
    vlTOPp->testbench__DOT__dut_14__DOT__r1 = 0U;
    vlTOPp->testbench__DOT____Vcellout__dut_14__y0 
        = vlTOPp->testbench__DOT__dut_14__DOT__r0;
    vlTOPp->testbench__DOT__dut_2__DOT__r0 = vlTOPp->testbench__DOT__a0;
    vlTOPp->testbench__DOT__dut_2__DOT__r2 = vlTOPp->testbench__DOT__b0;
    vlTOPp->testbench__DOT__dut_2__DOT__r0 = ((IData)(vlTOPp->testbench__DOT__dut_2__DOT__r0) 
                                              & (IData)(vlTOPp->testbench__DOT__dut_2__DOT__r2));
    vlTOPp->testbench__DOT__dut_2__DOT__r2 = (1U & 
                                              (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->testbench__DOT__a0)))));
    vlTOPp->testbench__DOT____Vcellout__dut_2__y2 = vlTOPp->testbench__DOT__dut_2__DOT__r2;
    vlTOPp->testbench__DOT____Vcellout__dut_2__y0 = vlTOPp->testbench__DOT__dut_2__DOT__r0;
    vlTOPp->testbench__DOT__dut_3__DOT__r0 = vlTOPp->testbench__DOT__a0;
    vlTOPp->testbench__DOT__dut_3__DOT__r2 = vlTOPp->testbench__DOT__b0;
    vlTOPp->testbench__DOT__dut_3__DOT__r2 = ((IData)(vlTOPp->testbench__DOT__dut_3__DOT__r2) 
                                              | (IData)(vlTOPp->testbench__DOT__dut_3__DOT__r0));
    vlTOPp->testbench__DOT____Vcellout__dut_3__y2 = vlTOPp->testbench__DOT__dut_3__DOT__r2;
    vlTOPp->testbench__DOT____Vcellout__dut_3__y0 = vlTOPp->testbench__DOT__dut_3__DOT__r0;
    vlTOPp->testbench__DOT__dut_4__DOT__r0 = vlTOPp->testbench__DOT__a0;
    vlTOPp->testbench__DOT__dut_4__DOT__r2 = vlTOPp->testbench__DOT__b0;
    vlTOPp->testbench__DOT__dut_4__DOT__r0 = ((IData)(vlTOPp->testbench__DOT__dut_4__DOT__r0) 
                                              & (IData)(vlTOPp->testbench__DOT__dut_4__DOT__r2));
    vlTOPp->testbench__DOT__dut_4__DOT__r2 = (1U & 
                                              (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->testbench__DOT__dut_4__DOT__r0)))));
    vlTOPp->testbench__DOT____Vcellout__dut_4__y2 = vlTOPp->testbench__DOT__dut_4__DOT__r2;
    vlTOPp->testbench__DOT____Vcellout__dut_4__y0 = vlTOPp->testbench__DOT__dut_4__DOT__r0;
    vlTOPp->testbench__DOT__dut_5__DOT__r0 = vlTOPp->testbench__DOT__a0;
    vlTOPp->testbench__DOT__dut_5__DOT__r2 = vlTOPp->testbench__DOT__b0;
    vlTOPp->testbench__DOT__dut_5__DOT__r2 = ((IData)(vlTOPp->testbench__DOT__dut_5__DOT__r2) 
                                              | (IData)(vlTOPp->testbench__DOT__dut_5__DOT__r0));
    vlTOPp->testbench__DOT__dut_5__DOT__r0 = (1U & 
                                              (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->testbench__DOT__b0)))));
    vlTOPp->testbench__DOT____Vcellout__dut_5__y2 = vlTOPp->testbench__DOT__dut_5__DOT__r2;
    vlTOPp->testbench__DOT____Vcellout__dut_5__y0 = vlTOPp->testbench__DOT__dut_5__DOT__r0;
    vlTOPp->testbench__DOT__dut_6__DOT__r1 = vlTOPp->testbench__DOT__a1;
    vlTOPp->testbench__DOT__dut_6__DOT__r2 = vlTOPp->testbench__DOT__b0;
    vlTOPp->testbench__DOT__dut_6__DOT__r1 = ((IData)(vlTOPp->testbench__DOT__dut_6__DOT__r1) 
                                              | (IData)(vlTOPp->testbench__DOT__dut_6__DOT__r2));
    vlTOPp->testbench__DOT____Vcellout__dut_6__y2 = vlTOPp->testbench__DOT__dut_6__DOT__r2;
    vlTOPp->testbench__DOT____Vcellout__dut_6__y1 = vlTOPp->testbench__DOT__dut_6__DOT__r1;
    vlTOPp->testbench__DOT__dut_7__DOT__r0 = vlTOPp->testbench__DOT__a0;
    vlTOPp->testbench__DOT__dut_7__DOT__r2 = vlTOPp->testbench__DOT__b0;
    vlTOPp->testbench__DOT__dut_7__DOT__r2 = ((IData)(vlTOPp->testbench__DOT__dut_7__DOT__r2) 
                                              | (IData)(vlTOPp->testbench__DOT__dut_7__DOT__r0));
    vlTOPp->testbench__DOT__dut_7__DOT__r0 = (1U & 
                                              (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->testbench__DOT__b0)))));
    vlTOPp->testbench__DOT____Vcellout__dut_7__y2 = vlTOPp->testbench__DOT__dut_7__DOT__r2;
    vlTOPp->testbench__DOT____Vcellout__dut_7__y0 = vlTOPp->testbench__DOT__dut_7__DOT__r0;
    vlTOPp->testbench__DOT__dut_8__DOT__r1 = vlTOPp->testbench__DOT__a1;
    vlTOPp->testbench__DOT__dut_8__DOT__r2 = vlTOPp->testbench__DOT__b0;
    vlTOPp->testbench__DOT__dut_8__DOT__r1 = ((IData)(vlTOPp->testbench__DOT__dut_8__DOT__r1) 
                                              | (IData)(vlTOPp->testbench__DOT__dut_8__DOT__r2));
    vlTOPp->testbench__DOT____Vcellout__dut_8__y2 = vlTOPp->testbench__DOT__dut_8__DOT__r2;
    vlTOPp->testbench__DOT____Vcellout__dut_8__y1 = vlTOPp->testbench__DOT__dut_8__DOT__r1;
    vlTOPp->testbench__DOT__dut_10__DOT__r0 = vlTOPp->testbench__DOT__a0;
    vlTOPp->testbench__DOT__dut_10__DOT__r3 = vlTOPp->testbench__DOT__b1;
    vlTOPp->testbench__DOT__dut_10__DOT__r3 = ((IData)(vlTOPp->testbench__DOT__dut_10__DOT__r3) 
                                               | (IData)(vlTOPp->testbench__DOT__dut_10__DOT__r0));
    vlTOPp->testbench__DOT__dut_10__DOT__r0 = (1U & 
                                               (~ (IData)(
                                                          (0U 
                                                           != (IData)(vlTOPp->testbench__DOT__b1)))));
    vlTOPp->testbench__DOT__dut_10__DOT__r0 = ((IData)(vlTOPp->testbench__DOT__dut_10__DOT__r0) 
                                               | (IData)(vlTOPp->testbench__DOT__a1));
    vlTOPp->testbench__DOT____Vcellout__dut_10__y3 
        = vlTOPp->testbench__DOT__dut_10__DOT__r3;
    vlTOPp->testbench__DOT____Vcellout__dut_10__y0 
        = vlTOPp->testbench__DOT__dut_10__DOT__r0;
    vlTOPp->testbench__DOT__dut_12__DOT__r0 = vlTOPp->testbench__DOT__a0;
    vlTOPp->testbench__DOT__dut_12__DOT__r2 = vlTOPp->testbench__DOT__b0;
    vlTOPp->testbench__DOT__dut_12__DOT__r2 = ((IData)(vlTOPp->testbench__DOT__dut_12__DOT__r2) 
                                               | (IData)(vlTOPp->testbench__DOT__dut_12__DOT__r0));
    vlTOPp->testbench__DOT__dut_12__DOT__r0 = (1U & 
                                               (~ (IData)(
                                                          (0U 
                                                           != (IData)(vlTOPp->testbench__DOT__b1)))));
    vlTOPp->testbench__DOT____Vcellout__dut_12__y2 
        = vlTOPp->testbench__DOT__dut_12__DOT__r2;
    vlTOPp->testbench__DOT____Vcellout__dut_12__y0 
        = vlTOPp->testbench__DOT__dut_12__DOT__r0;
    vlTOPp->testbench__DOT__dut_11__DOT__r0 = vlTOPp->testbench__DOT__a0;
    vlTOPp->testbench__DOT__dut_11__DOT__r2 = vlTOPp->testbench__DOT__b0;
    vlTOPp->testbench__DOT__dut_11__DOT__r2 = ((IData)(vlTOPp->testbench__DOT__dut_11__DOT__r2) 
                                               | (IData)(vlTOPp->testbench__DOT__dut_11__DOT__r0));
    vlTOPp->testbench__DOT__dut_11__DOT__r1 = (1U & 
                                               (~ (IData)(
                                                          (0U 
                                                           != (IData)(vlTOPp->testbench__DOT__dut_11__DOT__r2)))));
    vlTOPp->testbench__DOT__dut_11__DOT__r2 = ((IData)(vlTOPp->testbench__DOT__dut_11__DOT__r2) 
                                               | (IData)(vlTOPp->testbench__DOT__dut_11__DOT__r0));
    vlTOPp->testbench__DOT____Vcellout__dut_11__y2 
        = vlTOPp->testbench__DOT__dut_11__DOT__r2;
    vlTOPp->testbench__DOT____Vcellout__dut_11__y1 
        = vlTOPp->testbench__DOT__dut_11__DOT__r1;
    vlTOPp->testbench__DOT____Vcellout__dut_11__y0 
        = vlTOPp->testbench__DOT__dut_11__DOT__r0;
    vlTOPp->testbench__DOT__dut_13__DOT__r1 = vlTOPp->testbench__DOT__a1;
    vlTOPp->testbench__DOT__dut_13__DOT__r2 = vlTOPp->testbench__DOT__b0;
    vlTOPp->testbench__DOT__dut_13__DOT__r0 = (1U & 
                                               (~ (IData)(
                                                          (0U 
                                                           != (IData)(vlTOPp->testbench__DOT__a0)))));
    vlTOPp->testbench__DOT__dut_13__DOT__r1 = ((IData)(vlTOPp->testbench__DOT__dut_13__DOT__r1) 
                                               | (IData)(vlTOPp->testbench__DOT__dut_13__DOT__r2));
    vlTOPp->testbench__DOT__dut_13__DOT__r2 = ((IData)(vlTOPp->testbench__DOT__dut_13__DOT__r2) 
                                               | (IData)(vlTOPp->testbench__DOT__dut_13__DOT__r0));
    vlTOPp->testbench__DOT____Vcellout__dut_13__y2 
        = vlTOPp->testbench__DOT__dut_13__DOT__r2;
    vlTOPp->testbench__DOT____Vcellout__dut_13__y1 
        = vlTOPp->testbench__DOT__dut_13__DOT__r1;
    vlTOPp->testbench__DOT____Vcellout__dut_13__y0 
        = vlTOPp->testbench__DOT__dut_13__DOT__r0;
    vlTOPp->testbench__DOT__dut_9__DOT__r0 = vlTOPp->testbench__DOT__a0;
    vlTOPp->testbench__DOT__dut_9__DOT__r2 = vlTOPp->testbench__DOT__b0;
    vlTOPp->testbench__DOT__dut_9__DOT__r3 = vlTOPp->testbench__DOT__b1;
    vlTOPp->testbench__DOT__dut_9__DOT__r3 = ((IData)(vlTOPp->testbench__DOT__dut_9__DOT__r3) 
                                              ^ (IData)(vlTOPp->testbench__DOT__b0));
    vlTOPp->testbench__DOT__dut_9__DOT__r0 = ((IData)(vlTOPp->testbench__DOT__dut_9__DOT__r0) 
                                              & (IData)(vlTOPp->testbench__DOT__dut_9__DOT__r2));
    vlTOPp->testbench__DOT__dut_9__DOT__r2 = (1U & 
                                              (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->testbench__DOT__a0)))));
    vlTOPp->testbench__DOT__dut_9__DOT__r3 = (1U & 
                                              (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->testbench__DOT__a1)))));
    vlTOPp->testbench__DOT____Vcellout__dut_9__y3 = vlTOPp->testbench__DOT__dut_9__DOT__r3;
    vlTOPp->testbench__DOT____Vcellout__dut_9__y2 = vlTOPp->testbench__DOT__dut_9__DOT__r2;
    vlTOPp->testbench__DOT____Vcellout__dut_9__y0 = vlTOPp->testbench__DOT__dut_9__DOT__r0;
    vlTOPp->testbench__DOT__dut_0__DOT__r0 = vlTOPp->testbench__DOT__a0;
    vlTOPp->testbench__DOT__dut_0__DOT__r1 = vlTOPp->testbench__DOT__a1;
    vlTOPp->testbench__DOT__dut_0__DOT__r2 = vlTOPp->testbench__DOT__b0;
    vlTOPp->testbench__DOT__dut_0__DOT__r3 = vlTOPp->testbench__DOT__b1;
    vlTOPp->testbench__DOT__dut_0__DOT__r2 = ((IData)(vlTOPp->testbench__DOT__dut_0__DOT__r2) 
                                              & (IData)(vlTOPp->testbench__DOT__b0));
    vlTOPp->testbench__DOT__dut_0__DOT__r0 = ((IData)(vlTOPp->testbench__DOT__dut_0__DOT__r0) 
                                              & (IData)(vlTOPp->testbench__DOT__b1));
    vlTOPp->testbench__DOT__dut_0__DOT__r0 = (1U & 
                                              (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->testbench__DOT__dut_0__DOT__r0)))));
    vlTOPp->testbench__DOT__dut_0__DOT__r2 = (1U & 
                                              (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->testbench__DOT__dut_0__DOT__r0)))));
    vlTOPp->testbench__DOT__dut_0__DOT__r1 = ((IData)(vlTOPp->testbench__DOT__dut_0__DOT__r1) 
                                              | (IData)(vlTOPp->testbench__DOT__dut_0__DOT__r2));
    vlTOPp->testbench__DOT__dut_0__DOT__r0 = ((IData)(vlTOPp->testbench__DOT__dut_0__DOT__r0) 
                                              ^ (IData)(vlTOPp->testbench__DOT__dut_0__DOT__r3));
    vlTOPp->testbench__DOT__dut_0__DOT__r2 = ((IData)(vlTOPp->testbench__DOT__dut_0__DOT__r2) 
                                              | (IData)(vlTOPp->testbench__DOT__dut_0__DOT__r3));
    vlTOPp->testbench__DOT__dut_0__DOT__r0 = ((IData)(vlTOPp->testbench__DOT__dut_0__DOT__r0) 
                                              | (IData)(vlTOPp->testbench__DOT__a0));
    vlTOPp->testbench__DOT__dut_0__DOT__r2 = ((IData)(vlTOPp->testbench__DOT__dut_0__DOT__r2) 
                                              ^ (IData)(vlTOPp->testbench__DOT__a1));
    vlTOPp->testbench__DOT____Vcellout__dut_0__y3 = vlTOPp->testbench__DOT__dut_0__DOT__r3;
    vlTOPp->testbench__DOT____Vcellout__dut_0__y2 = vlTOPp->testbench__DOT__dut_0__DOT__r2;
    vlTOPp->testbench__DOT____Vcellout__dut_0__y1 = vlTOPp->testbench__DOT__dut_0__DOT__r1;
    vlTOPp->testbench__DOT____Vcellout__dut_0__y0 = vlTOPp->testbench__DOT__dut_0__DOT__r0;
    vlTOPp->testbench__DOT__dut_1__DOT__r0 = vlTOPp->testbench__DOT__a0;
    vlTOPp->testbench__DOT__dut_1__DOT__r1 = vlTOPp->testbench__DOT__a1;
    vlTOPp->testbench__DOT__dut_1__DOT__r2 = vlTOPp->testbench__DOT__b0;
    vlTOPp->testbench__DOT__dut_1__DOT__r3 = vlTOPp->testbench__DOT__b1;
    vlTOPp->testbench__DOT__dut_1__DOT__r2 = ((IData)(vlTOPp->testbench__DOT__dut_1__DOT__r2) 
                                              & (IData)(vlTOPp->testbench__DOT__b0));
    vlTOPp->testbench__DOT__dut_1__DOT__r0 = ((IData)(vlTOPp->testbench__DOT__dut_1__DOT__r0) 
                                              & (IData)(vlTOPp->testbench__DOT__b1));
    vlTOPp->testbench__DOT__dut_1__DOT__r0 = (1U & 
                                              (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->testbench__DOT__dut_1__DOT__r0)))));
    vlTOPp->testbench__DOT__dut_1__DOT__r2 = (1U & 
                                              (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->testbench__DOT__dut_1__DOT__r0)))));
    vlTOPp->testbench__DOT__dut_1__DOT__r1 = ((IData)(vlTOPp->testbench__DOT__dut_1__DOT__r1) 
                                              | (IData)(vlTOPp->testbench__DOT__dut_1__DOT__r2));
    vlTOPp->testbench__DOT__dut_1__DOT__r0 = ((IData)(vlTOPp->testbench__DOT__dut_1__DOT__r0) 
                                              ^ (IData)(vlTOPp->testbench__DOT__dut_1__DOT__r3));
    vlTOPp->testbench__DOT__dut_1__DOT__r2 = ((IData)(vlTOPp->testbench__DOT__dut_1__DOT__r2) 
                                              | (IData)(vlTOPp->testbench__DOT__dut_1__DOT__r3));
    vlTOPp->testbench__DOT__dut_1__DOT__r0 = ((IData)(vlTOPp->testbench__DOT__dut_1__DOT__r0) 
                                              | (IData)(vlTOPp->testbench__DOT__a0));
    vlTOPp->testbench__DOT__dut_1__DOT__r2 = ((IData)(vlTOPp->testbench__DOT__dut_1__DOT__r2) 
                                              ^ (IData)(vlTOPp->testbench__DOT__a1));
    vlTOPp->testbench__DOT____Vcellout__dut_1__y3 = vlTOPp->testbench__DOT__dut_1__DOT__r3;
    vlTOPp->testbench__DOT____Vcellout__dut_1__y2 = vlTOPp->testbench__DOT__dut_1__DOT__r2;
    vlTOPp->testbench__DOT____Vcellout__dut_1__y1 = vlTOPp->testbench__DOT__dut_1__DOT__r1;
    vlTOPp->testbench__DOT____Vcellout__dut_1__y0 = vlTOPp->testbench__DOT__dut_1__DOT__r0;
    vlTOPp->testbench__DOT__y3_current[2U] = vlTOPp->testbench__DOT____Vcellout__dut_2__y3;
    vlTOPp->testbench__DOT__y1_current[3U] = vlTOPp->testbench__DOT____Vcellout__dut_3__y1;
    vlTOPp->testbench__DOT__y3_current[3U] = vlTOPp->testbench__DOT____Vcellout__dut_3__y3;
    vlTOPp->testbench__DOT__y3_current[4U] = vlTOPp->testbench__DOT____Vcellout__dut_4__y3;
    vlTOPp->testbench__DOT__y1_current[5U] = vlTOPp->testbench__DOT____Vcellout__dut_5__y1;
    vlTOPp->testbench__DOT__y3_current[5U] = vlTOPp->testbench__DOT____Vcellout__dut_5__y3;
    vlTOPp->testbench__DOT__y3_current[6U] = vlTOPp->testbench__DOT____Vcellout__dut_6__y3;
    vlTOPp->testbench__DOT__y1_current[7U] = vlTOPp->testbench__DOT____Vcellout__dut_7__y1;
    vlTOPp->testbench__DOT__y3_current[7U] = vlTOPp->testbench__DOT____Vcellout__dut_7__y3;
    vlTOPp->testbench__DOT__y3_current[8U] = vlTOPp->testbench__DOT____Vcellout__dut_8__y3;
    vlTOPp->testbench__DOT__y1_current[0xaU] = vlTOPp->testbench__DOT____Vcellout__dut_10__y1;
    vlTOPp->testbench__DOT__y2_current[0xaU] = vlTOPp->testbench__DOT____Vcellout__dut_10__y2;
    vlTOPp->testbench__DOT__y3_current[0xbU] = vlTOPp->testbench__DOT____Vcellout__dut_11__y3;
    vlTOPp->testbench__DOT__y1_current[0xcU] = vlTOPp->testbench__DOT____Vcellout__dut_12__y1;
    vlTOPp->testbench__DOT__y3_current[0xcU] = vlTOPp->testbench__DOT____Vcellout__dut_12__y3;
    vlTOPp->testbench__DOT__y3_current[0xdU] = vlTOPp->testbench__DOT____Vcellout__dut_13__y3;
    vlTOPp->testbench__DOT__y2_current[0xeU] = vlTOPp->testbench__DOT____Vcellout__dut_14__y2;
    vlTOPp->testbench__DOT__y3_current[0xeU] = vlTOPp->testbench__DOT____Vcellout__dut_14__y3;
    vlTOPp->testbench__DOT__y1_current[2U] = vlTOPp->testbench__DOT____Vcellout__dut_2__y1;
    vlTOPp->testbench__DOT__y1_current[4U] = vlTOPp->testbench__DOT____Vcellout__dut_4__y1;
    vlTOPp->testbench__DOT__y1_current[9U] = vlTOPp->testbench__DOT____Vcellout__dut_9__y1;
    vlTOPp->testbench__DOT__y0_current[0xeU] = vlTOPp->testbench__DOT____Vcellout__dut_14__y0;
    vlTOPp->testbench__DOT__y2_current[2U] = vlTOPp->testbench__DOT____Vcellout__dut_2__y2;
    vlTOPp->testbench__DOT__y0_current[2U] = vlTOPp->testbench__DOT____Vcellout__dut_2__y0;
    vlTOPp->testbench__DOT__y2_current[3U] = vlTOPp->testbench__DOT____Vcellout__dut_3__y2;
    vlTOPp->testbench__DOT__y0_current[3U] = vlTOPp->testbench__DOT____Vcellout__dut_3__y0;
    vlTOPp->testbench__DOT__y2_current[4U] = vlTOPp->testbench__DOT____Vcellout__dut_4__y2;
    vlTOPp->testbench__DOT__y0_current[4U] = vlTOPp->testbench__DOT____Vcellout__dut_4__y0;
    vlTOPp->testbench__DOT__y2_current[5U] = vlTOPp->testbench__DOT____Vcellout__dut_5__y2;
    vlTOPp->testbench__DOT__y0_current[5U] = vlTOPp->testbench__DOT____Vcellout__dut_5__y0;
    vlTOPp->testbench__DOT__y2_current[6U] = vlTOPp->testbench__DOT____Vcellout__dut_6__y2;
    vlTOPp->testbench__DOT__y1_current[6U] = vlTOPp->testbench__DOT____Vcellout__dut_6__y1;
    vlTOPp->testbench__DOT__y2_current[7U] = vlTOPp->testbench__DOT____Vcellout__dut_7__y2;
    vlTOPp->testbench__DOT__y0_current[7U] = vlTOPp->testbench__DOT____Vcellout__dut_7__y0;
    vlTOPp->testbench__DOT__y2_current[8U] = vlTOPp->testbench__DOT____Vcellout__dut_8__y2;
    vlTOPp->testbench__DOT__y1_current[8U] = vlTOPp->testbench__DOT____Vcellout__dut_8__y1;
    vlTOPp->testbench__DOT__y3_current[0xaU] = vlTOPp->testbench__DOT____Vcellout__dut_10__y3;
    vlTOPp->testbench__DOT__y0_current[0xaU] = vlTOPp->testbench__DOT____Vcellout__dut_10__y0;
    vlTOPp->testbench__DOT__y2_current[0xcU] = vlTOPp->testbench__DOT____Vcellout__dut_12__y2;
    vlTOPp->testbench__DOT__y0_current[0xcU] = vlTOPp->testbench__DOT____Vcellout__dut_12__y0;
    vlTOPp->testbench__DOT__y2_current[0xbU] = vlTOPp->testbench__DOT____Vcellout__dut_11__y2;
    vlTOPp->testbench__DOT__y1_current[0xbU] = vlTOPp->testbench__DOT____Vcellout__dut_11__y1;
    vlTOPp->testbench__DOT__y0_current[0xbU] = vlTOPp->testbench__DOT____Vcellout__dut_11__y0;
    vlTOPp->testbench__DOT__y2_current[0xdU] = vlTOPp->testbench__DOT____Vcellout__dut_13__y2;
    vlTOPp->testbench__DOT__y1_current[0xdU] = vlTOPp->testbench__DOT____Vcellout__dut_13__y1;
    vlTOPp->testbench__DOT__y0_current[0xdU] = vlTOPp->testbench__DOT____Vcellout__dut_13__y0;
    vlTOPp->testbench__DOT__y3_current[9U] = vlTOPp->testbench__DOT____Vcellout__dut_9__y3;
    vlTOPp->testbench__DOT__y2_current[9U] = vlTOPp->testbench__DOT____Vcellout__dut_9__y2;
    vlTOPp->testbench__DOT__y0_current[9U] = vlTOPp->testbench__DOT____Vcellout__dut_9__y0;
    vlTOPp->testbench__DOT__y3_current[0U] = vlTOPp->testbench__DOT____Vcellout__dut_0__y3;
    vlTOPp->testbench__DOT__y2_current[0U] = vlTOPp->testbench__DOT____Vcellout__dut_0__y2;
    vlTOPp->testbench__DOT__y1_current[0U] = vlTOPp->testbench__DOT____Vcellout__dut_0__y1;
    vlTOPp->testbench__DOT__y0_current[0U] = vlTOPp->testbench__DOT____Vcellout__dut_0__y0;
    vlTOPp->testbench__DOT__y3_current[1U] = vlTOPp->testbench__DOT____Vcellout__dut_1__y3;
    vlTOPp->testbench__DOT__y2_current[1U] = vlTOPp->testbench__DOT____Vcellout__dut_1__y2;
    vlTOPp->testbench__DOT__y1_current[1U] = vlTOPp->testbench__DOT____Vcellout__dut_1__y1;
    vlTOPp->testbench__DOT__y0_current[1U] = vlTOPp->testbench__DOT____Vcellout__dut_1__y0;
}

void Vtestbench::_initial__TOP__4(Vtestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_initial__TOP__4\n"); );
    Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VlWide<6>/*191:0*/ __Vtemp86;
    VlWide<4>/*127:0*/ __Vtemp87;
    // Body
    vlTOPp->testbench__DOT__vectornum = 0U;
    vlTOPp->testbench__DOT__fitness[0U] = 0U;
    vlTOPp->testbench__DOT__fitness[1U] = 0U;
    vlTOPp->testbench__DOT__fitness[2U] = 0U;
    vlTOPp->testbench__DOT__fitness[3U] = 0U;
    vlTOPp->testbench__DOT__fitness[4U] = 0U;
    vlTOPp->testbench__DOT__fitness[5U] = 0U;
    vlTOPp->testbench__DOT__fitness[6U] = 0U;
    vlTOPp->testbench__DOT__fitness[7U] = 0U;
    vlTOPp->testbench__DOT__fitness[8U] = 0U;
    vlTOPp->testbench__DOT__fitness[9U] = 0U;
    vlTOPp->testbench__DOT__fitness[0xaU] = 0U;
    vlTOPp->testbench__DOT__fitness[0xbU] = 0U;
    vlTOPp->testbench__DOT__fitness[0xcU] = 0U;
    vlTOPp->testbench__DOT__fitness[0xdU] = 0U;
    vlTOPp->testbench__DOT__fitness[0xeU] = 0U;
    vlTOPp->testbench__DOT__clk = 1U;
    vlTOPp->testbench__DOT__rst = 0U;
    __Vtemp86[0U] = 0x732e7476U;
    __Vtemp86[1U] = 0x63746f72U;
    __Vtemp86[2U] = 0x745f7665U;
    __Vtemp86[3U] = 0x2f746573U;
    __Vtemp86[4U] = 0x6c617465U;
    __Vtemp86[5U] = 0x74656d70U;
    VL_READMEM_N(false, 128, 2, 0, VL_CVT_PACK_STR_NW(6, __Vtemp86)
                 ,  &(vlTOPp->testbench__DOT__testvectors)
                 , 0, ~0ULL);
    __Vtemp87[0U] = 0x2e747874U;
    __Vtemp87[1U] = 0x72795f62U;
    __Vtemp87[2U] = 0x6d656d6fU;
    __Vtemp87[3U] = 0x746d702fU;
    VL_WRITEMEM_N(false, 128, 2, 0, VL_CVT_PACK_STR_NW(4, __Vtemp87)
                  ,  &(vlTOPp->testbench__DOT__testvectors)
                  , 0, ~0ULL);
    VL_FINISH_MT("tmp/testbench.sv", 156, "");
}

void Vtestbench::_eval_initial(Vtestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_eval_initial\n"); );
    Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__testbench__DOT__clk 
        = vlTOPp->__VinpClk__TOP__testbench__DOT__clk;
    vlTOPp->_initial__TOP__4(vlSymsp);
}

void Vtestbench::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::final\n"); );
    // Variables
    Vtestbench__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtestbench::_eval_settle(Vtestbench__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_eval_settle\n"); );
    Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vtestbench::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_ctor_var_reset\n"); );
    // Body
    for (int __Vi0=0; __Vi0<15; ++__Vi0) {
        testbench__DOT__fitness[__Vi0] = VL_RAND_RESET_I(32);
    }
    testbench__DOT__clk = VL_RAND_RESET_I(1);
    testbench__DOT__rst = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<15; ++__Vi0) {
        testbench__DOT__y3_current[__Vi0] = VL_RAND_RESET_I(16);
    }
    testbench__DOT__y3_expected = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<15; ++__Vi0) {
        testbench__DOT__y2_current[__Vi0] = VL_RAND_RESET_I(16);
    }
    testbench__DOT__y2_expected = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<15; ++__Vi0) {
        testbench__DOT__y1_current[__Vi0] = VL_RAND_RESET_I(16);
    }
    testbench__DOT__y1_expected = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<15; ++__Vi0) {
        testbench__DOT__y0_current[__Vi0] = VL_RAND_RESET_I(16);
    }
    testbench__DOT__y0_expected = VL_RAND_RESET_I(16);
    testbench__DOT__a1 = VL_RAND_RESET_I(16);
    testbench__DOT__a0 = VL_RAND_RESET_I(16);
    testbench__DOT__b1 = VL_RAND_RESET_I(16);
    testbench__DOT__b0 = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        VL_RAND_RESET_W(128, testbench__DOT__testvectors[__Vi0]);
    }
    testbench__DOT__vectornum = VL_RAND_RESET_I(32);
    testbench__DOT____Vcellout__dut_0__y0 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_0__y1 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_0__y2 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_0__y3 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_1__y0 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_1__y1 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_1__y2 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_1__y3 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_2__y0 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_2__y1 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_2__y2 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_2__y3 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_3__y0 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_3__y1 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_3__y2 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_3__y3 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_4__y0 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_4__y1 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_4__y2 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_4__y3 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_5__y0 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_5__y1 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_5__y2 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_5__y3 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_6__y1 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_6__y2 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_6__y3 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_7__y0 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_7__y1 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_7__y2 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_7__y3 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_8__y1 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_8__y2 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_8__y3 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_9__y0 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_9__y1 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_9__y2 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_9__y3 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_10__y0 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_10__y1 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_10__y2 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_10__y3 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_11__y0 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_11__y1 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_11__y2 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_11__y3 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_12__y0 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_12__y1 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_12__y2 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_12__y3 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_13__y0 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_13__y1 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_13__y2 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_13__y3 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_14__y0 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_14__y2 = VL_RAND_RESET_I(16);
    testbench__DOT____Vcellout__dut_14__y3 = VL_RAND_RESET_I(16);
    testbench__DOT____Vlvbound1 = VL_RAND_RESET_I(32);
    testbench__DOT__dut_0__DOT__r0 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_0__DOT__r1 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_0__DOT__r2 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_0__DOT__r3 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_1__DOT__r0 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_1__DOT__r1 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_1__DOT__r2 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_1__DOT__r3 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_2__DOT__r0 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_2__DOT__r1 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_2__DOT__r2 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_2__DOT__r3 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_3__DOT__r0 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_3__DOT__r1 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_3__DOT__r2 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_3__DOT__r3 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_4__DOT__r0 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_4__DOT__r1 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_4__DOT__r2 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_4__DOT__r3 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_5__DOT__r0 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_5__DOT__r1 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_5__DOT__r2 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_5__DOT__r3 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_6__DOT__r1 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_6__DOT__r2 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_6__DOT__r3 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_7__DOT__r0 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_7__DOT__r1 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_7__DOT__r2 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_7__DOT__r3 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_8__DOT__r1 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_8__DOT__r2 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_8__DOT__r3 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_9__DOT__r0 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_9__DOT__r1 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_9__DOT__r2 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_9__DOT__r3 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_10__DOT__r0 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_10__DOT__r1 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_10__DOT__r2 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_10__DOT__r3 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_11__DOT__r0 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_11__DOT__r1 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_11__DOT__r2 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_11__DOT__r3 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_12__DOT__r0 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_12__DOT__r1 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_12__DOT__r2 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_12__DOT__r3 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_13__DOT__r0 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_13__DOT__r1 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_13__DOT__r2 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_13__DOT__r3 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_14__DOT__r0 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_14__DOT__r1 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_14__DOT__r2 = VL_RAND_RESET_I(16);
    testbench__DOT__dut_14__DOT__r3 = VL_RAND_RESET_I(16);
    __VinpClk__TOP__testbench__DOT__clk = VL_RAND_RESET_I(1);
    __Vchglast__TOP__testbench__DOT__clk = VL_RAND_RESET_I(1);
}
