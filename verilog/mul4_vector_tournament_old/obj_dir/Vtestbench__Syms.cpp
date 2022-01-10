// Verilated -*- SystemC -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtestbench__Syms.h"
#include "Vtestbench.h"



// FUNCTIONS
Vtestbench__Syms::~Vtestbench__Syms()
{
}

Vtestbench__Syms::Vtestbench__Syms(VerilatedContext* contextp, Vtestbench* topp, const char* namep)
    // Setup locals
    : VerilatedSyms{contextp}
    , __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
}
