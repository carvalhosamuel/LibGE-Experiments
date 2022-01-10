// symbolclasses.cpp -*- C++ -*-
#ifndef _SYMBOLCLASSES_CPP_
#define _SYMBOLCLASSES_CPP_

//#define DEBUG_LEVEL 2

#include "../include/symbolclasses.h"
#include "../include/bcd.h"

#include <GE/ge.h>
#include <string.h>

#include <iostream>
#include <typeinfo>


using namespace std;

vector<int> allowedBCDValues(RANGE, TERMINATOR);
int unusedValues[RANGE] = {TERMINATOR};

const vector<int> *genAllowedValues(const vector<bool> *bcd_used) {
#if (DEBUG_LEVEL >= 1)
  cerr << "'genAllowedItems(const vector<bool>*)' called\n";
  cerr << "bcd_used->size() = " << bcd_used->size() << endl;
#endif
  // Generate a list of used items
  unsigned int unused_values = 0;
  for (unsigned int value = 0; value < RANGE; value++) {
	  if (!((*bcd_used)[value])) { // If the value is not used
		  allowedBCDValues[unused_values++] = value;
	  }
	}

#if (DEBUG_LEVEL >= 1)
  cout << "used values: ";
  for (unsigned int w = 0; w < RANGE; w++)
    cout << (*bcd_used)[w] << " ";
  cout << endl;

    cout << "unused values: ";
    for (unsigned int w = 0; w < RANGE; w++)
      cout << allowedBCDValues[w] << " ";
    cout << endl;
#endif

  // Add the terminator value to the end of the vector if the
  // number of used items used is less than the number of items allowed
  if (unused_values < RANGE) {
    allowedBCDValues[unused_values] = TERMINATOR;
  }
  
#if (DEBUG_LEVEL >= 1)
  cout << "allowed values: ";
  for (unsigned int w = 0; w < RANGE; w++)
    cout << allowedBCDValues[w] << " ";
  cout << endl;
#endif

  return &allowedBCDValues;
}

