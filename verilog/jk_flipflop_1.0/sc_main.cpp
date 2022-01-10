#include "Vtestbench.h"
  int sc_main(int argc, char** argv) {
      Verilated::commandArgs(argc, argv);
      Vtestbench* top = new Vtestbench{"top"};
      while (!Verilated::gotFinish()) { sc_start(1, SC_NS); }
      delete top;
      return 0;
  }
