// AGLookUp.cpp -*- C++ -*-
#ifndef _AGLOOKUP_CPP_
#define _AGLOOKUP_CPP_

#include <string.h>

#include <iostream>
#include <typeinfo>

//#define DEBUG_LEVEL 2

#include "../include/symbolclasses.h"
#include "../include/bcd.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// This function generates an AGSymbol object of appropriate type. Implement it
// after finalising grammar.bnf and symbolclasses.h (and .cpp). The function is
// used when:
// (1)- a CFGrammar (or a derived) Object is constructed for the first time. At
//  this time we have to parse the strings to determine the corresponding
//  classes.
// (2)- an AGDerivationTree object is generated to map a genotype. At this time
//  we can use RTTI of the existing objects to generate a new object of
//  matching type. This can be made more efficient by recycling AGSymbol
//  objects instead of creating afresh every time.
AGSymbol *AGLookUp::findAGSymbol(const Symbol &agSym,
                 const unsigned int productions,
                 bool grammarMade) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'AGLookUp::findAGSymbol(const Symbol*, const Rule*, bool)' called\n";
  cerr << "Productions: " << productions << endl;
  cerr << "grammarMade: " << grammarMade << endl;
#endif
  const string sym = (const string)agSym;
  AGSymbol *ret_object = NULL;
  string errormessage;

  if (!grammarMade) { // Generating Grammar for the first time

  if (sym == "<statement>"){
    ret_object = new Statement(sym, agSym.getType());
  }
  else if (sym == "<switch-case>"){
    ret_object = new SwitchCase(sym, agSym.getType());
  }
  else if (sym == "<default-case>"){
    ret_object = new DefaultCase(sym, agSym.getType());
  }
  else if (sym == "<bcd-value>"){
    ret_object = new BCDValue(sym, agSym.getType());
  }
  else if (sym == "<seg-value>"){
    ret_object = new SegValue(sym, agSym.getType());
  }
  else if (sym == "<bit>"){
    ret_object = new Bit(sym, agSym.getType());
  }
  else if (sym == "4\'h0" || sym == "4\'h1" || sym == "4\'h2" ||
		   sym == "4\'h3" || sym == "4\'h4" || sym == "4\'h5" ||
		   sym == "4\'h6" || sym == "4\'h7" || sym == "4\'h8" ||
		   sym == "4\'h9" || sym == "4\'hA" || sym == "4\'hB" ||
		   sym == "4\'hC" || sym == "4\'hD" || sym == "4\'hE" ||
		   sym == "4\'hF" ){
    ret_object = new BCDTerminal(sym, agSym.getType());
  }
  else if (sym == "0" || sym == "1"){
    ret_object = new BitTerminal(sym, agSym.getType());
  }
  else {
	  ret_object = new GenericAGSymbol(sym, agSym.getType());
  }
  //else if (!sym.compare(0, strlen(" "), " ")) {
    //ret_object = new GenericAGSymbol(sym, agSym.getType());
  //}
  //else {
    //errormessage = "No matching class for the unexpected symbol read from "
           //"the grammar file: '";
  //}
  } 
  else {  // Grammar has already been made. We are using existing productions
      // to generate a tree/phenotype.
  if (typeid(agSym) == typeid(Statement)){
    ret_object = new Statement(sym, agSym.getType(), productions);
  }
  else if (typeid(agSym) == typeid(SwitchCase)){
    ret_object = new SwitchCase(sym, agSym.getType(), productions);
  }
  else if (typeid(agSym) == typeid(DefaultCase)){
    ret_object = new DefaultCase(sym, agSym.getType());
  }
  else if (typeid(agSym) == typeid(BCDValue)){
    ret_object = new BCDValue(sym, agSym.getType(), productions);
  }
  else if (typeid(agSym) == typeid(SegValue)){
    ret_object = new SegValue(sym, agSym.getType());
  }
  else if (typeid(agSym) == typeid(Bit)){
    ret_object = new Bit(sym, agSym.getType());
  }
  else if (typeid(agSym) == typeid(BCDTerminal)) {
    ret_object = new BCDTerminal(sym, agSym.getType());
  }
  else if (typeid(agSym) == typeid(BitTerminal)) {
    ret_object = new BitTerminal(sym, agSym.getType());
  }
  else {
    ret_object = new GenericAGSymbol(sym, agSym.getType());
  }
  //else if (typeid(agSym) == typeid(GenericAGSymbol)) {
    //ret_object = new GenericAGSymbol(sym, agSym.getType(), productions);
  //}
  //else {
    //errormessage = "Unexpected symbol read from the grammar file that could "
             //"not be downcast to any of the known symbolclasses: '";
  //}
  }

  if (!ret_object) {
  cerr << "agSym.getType() = " << agSym.getType() << endl;
  cerr << errormessage << sym << "'" << endl;
  exit(0);
  }

  return ret_object;
}

///////////////////////////////////////////////////////////////////////////////
// Destructor.
AGLookUp::~AGLookUp() {
#if (DEBUG_LEVEL >= 2)
  cerr << "'AGLookUp::~AGLookUp()' called\n";
#endif
}

#endif
