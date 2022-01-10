#include "Vtestbench.h"
  int sc_main(int argc, char** argv) {
      sc_set_time_resolution(1,SC_PS);
      Verilated::commandArgs(argc, argv);
      Vtestbench* top = new Vtestbench{"top"};
      while (!Verilated::gotFinish()) { sc_start(); }
      //sc_start();
      delete top;
      return 0;
  }
