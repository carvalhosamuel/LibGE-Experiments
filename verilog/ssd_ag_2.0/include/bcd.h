// knapsack.h -*- C++ -*-
#ifndef _BCD_H_
#define _BCD_H_

using namespace std;

const unsigned int RANGE = 1; // How many values are valid
const unsigned int ENDRANGE = 1;
const int TERMINATOR = -1;

/************************************************************
// Helper Function
*************************************************************/
// Function prototype: This function generates a vector of
// items allowed at the specified state of derivation process.
// The state is reflected by a vector of previously used items.

const vector<int> *genAllowedItems(const vector<bool> *bcd_used);

#endif
