// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtestbench.h for the primary calling header

#include "Vtestbench.h"
#include "Vtestbench__Syms.h"

//==========

VerilatedContext* Vtestbench::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void Vtestbench::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtestbench::eval\n"); );
    Vtestbench__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("tmp/testbench.sv", 26, "",
                "Verilated model didn't converge\n"
                "- See https://verilator.org/warn/DIDNOTCONVERGE");
            } else {
                __Vchange = _change_request(vlSymsp);
            }
        } while (VL_UNLIKELY(__Vchange));
    }
    
    void Vtestbench::_eval_initial_loop(Vtestbench__Syms* __restrict vlSymsp) {
        vlSymsp->__Vm_didInit = true;
        _eval_initial(vlSymsp);
        // Evaluate till stable
        int __VclockLoop = 0;
        QData __Vchange = 1;
        do {
            _eval_settle(vlSymsp);
            _eval(vlSymsp);
            if (VL_UNLIKELY(++__VclockLoop > 100)) {
                // About to fail, so enable debug to see what's not settling.
                // Note you must run make with OPT=-DVL_DEBUG for debug prints.
                int __Vsaved_debug = Verilated::debug();
                Verilated::debug(1);
                __Vchange = _change_request(vlSymsp);
                Verilated::debug(__Vsaved_debug);
                VL_FATAL_MT("tmp/testbench.sv", 26, "",
                    "Verilated model didn't DC converge\n"
                    "- See https://verilator.org/warn/DIDNOTCONVERGE");
                } else {
                    __Vchange = _change_request(vlSymsp);
                }
            } while (VL_UNLIKELY(__Vchange));
        }
        
        VL_INLINE_OPT void Vtestbench::_combo__TOP__1(Vtestbench__Syms* __restrict vlSymsp) {
            VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_combo__TOP__1\n"); );
            Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
            // Body
            vlTOPp->testbench__DOT__clk = (1U & (~ (IData)(vlTOPp->testbench__DOT__clk)));
        }
        
        VL_INLINE_OPT void Vtestbench::_sequent__TOP__3(Vtestbench__Syms* __restrict vlSymsp) {
            VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_sequent__TOP__3\n"); );
            Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
            // Variables
            SData/*15:0*/ __Vtask_testbench__DOT__testcase__0__a1_value;
            SData/*15:0*/ __Vtask_testbench__DOT__testcase__0__a0_value;
            SData/*15:0*/ __Vtask_testbench__DOT__testcase__0__b1_value;
            SData/*15:0*/ __Vtask_testbench__DOT__testcase__0__b0_value;
            SData/*15:0*/ __Vtask_testbench__DOT__testcase__0__y3_value;
            SData/*15:0*/ __Vtask_testbench__DOT__testcase__0__y2_value;
            SData/*15:0*/ __Vtask_testbench__DOT__testcase__0__y1_value;
            SData/*15:0*/ __Vtask_testbench__DOT__testcase__0__y0_value;
            // Body
            if ((1U & (~ (IData)(vlTOPp->testbench__DOT__rst)))) {
                vlTOPp->testbench__DOT__a1 = (0xffffU 
                                              & (vlTOPp->testbench__DOT__testvectors
                                                 [(1U 
                                                   & vlTOPp->testbench__DOT__vectornum)][3U] 
                                                 >> 0x10U));
                vlTOPp->testbench__DOT__a0 = (0xffffU 
                                              & vlTOPp->testbench__DOT__testvectors
                                              [(1U 
                                                & vlTOPp->testbench__DOT__vectornum)][3U]);
                vlTOPp->testbench__DOT__b1 = (0xffffU 
                                              & ((vlTOPp->testbench__DOT__testvectors
                                                  [
                                                  (1U 
                                                   & vlTOPp->testbench__DOT__vectornum)][3U] 
                                                  << 0x10U) 
                                                 | (vlTOPp->testbench__DOT__testvectors
                                                    [
                                                    (1U 
                                                     & vlTOPp->testbench__DOT__vectornum)][2U] 
                                                    >> 0x10U)));
                vlTOPp->testbench__DOT__b0 = (0xffffU 
                                              & vlTOPp->testbench__DOT__testvectors
                                              [(1U 
                                                & vlTOPp->testbench__DOT__vectornum)][2U]);
                vlTOPp->testbench__DOT__y3_expected 
                    = (0xffffU & ((vlTOPp->testbench__DOT__testvectors
                                   [(1U & vlTOPp->testbench__DOT__vectornum)][2U] 
                                   << 0x10U) | (vlTOPp->testbench__DOT__testvectors
                                                [(1U 
                                                  & vlTOPp->testbench__DOT__vectornum)][1U] 
                                                >> 0x10U)));
                vlTOPp->testbench__DOT__y2_expected 
                    = (0xffffU & vlTOPp->testbench__DOT__testvectors
                       [(1U & vlTOPp->testbench__DOT__vectornum)][1U]);
                vlTOPp->testbench__DOT__y1_expected 
                    = (0xffffU & ((vlTOPp->testbench__DOT__testvectors
                                   [(1U & vlTOPp->testbench__DOT__vectornum)][1U] 
                                   << 0x10U) | (vlTOPp->testbench__DOT__testvectors
                                                [(1U 
                                                  & vlTOPp->testbench__DOT__vectornum)][0U] 
                                                >> 0x10U)));
                vlTOPp->testbench__DOT__y0_expected 
                    = (0xffffU & vlTOPp->testbench__DOT__testvectors
                       [(1U & vlTOPp->testbench__DOT__vectornum)][0U]);
                vlTOPp->testbench__DOT__vectornum = 
                    ((IData)(1U) + vlTOPp->testbench__DOT__vectornum);
                __Vtask_testbench__DOT__testcase__0__y0_value 
                    = vlTOPp->testbench__DOT__y0_expected;
                __Vtask_testbench__DOT__testcase__0__y1_value 
                    = vlTOPp->testbench__DOT__y1_expected;
                __Vtask_testbench__DOT__testcase__0__y2_value 
                    = vlTOPp->testbench__DOT__y2_expected;
                __Vtask_testbench__DOT__testcase__0__y3_value 
                    = vlTOPp->testbench__DOT__y3_expected;
                __Vtask_testbench__DOT__testcase__0__b0_value 
                    = vlTOPp->testbench__DOT__b0;
                __Vtask_testbench__DOT__testcase__0__b1_value 
                    = vlTOPp->testbench__DOT__b1;
                __Vtask_testbench__DOT__testcase__0__a0_value 
                    = vlTOPp->testbench__DOT__a0;
                __Vtask_testbench__DOT__testcase__0__a1_value 
                    = vlTOPp->testbench__DOT__a1;
                vlTOPp->testbench__DOT__a1 = __Vtask_testbench__DOT__testcase__0__a1_value;
                vlTOPp->testbench__DOT__a0 = __Vtask_testbench__DOT__testcase__0__a0_value;
                vlTOPp->testbench__DOT__b1 = __Vtask_testbench__DOT__testcase__0__b1_value;
                vlTOPp->testbench__DOT__b0 = __Vtask_testbench__DOT__testcase__0__b0_value;
                vlTOPp->testbench__DOT____Vlvbound1 
                    = ((((0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y3_current
                                                      [0U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y3_value)))))) 
                         + (0x1fU & VL_COUNTONES_I(
                                                   (0xffffU 
                                                    & (~ 
                                                       (vlTOPp->testbench__DOT__y2_current
                                                        [0U] 
                                                        ^ (IData)(__Vtask_testbench__DOT__testcase__0__y2_value))))))) 
                        + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                   & (~ 
                                                      (vlTOPp->testbench__DOT__y1_current
                                                       [0U] 
                                                       ^ (IData)(__Vtask_testbench__DOT__testcase__0__y1_value))))))) 
                       + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y0_current
                                                      [0U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y0_value)))))));
                vlTOPp->testbench__DOT__fitness[0U] 
                    = vlTOPp->testbench__DOT____Vlvbound1;
                vlTOPp->testbench__DOT____Vlvbound1 
                    = ((((0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y3_current
                                                      [1U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y3_value)))))) 
                         + (0x1fU & VL_COUNTONES_I(
                                                   (0xffffU 
                                                    & (~ 
                                                       (vlTOPp->testbench__DOT__y2_current
                                                        [1U] 
                                                        ^ (IData)(__Vtask_testbench__DOT__testcase__0__y2_value))))))) 
                        + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                   & (~ 
                                                      (vlTOPp->testbench__DOT__y1_current
                                                       [1U] 
                                                       ^ (IData)(__Vtask_testbench__DOT__testcase__0__y1_value))))))) 
                       + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y0_current
                                                      [1U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y0_value)))))));
                vlTOPp->testbench__DOT__fitness[1U] 
                    = vlTOPp->testbench__DOT____Vlvbound1;
                vlTOPp->testbench__DOT____Vlvbound1 
                    = ((((0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y3_current
                                                      [2U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y3_value)))))) 
                         + (0x1fU & VL_COUNTONES_I(
                                                   (0xffffU 
                                                    & (~ 
                                                       (vlTOPp->testbench__DOT__y2_current
                                                        [2U] 
                                                        ^ (IData)(__Vtask_testbench__DOT__testcase__0__y2_value))))))) 
                        + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                   & (~ 
                                                      (vlTOPp->testbench__DOT__y1_current
                                                       [2U] 
                                                       ^ (IData)(__Vtask_testbench__DOT__testcase__0__y1_value))))))) 
                       + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y0_current
                                                      [2U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y0_value)))))));
                vlTOPp->testbench__DOT__fitness[2U] 
                    = vlTOPp->testbench__DOT____Vlvbound1;
                vlTOPp->testbench__DOT____Vlvbound1 
                    = ((((0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y3_current
                                                      [3U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y3_value)))))) 
                         + (0x1fU & VL_COUNTONES_I(
                                                   (0xffffU 
                                                    & (~ 
                                                       (vlTOPp->testbench__DOT__y2_current
                                                        [3U] 
                                                        ^ (IData)(__Vtask_testbench__DOT__testcase__0__y2_value))))))) 
                        + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                   & (~ 
                                                      (vlTOPp->testbench__DOT__y1_current
                                                       [3U] 
                                                       ^ (IData)(__Vtask_testbench__DOT__testcase__0__y1_value))))))) 
                       + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y0_current
                                                      [3U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y0_value)))))));
                vlTOPp->testbench__DOT__fitness[3U] 
                    = vlTOPp->testbench__DOT____Vlvbound1;
                vlTOPp->testbench__DOT____Vlvbound1 
                    = ((((0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y3_current
                                                      [4U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y3_value)))))) 
                         + (0x1fU & VL_COUNTONES_I(
                                                   (0xffffU 
                                                    & (~ 
                                                       (vlTOPp->testbench__DOT__y2_current
                                                        [4U] 
                                                        ^ (IData)(__Vtask_testbench__DOT__testcase__0__y2_value))))))) 
                        + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                   & (~ 
                                                      (vlTOPp->testbench__DOT__y1_current
                                                       [4U] 
                                                       ^ (IData)(__Vtask_testbench__DOT__testcase__0__y1_value))))))) 
                       + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y0_current
                                                      [4U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y0_value)))))));
                vlTOPp->testbench__DOT__fitness[4U] 
                    = vlTOPp->testbench__DOT____Vlvbound1;
                vlTOPp->testbench__DOT____Vlvbound1 
                    = ((((0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y3_current
                                                      [5U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y3_value)))))) 
                         + (0x1fU & VL_COUNTONES_I(
                                                   (0xffffU 
                                                    & (~ 
                                                       (vlTOPp->testbench__DOT__y2_current
                                                        [5U] 
                                                        ^ (IData)(__Vtask_testbench__DOT__testcase__0__y2_value))))))) 
                        + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                   & (~ 
                                                      (vlTOPp->testbench__DOT__y1_current
                                                       [5U] 
                                                       ^ (IData)(__Vtask_testbench__DOT__testcase__0__y1_value))))))) 
                       + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y0_current
                                                      [5U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y0_value)))))));
                vlTOPp->testbench__DOT__fitness[5U] 
                    = vlTOPp->testbench__DOT____Vlvbound1;
                vlTOPp->testbench__DOT____Vlvbound1 
                    = ((((0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y3_current
                                                      [6U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y3_value)))))) 
                         + (0x1fU & VL_COUNTONES_I(
                                                   (0xffffU 
                                                    & (~ 
                                                       (vlTOPp->testbench__DOT__y2_current
                                                        [6U] 
                                                        ^ (IData)(__Vtask_testbench__DOT__testcase__0__y2_value))))))) 
                        + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                   & (~ 
                                                      (vlTOPp->testbench__DOT__y1_current
                                                       [6U] 
                                                       ^ (IData)(__Vtask_testbench__DOT__testcase__0__y1_value))))))) 
                       + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y0_current
                                                      [6U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y0_value)))))));
                vlTOPp->testbench__DOT__fitness[6U] 
                    = vlTOPp->testbench__DOT____Vlvbound1;
                vlTOPp->testbench__DOT____Vlvbound1 
                    = ((((0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y3_current
                                                      [7U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y3_value)))))) 
                         + (0x1fU & VL_COUNTONES_I(
                                                   (0xffffU 
                                                    & (~ 
                                                       (vlTOPp->testbench__DOT__y2_current
                                                        [7U] 
                                                        ^ (IData)(__Vtask_testbench__DOT__testcase__0__y2_value))))))) 
                        + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                   & (~ 
                                                      (vlTOPp->testbench__DOT__y1_current
                                                       [7U] 
                                                       ^ (IData)(__Vtask_testbench__DOT__testcase__0__y1_value))))))) 
                       + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y0_current
                                                      [7U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y0_value)))))));
                vlTOPp->testbench__DOT__fitness[7U] 
                    = vlTOPp->testbench__DOT____Vlvbound1;
                vlTOPp->testbench__DOT____Vlvbound1 
                    = ((((0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y3_current
                                                      [8U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y3_value)))))) 
                         + (0x1fU & VL_COUNTONES_I(
                                                   (0xffffU 
                                                    & (~ 
                                                       (vlTOPp->testbench__DOT__y2_current
                                                        [8U] 
                                                        ^ (IData)(__Vtask_testbench__DOT__testcase__0__y2_value))))))) 
                        + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                   & (~ 
                                                      (vlTOPp->testbench__DOT__y1_current
                                                       [8U] 
                                                       ^ (IData)(__Vtask_testbench__DOT__testcase__0__y1_value))))))) 
                       + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y0_current
                                                      [8U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y0_value)))))));
                vlTOPp->testbench__DOT__fitness[8U] 
                    = vlTOPp->testbench__DOT____Vlvbound1;
                vlTOPp->testbench__DOT____Vlvbound1 
                    = ((((0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y3_current
                                                      [9U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y3_value)))))) 
                         + (0x1fU & VL_COUNTONES_I(
                                                   (0xffffU 
                                                    & (~ 
                                                       (vlTOPp->testbench__DOT__y2_current
                                                        [9U] 
                                                        ^ (IData)(__Vtask_testbench__DOT__testcase__0__y2_value))))))) 
                        + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                   & (~ 
                                                      (vlTOPp->testbench__DOT__y1_current
                                                       [9U] 
                                                       ^ (IData)(__Vtask_testbench__DOT__testcase__0__y1_value))))))) 
                       + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y0_current
                                                      [9U] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y0_value)))))));
                vlTOPp->testbench__DOT__fitness[9U] 
                    = vlTOPp->testbench__DOT____Vlvbound1;
                vlTOPp->testbench__DOT____Vlvbound1 
                    = ((((0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y3_current
                                                      [0xaU] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y3_value)))))) 
                         + (0x1fU & VL_COUNTONES_I(
                                                   (0xffffU 
                                                    & (~ 
                                                       (vlTOPp->testbench__DOT__y2_current
                                                        [0xaU] 
                                                        ^ (IData)(__Vtask_testbench__DOT__testcase__0__y2_value))))))) 
                        + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                   & (~ 
                                                      (vlTOPp->testbench__DOT__y1_current
                                                       [0xaU] 
                                                       ^ (IData)(__Vtask_testbench__DOT__testcase__0__y1_value))))))) 
                       + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y0_current
                                                      [0xaU] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y0_value)))))));
                vlTOPp->testbench__DOT__fitness[0xaU] 
                    = vlTOPp->testbench__DOT____Vlvbound1;
                vlTOPp->testbench__DOT____Vlvbound1 
                    = ((((0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y3_current
                                                      [0xbU] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y3_value)))))) 
                         + (0x1fU & VL_COUNTONES_I(
                                                   (0xffffU 
                                                    & (~ 
                                                       (vlTOPp->testbench__DOT__y2_current
                                                        [0xbU] 
                                                        ^ (IData)(__Vtask_testbench__DOT__testcase__0__y2_value))))))) 
                        + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                   & (~ 
                                                      (vlTOPp->testbench__DOT__y1_current
                                                       [0xbU] 
                                                       ^ (IData)(__Vtask_testbench__DOT__testcase__0__y1_value))))))) 
                       + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y0_current
                                                      [0xbU] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y0_value)))))));
                vlTOPp->testbench__DOT__fitness[0xbU] 
                    = vlTOPp->testbench__DOT____Vlvbound1;
                vlTOPp->testbench__DOT____Vlvbound1 
                    = ((((0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y3_current
                                                      [0xcU] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y3_value)))))) 
                         + (0x1fU & VL_COUNTONES_I(
                                                   (0xffffU 
                                                    & (~ 
                                                       (vlTOPp->testbench__DOT__y2_current
                                                        [0xcU] 
                                                        ^ (IData)(__Vtask_testbench__DOT__testcase__0__y2_value))))))) 
                        + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                   & (~ 
                                                      (vlTOPp->testbench__DOT__y1_current
                                                       [0xcU] 
                                                       ^ (IData)(__Vtask_testbench__DOT__testcase__0__y1_value))))))) 
                       + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y0_current
                                                      [0xcU] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y0_value)))))));
                vlTOPp->testbench__DOT__fitness[0xcU] 
                    = vlTOPp->testbench__DOT____Vlvbound1;
                vlTOPp->testbench__DOT____Vlvbound1 
                    = ((((0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y3_current
                                                      [0xdU] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y3_value)))))) 
                         + (0x1fU & VL_COUNTONES_I(
                                                   (0xffffU 
                                                    & (~ 
                                                       (vlTOPp->testbench__DOT__y2_current
                                                        [0xdU] 
                                                        ^ (IData)(__Vtask_testbench__DOT__testcase__0__y2_value))))))) 
                        + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                   & (~ 
                                                      (vlTOPp->testbench__DOT__y1_current
                                                       [0xdU] 
                                                       ^ (IData)(__Vtask_testbench__DOT__testcase__0__y1_value))))))) 
                       + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y0_current
                                                      [0xdU] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y0_value)))))));
                vlTOPp->testbench__DOT__fitness[0xdU] 
                    = vlTOPp->testbench__DOT____Vlvbound1;
                vlTOPp->testbench__DOT____Vlvbound1 
                    = ((((0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y3_current
                                                      [0xeU] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y3_value)))))) 
                         + (0x1fU & VL_COUNTONES_I(
                                                   (0xffffU 
                                                    & (~ 
                                                       (vlTOPp->testbench__DOT__y2_current
                                                        [0xeU] 
                                                        ^ (IData)(__Vtask_testbench__DOT__testcase__0__y2_value))))))) 
                        + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                   & (~ 
                                                      (vlTOPp->testbench__DOT__y1_current
                                                       [0xeU] 
                                                       ^ (IData)(__Vtask_testbench__DOT__testcase__0__y1_value))))))) 
                       + (0x1fU & VL_COUNTONES_I((0xffffU 
                                                  & (~ 
                                                     (vlTOPp->testbench__DOT__y0_current
                                                      [0xeU] 
                                                      ^ (IData)(__Vtask_testbench__DOT__testcase__0__y0_value)))))));
                vlTOPp->testbench__DOT__fitness[0xeU] 
                    = vlTOPp->testbench__DOT____Vlvbound1;
            }
            if (VL_UNLIKELY((2U == vlTOPp->testbench__DOT__vectornum))) {
                VL_WRITEF("Individual 0 fitness: %0d\nIndividual 1 fitness: %0d\nIndividual 2 fitness: %0d\nIndividual 3 fitness: %0d\nIndividual 4 fitness: %0d\nIndividual 5 fitness: %0d\nIndividual 6 fitness: %0d\nIndividual 7 fitness: %0d\nIndividual 8 fitness: %0d\nIndividual 9 fitness: %0d\nIndividual 10 fitness: %0d\nIndividual 11 fitness: %0d\nIndividual 12 fitness: %0d\nIndividual 13 fitness: %0d\nIndividual 14 fitness: %0d\n",
                          32,vlTOPp->testbench__DOT__fitness
                          [0U],32,vlTOPp->testbench__DOT__fitness
                          [1U],32,vlTOPp->testbench__DOT__fitness
                          [2U],32,vlTOPp->testbench__DOT__fitness
                          [3U],32,vlTOPp->testbench__DOT__fitness
                          [4U],32,vlTOPp->testbench__DOT__fitness
                          [5U],32,vlTOPp->testbench__DOT__fitness
                          [6U],32,vlTOPp->testbench__DOT__fitness
                          [7U],32,vlTOPp->testbench__DOT__fitness
                          [8U],32,vlTOPp->testbench__DOT__fitness
                          [9U],32,vlTOPp->testbench__DOT__fitness
                          [0xaU],32,vlTOPp->testbench__DOT__fitness
                          [0xbU],32,vlTOPp->testbench__DOT__fitness
                          [0xcU],32,vlTOPp->testbench__DOT__fitness
                          [0xdU],32,vlTOPp->testbench__DOT__fitness
                          [0xeU]);
                VL_STOP_MT("tmp/testbench.sv", 111, "");
            }
            vlTOPp->testbench__DOT__dut_2__DOT__r3 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__b1)))));
            vlTOPp->testbench__DOT__dut_2__DOT__r3 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__dut_2__DOT__r3)))));
            vlTOPp->testbench__DOT____Vcellout__dut_2__y3 
                = vlTOPp->testbench__DOT__dut_2__DOT__r3;
            vlTOPp->testbench__DOT__dut_3__DOT__r3 
                = vlTOPp->testbench__DOT__b1;
            vlTOPp->testbench__DOT____Vcellout__dut_3__y3 
                = vlTOPp->testbench__DOT__dut_3__DOT__r3;
            vlTOPp->testbench__DOT__dut_4__DOT__r3 
                = vlTOPp->testbench__DOT__b1;
            vlTOPp->testbench__DOT__dut_4__DOT__r3 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__b1)))));
            vlTOPp->testbench__DOT__dut_4__DOT__r3 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__dut_4__DOT__r3)))));
            vlTOPp->testbench__DOT____Vcellout__dut_4__y3 
                = vlTOPp->testbench__DOT__dut_4__DOT__r3;
            vlTOPp->testbench__DOT__dut_5__DOT__r3 
                = vlTOPp->testbench__DOT__b1;
            vlTOPp->testbench__DOT____Vcellout__dut_5__y3 
                = vlTOPp->testbench__DOT__dut_5__DOT__r3;
            vlTOPp->testbench__DOT__dut_6__DOT__r3 
                = vlTOPp->testbench__DOT__b1;
            vlTOPp->testbench__DOT____Vcellout__dut_6__y3 
                = vlTOPp->testbench__DOT__dut_6__DOT__r3;
            vlTOPp->testbench__DOT__dut_7__DOT__r3 
                = vlTOPp->testbench__DOT__b1;
            vlTOPp->testbench__DOT____Vcellout__dut_7__y3 
                = vlTOPp->testbench__DOT__dut_7__DOT__r3;
            vlTOPp->testbench__DOT__dut_8__DOT__r3 
                = vlTOPp->testbench__DOT__b1;
            vlTOPp->testbench__DOT____Vcellout__dut_8__y3 
                = vlTOPp->testbench__DOT__dut_8__DOT__r3;
            vlTOPp->testbench__DOT__dut_11__DOT__r3 
                = vlTOPp->testbench__DOT__b1;
            vlTOPp->testbench__DOT____Vcellout__dut_11__y3 
                = vlTOPp->testbench__DOT__dut_11__DOT__r3;
            vlTOPp->testbench__DOT__dut_12__DOT__r3 
                = vlTOPp->testbench__DOT__b1;
            vlTOPp->testbench__DOT____Vcellout__dut_12__y3 
                = vlTOPp->testbench__DOT__dut_12__DOT__r3;
            vlTOPp->testbench__DOT__dut_13__DOT__r3 
                = vlTOPp->testbench__DOT__b1;
            vlTOPp->testbench__DOT____Vcellout__dut_13__y3 
                = vlTOPp->testbench__DOT__dut_13__DOT__r3;
            vlTOPp->testbench__DOT__dut_14__DOT__r3 
                = vlTOPp->testbench__DOT__b1;
            vlTOPp->testbench__DOT____Vcellout__dut_14__y3 
                = vlTOPp->testbench__DOT__dut_14__DOT__r3;
            vlTOPp->testbench__DOT__dut_3__DOT__r1 
                = vlTOPp->testbench__DOT__a1;
            vlTOPp->testbench__DOT____Vcellout__dut_3__y1 
                = vlTOPp->testbench__DOT__dut_3__DOT__r1;
            vlTOPp->testbench__DOT__dut_5__DOT__r1 
                = vlTOPp->testbench__DOT__a1;
            vlTOPp->testbench__DOT____Vcellout__dut_5__y1 
                = vlTOPp->testbench__DOT__dut_5__DOT__r1;
            vlTOPp->testbench__DOT__dut_7__DOT__r1 
                = vlTOPp->testbench__DOT__a1;
            vlTOPp->testbench__DOT____Vcellout__dut_7__y1 
                = vlTOPp->testbench__DOT__dut_7__DOT__r1;
            vlTOPp->testbench__DOT__dut_10__DOT__r1 
                = vlTOPp->testbench__DOT__a1;
            vlTOPp->testbench__DOT____Vcellout__dut_10__y1 
                = vlTOPp->testbench__DOT__dut_10__DOT__r1;
            vlTOPp->testbench__DOT__dut_12__DOT__r1 
                = vlTOPp->testbench__DOT__a1;
            vlTOPp->testbench__DOT____Vcellout__dut_12__y1 
                = vlTOPp->testbench__DOT__dut_12__DOT__r1;
            vlTOPp->testbench__DOT__dut_9__DOT__r1 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__a0)))));
            vlTOPp->testbench__DOT____Vcellout__dut_9__y1 
                = vlTOPp->testbench__DOT__dut_9__DOT__r1;
            vlTOPp->testbench__DOT__dut_14__DOT__r0 
                = vlTOPp->testbench__DOT__a0;
            vlTOPp->testbench__DOT__dut_14__DOT__r1 
                = vlTOPp->testbench__DOT__a1;
            vlTOPp->testbench__DOT__dut_14__DOT__r0 
                = ((IData)(vlTOPp->testbench__DOT__dut_14__DOT__r0) 
                   ^ (IData)(vlTOPp->testbench__DOT__dut_14__DOT__r1));
            vlTOPp->testbench__DOT__dut_14__DOT__r1 = 0U;
            vlTOPp->testbench__DOT____Vcellout__dut_14__y0 
                = vlTOPp->testbench__DOT__dut_14__DOT__r0;
            vlTOPp->testbench__DOT__dut_10__DOT__r0 
                = vlTOPp->testbench__DOT__a0;
            vlTOPp->testbench__DOT__dut_10__DOT__r3 
                = vlTOPp->testbench__DOT__b1;
            vlTOPp->testbench__DOT__dut_10__DOT__r3 
                = ((IData)(vlTOPp->testbench__DOT__dut_10__DOT__r3) 
                   | (IData)(vlTOPp->testbench__DOT__dut_10__DOT__r0));
            vlTOPp->testbench__DOT__dut_10__DOT__r0 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__b1)))));
            vlTOPp->testbench__DOT__dut_10__DOT__r0 
                = ((IData)(vlTOPp->testbench__DOT__dut_10__DOT__r0) 
                   | (IData)(vlTOPp->testbench__DOT__a1));
            vlTOPp->testbench__DOT____Vcellout__dut_10__y3 
                = vlTOPp->testbench__DOT__dut_10__DOT__r3;
            vlTOPp->testbench__DOT____Vcellout__dut_10__y0 
                = vlTOPp->testbench__DOT__dut_10__DOT__r0;
            vlTOPp->testbench__DOT__dut_10__DOT__r2 
                = vlTOPp->testbench__DOT__b0;
            vlTOPp->testbench__DOT____Vcellout__dut_10__y2 
                = vlTOPp->testbench__DOT__dut_10__DOT__r2;
            vlTOPp->testbench__DOT__dut_14__DOT__r2 
                = vlTOPp->testbench__DOT__b0;
            vlTOPp->testbench__DOT____Vcellout__dut_14__y2 
                = vlTOPp->testbench__DOT__dut_14__DOT__r2;
            vlTOPp->testbench__DOT__dut_2__DOT__r1 
                = vlTOPp->testbench__DOT__a1;
            vlTOPp->testbench__DOT__dut_2__DOT__r1 
                = ((IData)(vlTOPp->testbench__DOT__dut_2__DOT__r1) 
                   & (IData)(vlTOPp->testbench__DOT__b0));
            vlTOPp->testbench__DOT____Vcellout__dut_2__y1 
                = vlTOPp->testbench__DOT__dut_2__DOT__r1;
            vlTOPp->testbench__DOT__dut_4__DOT__r1 
                = vlTOPp->testbench__DOT__a1;
            vlTOPp->testbench__DOT__dut_4__DOT__r1 
                = ((IData)(vlTOPp->testbench__DOT__dut_4__DOT__r1) 
                   & (IData)(vlTOPp->testbench__DOT__b0));
            vlTOPp->testbench__DOT____Vcellout__dut_4__y1 
                = vlTOPp->testbench__DOT__dut_4__DOT__r1;
            vlTOPp->testbench__DOT__dut_2__DOT__r0 
                = vlTOPp->testbench__DOT__a0;
            vlTOPp->testbench__DOT__dut_2__DOT__r2 
                = vlTOPp->testbench__DOT__b0;
            vlTOPp->testbench__DOT__dut_2__DOT__r0 
                = ((IData)(vlTOPp->testbench__DOT__dut_2__DOT__r0) 
                   & (IData)(vlTOPp->testbench__DOT__dut_2__DOT__r2));
            vlTOPp->testbench__DOT__dut_2__DOT__r2 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__a0)))));
            vlTOPp->testbench__DOT____Vcellout__dut_2__y2 
                = vlTOPp->testbench__DOT__dut_2__DOT__r2;
            vlTOPp->testbench__DOT____Vcellout__dut_2__y0 
                = vlTOPp->testbench__DOT__dut_2__DOT__r0;
            vlTOPp->testbench__DOT__dut_3__DOT__r0 
                = vlTOPp->testbench__DOT__a0;
            vlTOPp->testbench__DOT__dut_3__DOT__r2 
                = vlTOPp->testbench__DOT__b0;
            vlTOPp->testbench__DOT__dut_3__DOT__r2 
                = ((IData)(vlTOPp->testbench__DOT__dut_3__DOT__r2) 
                   | (IData)(vlTOPp->testbench__DOT__dut_3__DOT__r0));
            vlTOPp->testbench__DOT____Vcellout__dut_3__y2 
                = vlTOPp->testbench__DOT__dut_3__DOT__r2;
            vlTOPp->testbench__DOT____Vcellout__dut_3__y0 
                = vlTOPp->testbench__DOT__dut_3__DOT__r0;
            vlTOPp->testbench__DOT__dut_4__DOT__r0 
                = vlTOPp->testbench__DOT__a0;
            vlTOPp->testbench__DOT__dut_4__DOT__r2 
                = vlTOPp->testbench__DOT__b0;
            vlTOPp->testbench__DOT__dut_4__DOT__r0 
                = ((IData)(vlTOPp->testbench__DOT__dut_4__DOT__r0) 
                   & (IData)(vlTOPp->testbench__DOT__dut_4__DOT__r2));
            vlTOPp->testbench__DOT__dut_4__DOT__r2 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__dut_4__DOT__r0)))));
            vlTOPp->testbench__DOT____Vcellout__dut_4__y2 
                = vlTOPp->testbench__DOT__dut_4__DOT__r2;
            vlTOPp->testbench__DOT____Vcellout__dut_4__y0 
                = vlTOPp->testbench__DOT__dut_4__DOT__r0;
            vlTOPp->testbench__DOT__dut_5__DOT__r0 
                = vlTOPp->testbench__DOT__a0;
            vlTOPp->testbench__DOT__dut_5__DOT__r2 
                = vlTOPp->testbench__DOT__b0;
            vlTOPp->testbench__DOT__dut_5__DOT__r2 
                = ((IData)(vlTOPp->testbench__DOT__dut_5__DOT__r2) 
                   | (IData)(vlTOPp->testbench__DOT__dut_5__DOT__r0));
            vlTOPp->testbench__DOT__dut_5__DOT__r0 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__b0)))));
            vlTOPp->testbench__DOT____Vcellout__dut_5__y2 
                = vlTOPp->testbench__DOT__dut_5__DOT__r2;
            vlTOPp->testbench__DOT____Vcellout__dut_5__y0 
                = vlTOPp->testbench__DOT__dut_5__DOT__r0;
            vlTOPp->testbench__DOT__dut_6__DOT__r1 
                = vlTOPp->testbench__DOT__a1;
            vlTOPp->testbench__DOT__dut_6__DOT__r2 
                = vlTOPp->testbench__DOT__b0;
            vlTOPp->testbench__DOT__dut_6__DOT__r1 
                = ((IData)(vlTOPp->testbench__DOT__dut_6__DOT__r1) 
                   | (IData)(vlTOPp->testbench__DOT__dut_6__DOT__r2));
            vlTOPp->testbench__DOT____Vcellout__dut_6__y2 
                = vlTOPp->testbench__DOT__dut_6__DOT__r2;
            vlTOPp->testbench__DOT____Vcellout__dut_6__y1 
                = vlTOPp->testbench__DOT__dut_6__DOT__r1;
            vlTOPp->testbench__DOT__dut_7__DOT__r0 
                = vlTOPp->testbench__DOT__a0;
            vlTOPp->testbench__DOT__dut_7__DOT__r2 
                = vlTOPp->testbench__DOT__b0;
            vlTOPp->testbench__DOT__dut_7__DOT__r2 
                = ((IData)(vlTOPp->testbench__DOT__dut_7__DOT__r2) 
                   | (IData)(vlTOPp->testbench__DOT__dut_7__DOT__r0));
            vlTOPp->testbench__DOT__dut_7__DOT__r0 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__b0)))));
            vlTOPp->testbench__DOT____Vcellout__dut_7__y2 
                = vlTOPp->testbench__DOT__dut_7__DOT__r2;
            vlTOPp->testbench__DOT____Vcellout__dut_7__y0 
                = vlTOPp->testbench__DOT__dut_7__DOT__r0;
            vlTOPp->testbench__DOT__dut_8__DOT__r1 
                = vlTOPp->testbench__DOT__a1;
            vlTOPp->testbench__DOT__dut_8__DOT__r2 
                = vlTOPp->testbench__DOT__b0;
            vlTOPp->testbench__DOT__dut_8__DOT__r1 
                = ((IData)(vlTOPp->testbench__DOT__dut_8__DOT__r1) 
                   | (IData)(vlTOPp->testbench__DOT__dut_8__DOT__r2));
            vlTOPp->testbench__DOT____Vcellout__dut_8__y2 
                = vlTOPp->testbench__DOT__dut_8__DOT__r2;
            vlTOPp->testbench__DOT____Vcellout__dut_8__y1 
                = vlTOPp->testbench__DOT__dut_8__DOT__r1;
            vlTOPp->testbench__DOT__dut_12__DOT__r0 
                = vlTOPp->testbench__DOT__a0;
            vlTOPp->testbench__DOT__dut_12__DOT__r2 
                = vlTOPp->testbench__DOT__b0;
            vlTOPp->testbench__DOT__dut_12__DOT__r2 
                = ((IData)(vlTOPp->testbench__DOT__dut_12__DOT__r2) 
                   | (IData)(vlTOPp->testbench__DOT__dut_12__DOT__r0));
            vlTOPp->testbench__DOT__dut_12__DOT__r0 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__b1)))));
            vlTOPp->testbench__DOT____Vcellout__dut_12__y2 
                = vlTOPp->testbench__DOT__dut_12__DOT__r2;
            vlTOPp->testbench__DOT____Vcellout__dut_12__y0 
                = vlTOPp->testbench__DOT__dut_12__DOT__r0;
            vlTOPp->testbench__DOT__dut_11__DOT__r0 
                = vlTOPp->testbench__DOT__a0;
            vlTOPp->testbench__DOT__dut_11__DOT__r2 
                = vlTOPp->testbench__DOT__b0;
            vlTOPp->testbench__DOT__dut_11__DOT__r2 
                = ((IData)(vlTOPp->testbench__DOT__dut_11__DOT__r2) 
                   | (IData)(vlTOPp->testbench__DOT__dut_11__DOT__r0));
            vlTOPp->testbench__DOT__dut_11__DOT__r1 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__dut_11__DOT__r2)))));
            vlTOPp->testbench__DOT__dut_11__DOT__r2 
                = ((IData)(vlTOPp->testbench__DOT__dut_11__DOT__r2) 
                   | (IData)(vlTOPp->testbench__DOT__dut_11__DOT__r0));
            vlTOPp->testbench__DOT____Vcellout__dut_11__y2 
                = vlTOPp->testbench__DOT__dut_11__DOT__r2;
            vlTOPp->testbench__DOT____Vcellout__dut_11__y1 
                = vlTOPp->testbench__DOT__dut_11__DOT__r1;
            vlTOPp->testbench__DOT____Vcellout__dut_11__y0 
                = vlTOPp->testbench__DOT__dut_11__DOT__r0;
            vlTOPp->testbench__DOT__dut_13__DOT__r1 
                = vlTOPp->testbench__DOT__a1;
            vlTOPp->testbench__DOT__dut_13__DOT__r2 
                = vlTOPp->testbench__DOT__b0;
            vlTOPp->testbench__DOT__dut_13__DOT__r0 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__a0)))));
            vlTOPp->testbench__DOT__dut_13__DOT__r1 
                = ((IData)(vlTOPp->testbench__DOT__dut_13__DOT__r1) 
                   | (IData)(vlTOPp->testbench__DOT__dut_13__DOT__r2));
            vlTOPp->testbench__DOT__dut_13__DOT__r2 
                = ((IData)(vlTOPp->testbench__DOT__dut_13__DOT__r2) 
                   | (IData)(vlTOPp->testbench__DOT__dut_13__DOT__r0));
            vlTOPp->testbench__DOT____Vcellout__dut_13__y2 
                = vlTOPp->testbench__DOT__dut_13__DOT__r2;
            vlTOPp->testbench__DOT____Vcellout__dut_13__y1 
                = vlTOPp->testbench__DOT__dut_13__DOT__r1;
            vlTOPp->testbench__DOT____Vcellout__dut_13__y0 
                = vlTOPp->testbench__DOT__dut_13__DOT__r0;
            vlTOPp->testbench__DOT__dut_9__DOT__r0 
                = vlTOPp->testbench__DOT__a0;
            vlTOPp->testbench__DOT__dut_9__DOT__r2 
                = vlTOPp->testbench__DOT__b0;
            vlTOPp->testbench__DOT__dut_9__DOT__r3 
                = vlTOPp->testbench__DOT__b1;
            vlTOPp->testbench__DOT__dut_9__DOT__r3 
                = ((IData)(vlTOPp->testbench__DOT__dut_9__DOT__r3) 
                   ^ (IData)(vlTOPp->testbench__DOT__b0));
            vlTOPp->testbench__DOT__dut_9__DOT__r0 
                = ((IData)(vlTOPp->testbench__DOT__dut_9__DOT__r0) 
                   & (IData)(vlTOPp->testbench__DOT__dut_9__DOT__r2));
            vlTOPp->testbench__DOT__dut_9__DOT__r2 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__a0)))));
            vlTOPp->testbench__DOT__dut_9__DOT__r3 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__a1)))));
            vlTOPp->testbench__DOT____Vcellout__dut_9__y3 
                = vlTOPp->testbench__DOT__dut_9__DOT__r3;
            vlTOPp->testbench__DOT____Vcellout__dut_9__y2 
                = vlTOPp->testbench__DOT__dut_9__DOT__r2;
            vlTOPp->testbench__DOT____Vcellout__dut_9__y0 
                = vlTOPp->testbench__DOT__dut_9__DOT__r0;
            vlTOPp->testbench__DOT__dut_0__DOT__r0 
                = vlTOPp->testbench__DOT__a0;
            vlTOPp->testbench__DOT__dut_0__DOT__r1 
                = vlTOPp->testbench__DOT__a1;
            vlTOPp->testbench__DOT__dut_0__DOT__r2 
                = vlTOPp->testbench__DOT__b0;
            vlTOPp->testbench__DOT__dut_0__DOT__r3 
                = vlTOPp->testbench__DOT__b1;
            vlTOPp->testbench__DOT__dut_0__DOT__r2 
                = ((IData)(vlTOPp->testbench__DOT__dut_0__DOT__r2) 
                   & (IData)(vlTOPp->testbench__DOT__b0));
            vlTOPp->testbench__DOT__dut_0__DOT__r0 
                = ((IData)(vlTOPp->testbench__DOT__dut_0__DOT__r0) 
                   & (IData)(vlTOPp->testbench__DOT__b1));
            vlTOPp->testbench__DOT__dut_0__DOT__r0 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__dut_0__DOT__r0)))));
            vlTOPp->testbench__DOT__dut_0__DOT__r2 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__dut_0__DOT__r0)))));
            vlTOPp->testbench__DOT__dut_0__DOT__r1 
                = ((IData)(vlTOPp->testbench__DOT__dut_0__DOT__r1) 
                   | (IData)(vlTOPp->testbench__DOT__dut_0__DOT__r2));
            vlTOPp->testbench__DOT__dut_0__DOT__r0 
                = ((IData)(vlTOPp->testbench__DOT__dut_0__DOT__r0) 
                   ^ (IData)(vlTOPp->testbench__DOT__dut_0__DOT__r3));
            vlTOPp->testbench__DOT__dut_0__DOT__r2 
                = ((IData)(vlTOPp->testbench__DOT__dut_0__DOT__r2) 
                   | (IData)(vlTOPp->testbench__DOT__dut_0__DOT__r3));
            vlTOPp->testbench__DOT__dut_0__DOT__r0 
                = ((IData)(vlTOPp->testbench__DOT__dut_0__DOT__r0) 
                   | (IData)(vlTOPp->testbench__DOT__a0));
            vlTOPp->testbench__DOT__dut_0__DOT__r2 
                = ((IData)(vlTOPp->testbench__DOT__dut_0__DOT__r2) 
                   ^ (IData)(vlTOPp->testbench__DOT__a1));
            vlTOPp->testbench__DOT____Vcellout__dut_0__y3 
                = vlTOPp->testbench__DOT__dut_0__DOT__r3;
            vlTOPp->testbench__DOT____Vcellout__dut_0__y2 
                = vlTOPp->testbench__DOT__dut_0__DOT__r2;
            vlTOPp->testbench__DOT____Vcellout__dut_0__y1 
                = vlTOPp->testbench__DOT__dut_0__DOT__r1;
            vlTOPp->testbench__DOT____Vcellout__dut_0__y0 
                = vlTOPp->testbench__DOT__dut_0__DOT__r0;
            vlTOPp->testbench__DOT__dut_1__DOT__r0 
                = vlTOPp->testbench__DOT__a0;
            vlTOPp->testbench__DOT__dut_1__DOT__r1 
                = vlTOPp->testbench__DOT__a1;
            vlTOPp->testbench__DOT__dut_1__DOT__r2 
                = vlTOPp->testbench__DOT__b0;
            vlTOPp->testbench__DOT__dut_1__DOT__r3 
                = vlTOPp->testbench__DOT__b1;
            vlTOPp->testbench__DOT__dut_1__DOT__r2 
                = ((IData)(vlTOPp->testbench__DOT__dut_1__DOT__r2) 
                   & (IData)(vlTOPp->testbench__DOT__b0));
            vlTOPp->testbench__DOT__dut_1__DOT__r0 
                = ((IData)(vlTOPp->testbench__DOT__dut_1__DOT__r0) 
                   & (IData)(vlTOPp->testbench__DOT__b1));
            vlTOPp->testbench__DOT__dut_1__DOT__r0 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__dut_1__DOT__r0)))));
            vlTOPp->testbench__DOT__dut_1__DOT__r2 
                = (1U & (~ (IData)((0U != (IData)(vlTOPp->testbench__DOT__dut_1__DOT__r0)))));
            vlTOPp->testbench__DOT__dut_1__DOT__r1 
                = ((IData)(vlTOPp->testbench__DOT__dut_1__DOT__r1) 
                   | (IData)(vlTOPp->testbench__DOT__dut_1__DOT__r2));
            vlTOPp->testbench__DOT__dut_1__DOT__r0 
                = ((IData)(vlTOPp->testbench__DOT__dut_1__DOT__r0) 
                   ^ (IData)(vlTOPp->testbench__DOT__dut_1__DOT__r3));
            vlTOPp->testbench__DOT__dut_1__DOT__r2 
                = ((IData)(vlTOPp->testbench__DOT__dut_1__DOT__r2) 
                   | (IData)(vlTOPp->testbench__DOT__dut_1__DOT__r3));
            vlTOPp->testbench__DOT__dut_1__DOT__r0 
                = ((IData)(vlTOPp->testbench__DOT__dut_1__DOT__r0) 
                   | (IData)(vlTOPp->testbench__DOT__a0));
            vlTOPp->testbench__DOT__dut_1__DOT__r2 
                = ((IData)(vlTOPp->testbench__DOT__dut_1__DOT__r2) 
                   ^ (IData)(vlTOPp->testbench__DOT__a1));
            vlTOPp->testbench__DOT____Vcellout__dut_1__y3 
                = vlTOPp->testbench__DOT__dut_1__DOT__r3;
            vlTOPp->testbench__DOT____Vcellout__dut_1__y2 
                = vlTOPp->testbench__DOT__dut_1__DOT__r2;
            vlTOPp->testbench__DOT____Vcellout__dut_1__y1 
                = vlTOPp->testbench__DOT__dut_1__DOT__r1;
            vlTOPp->testbench__DOT____Vcellout__dut_1__y0 
                = vlTOPp->testbench__DOT__dut_1__DOT__r0;
            vlTOPp->testbench__DOT__y3_current[2U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_2__y3;
            vlTOPp->testbench__DOT__y3_current[3U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_3__y3;
            vlTOPp->testbench__DOT__y3_current[4U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_4__y3;
            vlTOPp->testbench__DOT__y3_current[5U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_5__y3;
            vlTOPp->testbench__DOT__y3_current[6U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_6__y3;
            vlTOPp->testbench__DOT__y3_current[7U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_7__y3;
            vlTOPp->testbench__DOT__y3_current[8U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_8__y3;
            vlTOPp->testbench__DOT__y3_current[0xbU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_11__y3;
            vlTOPp->testbench__DOT__y3_current[0xcU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_12__y3;
            vlTOPp->testbench__DOT__y3_current[0xdU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_13__y3;
            vlTOPp->testbench__DOT__y3_current[0xeU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_14__y3;
            vlTOPp->testbench__DOT__y1_current[3U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_3__y1;
            vlTOPp->testbench__DOT__y1_current[5U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_5__y1;
            vlTOPp->testbench__DOT__y1_current[7U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_7__y1;
            vlTOPp->testbench__DOT__y1_current[0xaU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_10__y1;
            vlTOPp->testbench__DOT__y1_current[0xcU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_12__y1;
            vlTOPp->testbench__DOT__y1_current[9U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_9__y1;
            vlTOPp->testbench__DOT__y0_current[0xeU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_14__y0;
            vlTOPp->testbench__DOT__y3_current[0xaU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_10__y3;
            vlTOPp->testbench__DOT__y0_current[0xaU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_10__y0;
            vlTOPp->testbench__DOT__y2_current[0xaU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_10__y2;
            vlTOPp->testbench__DOT__y2_current[0xeU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_14__y2;
            vlTOPp->testbench__DOT__y1_current[2U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_2__y1;
            vlTOPp->testbench__DOT__y1_current[4U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_4__y1;
            vlTOPp->testbench__DOT__y2_current[2U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_2__y2;
            vlTOPp->testbench__DOT__y0_current[2U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_2__y0;
            vlTOPp->testbench__DOT__y2_current[3U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_3__y2;
            vlTOPp->testbench__DOT__y0_current[3U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_3__y0;
            vlTOPp->testbench__DOT__y2_current[4U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_4__y2;
            vlTOPp->testbench__DOT__y0_current[4U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_4__y0;
            vlTOPp->testbench__DOT__y2_current[5U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_5__y2;
            vlTOPp->testbench__DOT__y0_current[5U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_5__y0;
            vlTOPp->testbench__DOT__y2_current[6U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_6__y2;
            vlTOPp->testbench__DOT__y1_current[6U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_6__y1;
            vlTOPp->testbench__DOT__y2_current[7U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_7__y2;
            vlTOPp->testbench__DOT__y0_current[7U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_7__y0;
            vlTOPp->testbench__DOT__y2_current[8U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_8__y2;
            vlTOPp->testbench__DOT__y1_current[8U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_8__y1;
            vlTOPp->testbench__DOT__y2_current[0xcU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_12__y2;
            vlTOPp->testbench__DOT__y0_current[0xcU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_12__y0;
            vlTOPp->testbench__DOT__y2_current[0xbU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_11__y2;
            vlTOPp->testbench__DOT__y1_current[0xbU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_11__y1;
            vlTOPp->testbench__DOT__y0_current[0xbU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_11__y0;
            vlTOPp->testbench__DOT__y2_current[0xdU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_13__y2;
            vlTOPp->testbench__DOT__y1_current[0xdU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_13__y1;
            vlTOPp->testbench__DOT__y0_current[0xdU] 
                = vlTOPp->testbench__DOT____Vcellout__dut_13__y0;
            vlTOPp->testbench__DOT__y3_current[9U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_9__y3;
            vlTOPp->testbench__DOT__y2_current[9U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_9__y2;
            vlTOPp->testbench__DOT__y0_current[9U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_9__y0;
            vlTOPp->testbench__DOT__y3_current[0U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_0__y3;
            vlTOPp->testbench__DOT__y2_current[0U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_0__y2;
            vlTOPp->testbench__DOT__y1_current[0U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_0__y1;
            vlTOPp->testbench__DOT__y0_current[0U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_0__y0;
            vlTOPp->testbench__DOT__y3_current[1U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_1__y3;
            vlTOPp->testbench__DOT__y2_current[1U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_1__y2;
            vlTOPp->testbench__DOT__y1_current[1U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_1__y1;
            vlTOPp->testbench__DOT__y0_current[1U] 
                = vlTOPp->testbench__DOT____Vcellout__dut_1__y0;
        }
        
        void Vtestbench::_eval(Vtestbench__Syms* __restrict vlSymsp) {
            VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_eval\n"); );
            Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
            // Body
            vlTOPp->_combo__TOP__1(vlSymsp);
            if (((IData)(vlTOPp->__VinpClk__TOP__testbench__DOT__clk) 
                 & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__testbench__DOT__clk)))) {
                vlTOPp->_sequent__TOP__3(vlSymsp);
            }
            // Final
            vlTOPp->__Vclklast__TOP____VinpClk__TOP__testbench__DOT__clk 
                = vlTOPp->__VinpClk__TOP__testbench__DOT__clk;
            vlTOPp->__VinpClk__TOP__testbench__DOT__clk 
                = vlTOPp->testbench__DOT__clk;
        }
        
        VL_INLINE_OPT QData Vtestbench::_change_request(Vtestbench__Syms* __restrict vlSymsp) {
            VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_change_request\n"); );
            Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
            // Body
            return (vlTOPp->_change_request_1(vlSymsp));
        }
        
        VL_INLINE_OPT QData Vtestbench::_change_request_1(Vtestbench__Syms* __restrict vlSymsp) {
            VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_change_request_1\n"); );
            Vtestbench* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
            // Body
            // Change detection
            QData __req = false;  // Logically a bool
            __req |= ((vlTOPp->testbench__DOT__clk ^ vlTOPp->__Vchglast__TOP__testbench__DOT__clk));
            VL_DEBUG_IF( if(__req && ((vlTOPp->testbench__DOT__clk ^ vlTOPp->__Vchglast__TOP__testbench__DOT__clk))) VL_DBG_MSGF("        CHANGE: tmp/testbench.sv:31: testbench.clk\n"); );
            // Final
            vlTOPp->__Vchglast__TOP__testbench__DOT__clk 
                = vlTOPp->testbench__DOT__clk;
            return __req;
        }
        
#ifdef VL_DEBUG
        void Vtestbench::_eval_debug_assertions() {
            VL_DEBUG_IF(VL_DBG_MSGF("+    Vtestbench::_eval_debug_assertions\n"); );
        }
#endif  // VL_DEBUG
