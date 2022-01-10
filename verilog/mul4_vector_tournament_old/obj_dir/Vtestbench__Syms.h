// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTESTBENCH__SYMS_H_
#define VERILATED_VTESTBENCH__SYMS_H_  // guard

#include "systemc.h"
#include "verilated_sc.h"
#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vtestbench.h"

// SYMS CLASS
class Vtestbench__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vtestbench*                    TOPp;
    
    // CREATORS
    Vtestbench__Syms(VerilatedContext* contextp, Vtestbench* topp, const char* namep);
    ~Vtestbench__Syms();
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
