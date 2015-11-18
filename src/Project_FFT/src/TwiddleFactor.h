/*
 * TwiddleFactor.h
 *
 *  Created on: 17 nov. 2015
 *      Author: su
 */

#ifndef TWIDDLEFACTOR_H_
#define TWIDDLEFACTOR_H_
#include <iostream>
#include <vector>
#include <complex>
using namespace std;

#define PI 3.14159
#define N 1024

class TwiddleFactor {
public:
	TwiddleFactor();
	virtual ~TwiddleFactor();
	vector<complex<float>> CalculFactors();
};

#endif /* TWIDDLEFACTOR_H_ */
