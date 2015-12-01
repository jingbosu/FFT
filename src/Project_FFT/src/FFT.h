/*
 * FFT.h
 *
 *  Created on: 17 nov. 2015
 *      Author: su
 */

#ifndef FFT_H_
#define FFT_H_

#include <iostream>
#include <cmath>
#include <vector>
#include <complex>
#include "BitReverse.h"
#include "TwiddleFactor.h"

using namespace std;
//float = ac_fixed<32, 16, true>
class FFT {
public:
	FFT();
	virtual ~FFT();

	vector<ac_complex<ac_fixed<32, 16, true> > > calculFFT(vector<ac_fixed<32, 16, true> > data_in);
};

#endif /* FFT_H_ */