/****************************************************************************
 * 			Methods for class: Statement
 *****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
// Constructor: passes on the arguments to superclass. rulePtr points to the
// Rule object for the non-terminal <S>.
Statement::Statement(const string newArray, const SymbolType newType, const unsigned int)
    : AGSymbol(newArray, newType) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'Statement::Statement(const string, SymbolType, const unsigned int)' called\n";
#endif

  i_allowedBCDValues.resize(RANGE);
  // Initially all items are allowed.
  for (unsigned int i = 0; i < RANGE; i++) {
    i_allowedBCDValues[i] = true;
  }
}

///////////////////////////////////////////////////////////////////////////////
// Copy constructor.
Statement::Statement(const Statement &copy) : AGSymbol(copy) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'Statement::Statement(const Statement&)' called\n";
#endif
  const vector<bool> *v_prods = copy.getAllowedBCDValues();
  unsigned int size = v_prods->size();
  if (i_allowedBCDValues.size() != size)
    i_allowedBCDValues.resize(size);
  for (unsigned int i = 0; i < size; i++)
    i_allowedBCDValues[i] = (*v_prods)[i];
}

///////////////////////////////////////////////////////////////////////////////
// Destructor.
Statement::~Statement() {
#if (DEBUG_LEVEL >= 2)
  cerr << "'Statement::~Statement()' called\n";
#endif
}

///////////////////////////////////////////////////////////////////////////////
// Empty Implementation
AGMapState Statement::updateInheritedAttributes(AGContext &context,
                                           const int prodIndex,
                                           AGLookUp &lookUp) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'Statement::updateInheritedAttributes(AGContext &, const int, "
          "AGLookUp&)' called\n";
#endif

  return PASS;
}

///////////////////////////////////////////////////////////////////////////////
// Empty Implementation
AGMapState Statement::updateSynthesisedAttributes(AGContext &context, const int prodIndex,
                                             AGLookUp &lookUp) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'Statement::updateSynthesisedAttributes(AGContext &context, const int, "
          "AGLookUp&)' called\n";
#endif

  return PASS;
}

//////////////////////////////////////////////////////////////////////////////
// Helps determining the value of valid productions for forward checking.
const vector<bool> *Statement::getAllowedBCDValues() const {
#if (DEBUG_LEVEL >= 2)
  cerr << "'S::getAllowedBCDValues() const' called\n";
#endif
  return &i_allowedBCDValues;
}

///////////////////////////////////////////////////////////////////////////////
// Copy newValue.
Statement &Statement::operator=(const Statement newValue) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'Statement& Statement::operator=(const Statement)' called\n";
#endif

  // Pass it on to the superclass.
  // Pass it on to the superclass.
  AGSymbol::operator=(newValue);
  const vector<bool> *v_prods = newValue.getAllowedBCDValues();
  unsigned int size = v_prods->size();
  if (i_allowedBCDValues.size() != size)
    i_allowedBCDValues.resize(size);
  for (unsigned int i = 0; i < size; i++)
    i_allowedBCDValues[i] = (*v_prods)[i];

  return *this;
}

/****************************************************************************
 * 			Methods for class: SwitchCase
 *****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
// Constructor: passes on the arguments to superclass.
SwitchCase::SwitchCase(const string newArray, const SymbolType newType,
     const unsigned int productions) : AGSymbol(newArray, newType) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'SwitchCase::SwitchCase(const string, SymbolType)' called\n";
#endif
  // add code to initialise:
  if (productions > 0) {
    i_validProductionIndices.resize(productions, false);
  }
  i_usedValues.resize(RANGE, false);
}

///////////////////////////////////////////////////////////////////////////////
// Copy constructor.
SwitchCase::SwitchCase(const SwitchCase &copy) : AGSymbol(copy) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'SwitchCase::SwitchCase(const Item&)' called\n";
#endif
  const vector<bool> *v_prods = copy.getValidProductionIndices();
  unsigned int size = v_prods->size();
  if (i_validProductionIndices.size() != size)
    i_validProductionIndices.resize(size);
  for (unsigned int i = 0; i < size; i++) {
    i_validProductionIndices[i] = (*v_prods)[i];
  }
  // reusing the same vector to copy another: i_usedItems;
  v_prods = copy.getUsedValues();
  for (unsigned i = 0; i < v_prods->size(); i++) {
    i_usedValues[i] = (*v_prods)[i];
  }
}

///////////////////////////////////////////////////////////////////////////////
// Destructor.
SwitchCase::~SwitchCase() {
#if (DEBUG_LEVEL >= 2)
  cerr << "'SwitchCase::~SwitchCase()' called\n";
#endif
}

///////////////////////////////////////////////////////////////////////////////
// This pertains to productions:
//	 <statement>		::= "switch(bcd.read()){\n"<switch-case><default-case>"\n}"
// 	 <switch-case>	::= "case "<bcd-value>":\nseg.write("<seg-value>");\n" | "case "<bcd-value>":\nseg.write("<seg-value>");\n" <switch-case>
// <K> at the right side, depends on both <I> and, <K> on the left side.
AGMapState SwitchCase::updateInheritedAttributes(AGContext &context,
                                           const int prodIndex,
                                           AGLookUp &lookUp) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'SwitchCase::updateInheritedAttributes(AGContext &context, const int "
          "prodIndex, AGLookUp& lookUp)' called\n";
#endif
  AGSymbol *data = context.getParent()->getData();
  const vector<int> *allowedValues = NULL;
  
  // Need to point to the second sibling on the left. Use an iterator
  // to do this
  AGTree::iterator bcd_value_iterator = context.getStartIndex();
  bcd_value_iterator++;
  
  if (typeid(*data) == typeid(Statement)) {
    // i_usedValues stays initialised to false.
    // but initialise i_validProductionIndices appropriately.
    // If forward checking is enabled
    if (getValidProductionIndices()) {
      allowedValues = genAllowedValues(getUsedValues());
    }
  } else if (typeid(*data) == typeid(SwitchCase) &&
             typeid(*(bcd_value_iterator->getData())) == typeid(BCDValue)) {
    SwitchCase *switchCase = static_cast<SwitchCase *>(data); // parent node
    BCDValue *bcdValue = static_cast<BCDValue *>(bcd_value_iterator->getData()); // left sibling node
    // update used items from the parent node
    const vector<bool> *usedValues = switchCase->getUsedValues();
    for (unsigned int i = 0; i < RANGE; i++) {
      i_usedValues[i] = (*usedValues)[i];
    }
    
    unsigned int temp = bcdValue->getValue();
    
    // update used items from the left sibling node
    if (bcdValue->getValue() != ENDRANGE) {
      i_usedValues[bcdValue->getValue()] = true;
      if (getValidProductionIndices()) {
        allowedValues = genAllowedValues(getUsedValues());
      }
    }
  } else {
    // If the cast fails, then it is an error. Check the grammar.
    cerr << "error: in call SwitchCase::updateInheritedAttributes(..arguments..): can "
            "not downcast appropriately'"
         << endl;
    cerr << "Parent = " << (*data)
         << " : left sibling (startIndex->getData()) = "
         << (*(bcd_value_iterator->getData())) << endl;
    exit(1);
  }

  // There are two rules: <K>::=<I> | <I><K>. We only want to allow the second
  //(recursive) rule if more than one items are eligible for selection.
  if (allowedValues) {
    for (unsigned int i = 0; i < allowedValues->size() && (i < 2) &&
                             (*allowedValues)[i] != TERMINATOR;
         i++)
      i_validProductionIndices[i] = true;
  }
  i_validProductionIndices[0] = true;
  // the non-recursive option is true in any case.

  return PASS;
}

///////////////////////////////////////////////////////////////////////////////
// This pertains to productions:
// <switch-case> ::= "case "<bcd-value>":\nseg.write("<seg-value>");\n" | "case "<bcd-value>":\nseg.write("<seg-value>");\n" <switch-case>
// However, nothing needs to be done, when forward checking is in place.
AGMapState SwitchCase::updateSynthesisedAttributes(AGContext &context, const int prodIndex,
                                             AGLookUp &lookUp) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'SwitchCase::updateSynthesisedAttributes(AGContext &context, const int, "
          "AGLookUp&)' called\n";
#endif

  return PASS;
}

///////////////////////////////////////////////////////////////////////////////
// Facilitates forward checking.
const vector<bool> *SwitchCase::getValidProductionIndices() const {
#if (DEBUG_LEVEL >= 2)
  cerr << "'SwitchCase::getValidProductionIndices()' called\n";
#endif
  return &i_validProductionIndices;
}

//////////////////////////////////////////////////////////////////////////////
// Helps determining the value of valid productions for forward checking.
const vector<bool> *SwitchCase::getUsedValues() const {
#if (DEBUG_LEVEL >= 2)
  cerr << "'SwitchCase::getUsedValues() const' called\n";
#endif
  return &i_usedValues;
}

///////////////////////////////////////////////////////////////////////////////
// Copy newValue.
SwitchCase &SwitchCase::operator=(const SwitchCase newValue) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'K& K::operator=(const K)' called\n";
#endif

  // Pass it on to the superclass.
  AGSymbol::operator=(newValue);
  const vector<bool> *productions = newValue.getValidProductionIndices();
  i_validProductionIndices.resize(productions->size());
  for (unsigned int c = 0; c < productions->size(); c++)
    i_validProductionIndices[c] = (*productions)[c];

  // reusing the same vector to copy another i_usedItems;
  productions = newValue.getUsedValues();
  for (unsigned c = 0; c < productions->size(); c++)
    i_usedValues[c] = (*productions)[c];
  return *this;
}

/****************************************************************************
 * 			Methods for class: DefaultCase
 *****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
// Constructor: passes on the arguments to superclass.
DefaultCase::DefaultCase(const string newValue, const SymbolType newType)
    : AGSymbol(newValue, newType) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'DefaultCase::DefaultCase(const string, SymbolType)' called\n";
#endif
}

///////////////////////////////////////////////////////////////////////////////
// Copy constructor.
DefaultCase::DefaultCase(const DefaultCase &copy) : AGSymbol(copy) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'DefaultCase::DefaultCase(const Item&)' called\n";
#endif
}

///////////////////////////////////////////////////////////////////////////////
// Destructor.
DefaultCase::~DefaultCase() {
#if (DEBUG_LEVEL >= 2)
  cerr << "'DefaultCase::~DefaultCase()' called\n";
#endif
}

///////////////////////////////////////////////////////////////////////////////
// Empty Implementation
AGMapState DefaultCase::updateInheritedAttributes(AGContext &context,
                                           const int prodIndex,
                                           AGLookUp &lookUp) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'DefaultCase::updateInheritedAttributes(AGContext &, const int, "
          "AGLookUp&)' called\n";
#endif

  return PASS;
}

///////////////////////////////////////////////////////////////////////////////
// <number>.i_value = <number>.i_value = <bit>1.i_value * 2 + ... + <bit>n-1.i_value
AGMapState DefaultCase::updateSynthesisedAttributes(AGContext &context, const int prodIndex,
                                             AGLookUp &lookUp) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'DefaultCase::updateSynthesisedAttributes(AGContext &context, const int, "
          "AGLookUp&)' called\n";
#endif

  return PASS;
}

///////////////////////////////////////////////////////////////////////////////
// Copy newValue.
DefaultCase &DefaultCase::operator=(const DefaultCase newValue) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'DefaultCase& DefaultCase::operator=(const DefaultCase)' called\n";
#endif

  return *this;
}

/****************************************************************************
 * 			Methods for class: BCDValue
 *****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
// Constructor: passes on the arguments to superclass.
BCDValue::BCDValue(const string newArray, const SymbolType newType,
     const unsigned int productions) : AGSymbol(newArray, newType) {

#if (DEBUG_LEVEL >= 2)
  cerr << "'BCDValue::BCDValue(const string, SymbolType)' called\n";
#endif

  s_value = -1;
  // add code to initialise:
  if (productions > 0) {
    if (productions == RANGE) {
      i_validProductionIndices.resize(productions, false);
      i_validProductionIndices[RANGE] = true;
      // The ending item is always eligible
    } else {
      cerr << "Grammar mismatches with problem specification:  RANGE="
           << (RANGE) << " #items in grammar=" << productions << endl;
      exit(0);
    }
  }
  
}

///////////////////////////////////////////////////////////////////////////////
// Copy constructor.
BCDValue::BCDValue(const BCDValue &copy) : AGSymbol(copy) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BCDValue::BCDValue(const BCDValue&)' called\n";
#endif
  s_value = copy.getValue();
  const vector<bool> *v_prods = copy.getValidProductionIndices();
  unsigned int size = v_prods->size();
  if (i_validProductionIndices.size() != size)
    i_validProductionIndices.resize(size);
  for (unsigned int i = 0; i < size; i++)
    i_validProductionIndices[i] = (*v_prods)[i];
}

///////////////////////////////////////////////////////////////////////////////
// Destructor.
BCDValue::~BCDValue() {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BCDValue::~BCDValue()' called\n";
#endif
}

///////////////////////////////////////////////////////////////////////////////
// This pertains to productions: 
// <switch-case>	::= "case "<bcd-value>":\nseg.write("<seg-value>");\n" | 
// "case "<bcd-value>":\nseg.write("<seg-value>");\n" <switch-case>. 
// In both these cases the inherited attributes of <bcd-value> only depend 
// upon the parent node of type <switch-case>.
AGMapState BCDValue::updateInheritedAttributes(AGContext &context,
                                           const int prodIndex,
                                           AGLookUp &lookUp) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BCDValue::updateInheritedAttributes(AGContext &context, const int "
          "prodIndex, AGLookUp& lookUp)' called\n";
#endif
  // Add code to update i_validProductionIndices from the usedItems list
  // of the parent Node which should be of type 'switch-case'

  AGSymbol *data = context.getParent()->getData();
  if (typeid(*data) != typeid(SwitchCase)) {
    // If the cast fails, then it is an error. Check the grammar.
    cerr << "error: in call BCDValue::updateInheritedAttributes(..arguments..): can "
            "not cast to 'SwitchCase*'"
         << endl;
    exit(1);
  }
  // If forward checking is enabled
  if (getValidProductionIndices()) {
    const vector<int> *allowedValues;
    SwitchCase *switchCase = static_cast<SwitchCase *>(data);
    allowedValues = genAllowedValues(switchCase->getUsedValues());

    unsigned int a_size = allowedValues->size();
    for (unsigned int i = 0; i < a_size && (*allowedValues)[i] != TERMINATOR;
         i++)
      i_validProductionIndices[(*allowedValues)[i]] = true;
    // Always true.
    i_validProductionIndices[RANGE] = true;
  }

  return PASS;
}

///////////////////////////////////////////////////////////////////////////////
//<bcd-value>		::= 4\'h0 | 4\'h1 | 4\'h2 | 4\'h3 | 4\'h4 | 4\'h5 | 4\'h6 | 4\'h7
//| 4\'h8 | 4\'h9 | 4\'hA | 4\'hB | 4\'hC | 4\'hD | 4\'hE | 4\'hF
AGMapState BCDValue::updateSynthesisedAttributes(AGContext &context, const int prodIndex,
                                             AGLookUp &lookUp) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BCDValue::updateSynthesisedAttributes(AGContext &context, const int, "
          "AGLookUp&)' called\n";
#endif

  // Check if child is correct data type
  AGSymbol *data;

  for(AGTree::iterator i = context.getStartIndex(); i < context.getEndIndex(); i++){
	  data = i->getData();
	  
	  if (typeid(*data) == typeid(BCDTerminal)) {
		  BCDTerminal *bcd_terminal = static_cast<BCDTerminal *>(data);
	  
		  s_value = bcd_terminal->getValue();
	  }
	  else if (typeid(*data) == typeid(GenericAGSymbol)){ // This is to catch the terminals without a class
		  // Do Nothing
	  }
	  else {
		cerr << "error: in call BCDValue::updateSynthesisedAttributes(..arguments..): "
			"can not cast to 'BCDTerminal*'"
			 << endl;
		exit(1);
	  }
	  
  }

  return PASS;
}

///////////////////////////////////////////////////////////////////////////////
// Returns a 0 indexed item number for this object. This helps to identify the
// item that this object encapsulates.
unsigned int BCDValue::getValue() const {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BCDValue::getValue()' called\n";
#endif
  return s_value;
}

unsigned int BCDValue::setValue(unsigned int value) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BCDValue::setValue()' called\n";
#endif
  s_value = value;
}

const vector<bool> *BCDValue::getValidProductionIndices() const {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BCDValue::getValidProductionIndices()' called\n";
#endif
  return &i_validProductionIndices;
}

///////////////////////////////////////////////////////////////////////////////
// Copy newValue.
BCDValue &BCDValue::operator=(const BCDValue newValue) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BCDValue& BCDValue::operator=(const BCDValue)' called\n";
#endif

  // Pass it on to the superclass.
  AGSymbol::operator=(newValue);
  s_value = newValue.getValue();
  return *this;
}

//////////////////////////////////////////////////////////////////////////////
// Item comparison operator.
bool BCDValue::operator==(const BCDValue &newSymbol){
#if (DEBUG_LEVEL >= 2)
        cerr << "'bool AGSymbol::operator==(const AGSymbol&)' called\n";
#endif

        return (AGSymbol::operator==(newSymbol) && newSymbol.getValue()==getValue());
}

/****************************************************************************
 * 			Methods for class: SegValue
 *****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
// Constructor: passes on the arguments to superclass.
SegValue::SegValue(const string newValue, const SymbolType newType)
    : AGSymbol(newValue, newType) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'SegValue::SegValue(const string, SymbolType)' called\n";
#endif
}

///////////////////////////////////////////////////////////////////////////////
// Copy constructor.
SegValue::SegValue(const SegValue &copy) : AGSymbol(copy) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'SegValue::SegValue(const Item&)' called\n";
#endif
}

///////////////////////////////////////////////////////////////////////////////
// Destructor.
SegValue::~SegValue() {
#if (DEBUG_LEVEL >= 2)
  cerr << "'SegValue::~SegValue()' called\n";
#endif
}

///////////////////////////////////////////////////////////////////////////////
// Empty Implementation
AGMapState SegValue::updateInheritedAttributes(AGContext &context,
                                           const int prodIndex,
                                           AGLookUp &lookUp) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'SegValue::updateInheritedAttributes(AGContext &, const int, "
          "AGLookUp&)' called\n";
#endif

  return PASS;
}

///////////////////////////////////////////////////////////////////////////////
// Empty Implementation
AGMapState SegValue::updateSynthesisedAttributes(AGContext &context, const int prodIndex,
                                             AGLookUp &lookUp) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'SegValue::updateSynthesisedAttributes(AGContext &context, const int, "
          "AGLookUp&)' called\n";
#endif

  return PASS;
}

///////////////////////////////////////////////////////////////////////////////
// Copy newValue.
SegValue &SegValue::operator=(const SegValue newValue) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'SegValue& SegValue::operator=(const SegValue)' called\n";
#endif
  return *this;
}

//////////////////////////////////////////////////////////////////////////////
// Item comparison operator.
bool SegValue::operator==(const SegValue &newSymbol){
#if (DEBUG_LEVEL >= 2)
        cerr << "'bool AGSymbol::operator==(const AGSymbol&)' called\n";
#endif

        return (AGSymbol::operator==(newSymbol));
}

/****************************************************************************
 * 			Methods for class: Bit
 *****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
// Constructor: passes on the arguments to superclass.
Bit::Bit(const string newValue, const SymbolType newType)
    : AGSymbol(newValue, newType) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'Bit::Bit(const string, SymbolType)' called\n";
#endif
}

///////////////////////////////////////////////////////////////////////////////
// Copy constructor.
Bit::Bit(const Bit &copy) : AGSymbol(copy) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'Bit::Bit(const Item&)' called\n";
#endif
  s_value = copy.getValue();
}

///////////////////////////////////////////////////////////////////////////////
// Destructor.
Bit::~Bit() {
#if (DEBUG_LEVEL >= 2)
  cerr << "'Bit::~Bit()' called\n";
#endif
}

///////////////////////////////////////////////////////////////////////////////
// Corresponds to the rule <number>.s_value = <bit>1.s_value * 2 + ... + <bit>n-1.s_value
AGMapState Bit::updateInheritedAttributes(AGContext &context,
                                           const int prodIndex,
                                           AGLookUp &lookUp) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'Bit::updateInheritedAttributes(AGContext &, const int, "
          "AGLookUp&)' called\n";
#endif

  return PASS;
}

///////////////////////////////////////////////////////////////////////////////
// Corresponds to the rule <bit> = 0 | 1
AGMapState Bit::updateSynthesisedAttributes(AGContext &context,
                                          const int prodIndex,
                                          AGLookUp &lookUp) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'Bit::updateSynthesisedAttributes(AGContext &context, const int, "
          "AGLookUp&)' called\n";
#endif

  // Check if child is correct data type
  AGSymbol *data = context.getStartIndex()->getData();
  if (typeid(*data) != typeid(BitTerminal)) {
    cerr << "error: in call Terminal::updateSynthesisedAttributes(..arguments..): "
            "can not cast to 'BitTerminal*'"
         << endl;
    exit(1);
  }

  BitTerminal *bit_terminal = static_cast<BitTerminal *>(data);
  s_value = bit_terminal->getValue();
  
  // Nothing to do
  
  return PASS;
}

///////////////////////////////////////////////////////////////////////////////
// Returns a 0 indexed item number for this object. This helps to identify the
// item that this object encapsulates.
unsigned int Bit::getValue() const {
#if (DEBUG_LEVEL >= 2)
  cerr << "'Bit::getValue()' called\n";
#endif
  return s_value;
}

unsigned int Bit::setValue(unsigned int value) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'Bit::setValue()' called\n";
#endif
  s_value = value;
}

///////////////////////////////////////////////////////////////////////////////
// Copy newValue.
Bit &Bit::operator=(const Bit newValue) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'Bit& Bit::operator=(const Bit)' called\n";
#endif

  // Pass it on to the superclass.
  AGSymbol::operator=(newValue);
  s_value = newValue.getValue();
  return *this;
}

//////////////////////////////////////////////////////////////////////////////
// Item comparison operator.
bool Bit::operator==(const Bit &newSymbol){
#if (DEBUG_LEVEL >= 2)
        cerr << "'bool AGSymbol::operator==(const AGSymbol&)' called\n";
#endif

        return (AGSymbol::operator==(newSymbol) && newSymbol.getValue()==getValue());
}

/****************************************************************************
 * 			Methods for class: BCDTerminal
 *****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
// Constructor: passes on the arguments to superclass.
BCDTerminal::BCDTerminal(const string newValue, const SymbolType newType)
    : AGSymbol(newValue, newType) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BCDTerminal::BCDTerminal(const string, SymbolType)' called\n";
#endif

  // Code to initialise Value.
  // Expected that symbols are specified as: n
  // where n is an integer between 0 and 1

  
  if (newValue  == "4\'h0"){
    value = 0x0;
  }
  else if (newValue  == "4\'h1"){
    value = 0x1;
  }
  else if (newValue  == "4\'h2"){
    value = 0x2;
  }
  else if (newValue  == "4\'h3"){
    value = 0x3;
  }
  else if (newValue  == "4\'h4"){
    value = 0x4;
  }
  else if (newValue  == "4\'h5"){
    value = 0x5;
  }
  else if (newValue  == "4\'h6"){
    value = 0x6;
  }
  else if (newValue  == "4\'h7"){
    value = 0x7;
  }
  else if (newValue  == "4\'h8"){
    value = 0x8;
  }
  else if (newValue  == "4\'h9"){
    value = 0x9;
  }
  else if (newValue  == "4\'hA"){
    value = 0xA;
  }
  else if (newValue  == "4\'hB"){
    value = 0xB;
  }
  else if (newValue  == "4\'hC"){
    value = 0xC;
  }
  else if (newValue  == "4\'hD"){
    value = 0xD;
  }
  else if (newValue  == "4\'hE"){
    value = 0xE;
  }
  else if (newValue  == "4\'hF"){
    value = 0xF;
  }
  else {
        cerr << "Error in value for BCDTerminal in Grammar file: '" << newValue
             << "'. Each bit should be written as: BCDTerminal(0) or BCDTerminal(1)" << endl;
        //exit(0);
  }
}

///////////////////////////////////////////////////////////////////////////////
// Copy constructor.
BCDTerminal::BCDTerminal(const BCDTerminal &copy) : AGSymbol(copy) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BCDTerminal::BCDTerminal(const BCDTerminal&)' called\n";
#endif
  value = copy.getValue();
}

///////////////////////////////////////////////////////////////////////////////
// Destructor.
BCDTerminal::~BCDTerminal() {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BCDTerminal::~BCDTerminal()' called\n";
#endif
}

///////////////////////////////////////////////////////////////////////////////
// Corresponds to the rule <bcd-value>	::= 0x0 | 0x1 | 0x2 | 0x3 | 0x4 | 0x5 | 
// 0x6 | 0x7 | 0x8 | 0x9 | 0xA | 0xB | 0xC | 0bD | 0bE | 0bF
AGMapState BCDTerminal::updateInheritedAttributes(AGContext &context,
                                           const int prodIndex,
                                           AGLookUp &lookUp) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BCDTerminal::updateInheritedAttributes(AGContext &, const int, "
          "AGLookUp&)' called\n";
#endif

  // Check if parent is correct data type
  AGSymbol *data = context.getParent()->getData();
  if (typeid(*data) != typeid(BCDValue)) {
    cerr << "error: in call BCDTerminal::updateInheritedAttributes(..arguments..): "
            "can not cast to 'BCDValue*'"
         << endl;
    exit(1);
  }

  BCDValue *bcd_value = static_cast<BCDValue *>(data);
  bcd_value->setValue(getValue());
  
#if (DEBUG_LEVEL >= 2)
  cerr << "Setting bit value to " << getValue() << "; Value of bit " << bcd_value->getValue() << endl;
#endif

  return PASS;
}

///////////////////////////////////////////////////////////////////////////////
// A default implementation; only returns success.
AGMapState BCDTerminal::updateSynthesisedAttributes(AGContext &context, const int prodIndex,
                                             AGLookUp &lookUp) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BCDTerminal::updateSynthesisedAttributes(AGContext &context, const int, "
          "AGLookUp&)' called\n";
#endif
  return PASS;
}

///////////////////////////////////////////////////////////////////////////////
// Returns a 0 indexed item number for this object. This helps to identify the
// item that this object encapsulates.
unsigned int BCDTerminal::getValue() const {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BCDTerminal::getValue()' called\n";
#endif
  return value;
}

/****************************************************************************
 * 			Methods for class: BitTerminal
 *****************************************************************************/

