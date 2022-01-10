// symbolclasses.h -*- C++ -*-
#ifndef _SYMBOLCLASSES_H_
#define _SYMBOLCLASSES_H_

#include <GE/ge.h>

#include <iostream>
#include <string>

using namespace std;

/************************************************************
// Grammar Specific Classes Begin.
*************************************************************/

class Statement : public AGSymbol {
public:
  Statement(const string, const SymbolType, const unsigned int = 0);
  Statement(const Statement&);
  ~Statement();
  virtual AGMapState updateSynthesisedAttributes(AGContext &context,
                                                 const int prodIndex,
                                                 AGLookUp &lookUp);
  virtual AGMapState updateInheritedAttributes(AGContext &context, 
												 const int prodIndex,
                                                 AGLookUp &lookUp);
  virtual const vector<bool> *getAllowedBCDValues() const;
  Statement &operator=(const Statement);
  bool operator==(const Statement&);
protected:
  vector<bool> i_allowedBCDValues;
};

class SwitchCase : public AGSymbol {
public:
  SwitchCase(const string, const SymbolType, const unsigned int = 0);
  SwitchCase(const SwitchCase&);
  ~SwitchCase();
  virtual AGMapState updateSynthesisedAttributes(AGContext &context,
                                                 const int prodIndex,
                                                 AGLookUp &lookUp);
  virtual AGMapState updateInheritedAttributes(AGContext &context, 
												 const int prodIndex,
                                                 AGLookUp &lookUp);
  virtual const vector<bool> *getValidProductionIndices() const;
  virtual const vector<bool> *getUsedValues() const;
  SwitchCase &operator=(const SwitchCase);
  bool operator==(const SwitchCase&);
protected:
  vector<bool> i_validProductionIndices;
  vector<bool> i_usedValues;
};

class DefaultCase : public AGSymbol {
public:
  DefaultCase(const string newValue, const SymbolType newType);
  DefaultCase(const DefaultCase&);
  ~DefaultCase();
  virtual AGMapState updateSynthesisedAttributes(AGContext &context,
                                                 const int prodIndex,
                                                 AGLookUp &lookUp);
  virtual AGMapState updateInheritedAttributes(AGContext &context, 
												 const int prodIndex,
                                                 AGLookUp &lookUp);
  DefaultCase &operator=(const DefaultCase);
  bool operator==(const DefaultCase&);
};

class BCDValue : public AGSymbol {
public:
  BCDValue(const string, const SymbolType, const unsigned int = 0);
  BCDValue(const BCDValue&);
  ~BCDValue();
  virtual AGMapState updateSynthesisedAttributes(AGContext &context,
                                                 const int prodIndex,
                                                 AGLookUp &lookUp);
  virtual AGMapState updateInheritedAttributes(AGContext &context, 
												 const int prodIndex,
                                                 AGLookUp &lookUp);
  unsigned int getValue() const;
  unsigned int setValue(unsigned int value);
  virtual const vector<bool> *getValidProductionIndices() const;
  BCDValue &operator=(const BCDValue);
  bool operator==(const BCDValue&);
protected:
  unsigned int s_value;
  vector<bool> i_validProductionIndices;
};

class SegValue : public AGSymbol {
public:
  SegValue(const string newValue, const SymbolType newType);
  SegValue(const SegValue&);
  ~SegValue();
  virtual AGMapState updateSynthesisedAttributes(AGContext &context,
                                                 const int prodIndex,
                                                 AGLookUp &lookUp);
  virtual AGMapState updateInheritedAttributes(AGContext &context, 
												 const int prodIndex,
                                                 AGLookUp &lookUp);
  SegValue &operator=(const SegValue);
  bool operator==(const SegValue&);
};

class Bit : public AGSymbol {
public:
  Bit(const string newValue, const SymbolType newType);
  Bit(const Bit&);
  ~Bit();
  virtual AGMapState updateSynthesisedAttributes(AGContext &context,
                                                 const int prodIndex,
                                                 AGLookUp &lookUp);
  virtual AGMapState updateInheritedAttributes(AGContext &context, 
												 const int prodIndex,
                                                 AGLookUp &lookUp);
  unsigned int getValue() const;
  unsigned int setValue(unsigned int value);
  Bit &operator=(const Bit);
  bool operator==(const Bit&);
protected:
  unsigned int s_value;
};

class BCDTerminal : public AGSymbol {
public:
  BCDTerminal(const string newValue, const SymbolType newType);
  BCDTerminal(const BCDTerminal&);
  ~BCDTerminal();
  virtual AGMapState updateSynthesisedAttributes(AGContext &context,
                                                 const int prodIndex,
                                                 AGLookUp &lookUp);
  virtual AGMapState updateInheritedAttributes(AGContext &context, 
												 const int prodIndex,
                                                 AGLookUp &lookUp);
  unsigned int getValue() const;
protected:
  unsigned int value;
};

class BitTerminal : public AGSymbol {
public:
  BitTerminal(const string newValue, const SymbolType newType);
  BitTerminal(const BitTerminal&);
  ~BitTerminal();
  virtual AGMapState updateSynthesisedAttributes(AGContext &context,
                                                 const int prodIndex,
                                                 AGLookUp &lookUp);
  virtual AGMapState updateInheritedAttributes(AGContext &context, 
												 const int prodIndex,
                                                 AGLookUp &lookUp);
  unsigned int getValue() const;
protected:
  unsigned int value;
};

#endif
