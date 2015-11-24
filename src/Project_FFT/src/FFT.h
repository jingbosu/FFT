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

class FFT {
public:
	FFT();
	virtual ~FFT();

	vector<complex<float> > calculFFT(vector<float> data_in);
};

#endif /* FFT_H_ */