///////////////////////////////////////////////////////////////////////////////
// Constructor: passes on the arguments to superclass.
BitTerminal::BitTerminal(const string newValue, const SymbolType newType)
    : AGSymbol(newValue, newType) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BitTerminal::BitTerminal(const string, SymbolType)' called\n";
#endif

  // Code to initialise Value.
  // Expected that symbols are specified as: n
  // where n is an integer between 0 and 1

  
  if (newValue[0]  == '0'){
    value = 0;
  }
  else if (newValue[0]  == '1'){
    value = 1;
  }
  else {
        cerr << "Error in value for BitTerminal in Grammar file: '" << newValue
             << "'. Each bit should be written as: BitTerminal(0) or BitTerminal(1)" << endl;
        //exit(0);
  }
}

///////////////////////////////////////////////////////////////////////////////
// Copy constructor.
BitTerminal::BitTerminal(const BitTerminal &copy) : AGSymbol(copy) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BitTerminal::BitTerminal(const BitTerminal&)' called\n";
#endif
  value = copy.getValue();
}

///////////////////////////////////////////////////////////////////////////////
// Destructor.
BitTerminal::~BitTerminal() {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BitTerminal::~BitTerminal()' called\n";
#endif
}

///////////////////////////////////////////////////////////////////////////////
// Corresponds to the rule <bit> = 0 | 1
AGMapState BitTerminal::updateInheritedAttributes(AGContext &context,
                                           const int prodIndex,
                                           AGLookUp &lookUp) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BitTerminal::updateInheritedAttributes(AGContext &, const int, "
          "AGLookUp&)' called\n";
#endif

  // Check if parent is correct data type
  AGSymbol *data = context.getParent()->getData();
  if (typeid(*data) != typeid(Bit)) {
    cerr << "error: in call BitTerminal::updateInheritedAttributes(..arguments..): "
            "can not cast to 'Bit*'"
         << endl;
    exit(1);
  }

  Bit *bit = static_cast<Bit *>(data);
  bit->setValue(getValue());
  
#if (DEBUG_LEVEL >= 2)
  cerr << "Setting bit value to " << getValue() << "; Value of bit " << bcd_value->getValue() << endl;
#endif
  
  return PASS;
}

///////////////////////////////////////////////////////////////////////////////
// A default implementation; only returns success.
AGMapState BitTerminal::updateSynthesisedAttributes(AGContext &context, const int prodIndex,
                                             AGLookUp &lookUp) {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BitTerminal::updateSynthesisedAttributes(AGContext &context, const int, "
          "AGLookUp&)' called\n";
#endif
  return PASS;
}

///////////////////////////////////////////////////////////////////////////////
// Returns a 0 indexed item number for this object. This helps to identify the
// item that this object encapsulates.
unsigned int BitTerminal::getValue() const {
#if (DEBUG_LEVEL >= 2)
  cerr << "'BitTerminal::getValue()' called\n";
#endif
  return value;
}

#endif
