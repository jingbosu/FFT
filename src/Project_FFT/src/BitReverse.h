/*
 * BitReverse.h
 *
 *  Created on: 17 nov. 2015
 *      Author: su
 */

#ifndef BITREVERSE_H_
#define BITREVERSE_H_

#include <vector>
#include <iostream>
#include <bitset>
#include <complex>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "ac_complex.h"
#include "TwiddleFactor.h"

using namespace std;

class BitReverse {
public:
	BitReverse();
	virtual ~BitReverse();

	vector<ac_complex<ac_fixed<32, 16, true> > > ReverseVector(vector<ac_fixed<32, 16, true> > tableau);
	string ConvertIntToBinary(ac_int<32, true> i, ac_int<32, true> size);
	string ReverseString(string s);
	ac_int<32, true> ConvertBinaryToInt(string s);
};

#endif /* BITREVERSE_H_ */
