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
using namespace std;

class BitReverse {
public:
	BitReverse();
	virtual ~BitReverse();

	vector<complex<float> > ReverseVector(vector<float> tableau);
	string ConvertIntToBinary(int i, int size);
	string ReverseString(string s);
	int ConvertBinaryToInt(string s);
};

#endif /* BITREVERSE_H_ */
