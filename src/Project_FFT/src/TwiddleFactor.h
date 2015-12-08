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
#include "ac_complex.h"
#include "Sin.h"
#include "Cos.h"

using namespace std;

#define PI 3.141592653589793
#define N 8

class TwiddleFactor {
public:
	TwiddleFactor();
	virtual ~TwiddleFactor();

	vector<ac_complex<ac_fixed<32, 16, true> > > CalculFactors();
	vector<ac_complex<ac_fixed<32, 16, true> > > vec_comp;
};

#endif /* TWIDDLEFACTOR_H_ */
