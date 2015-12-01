/*
 * TwiddleFactor.cpp
 *
 *  Created on: 17 nov. 2015
 *      Author: su
 */

#include "TwiddleFactor.h"
#include "Sin.h"
#include "Cos.h"

TwiddleFactor::TwiddleFactor() {
	vec_comp = CalculFactors();
}

TwiddleFactor::~TwiddleFactor() {
	// TODO Auto-generated destructor stub
}

vector<ac_complex<ac_fixed<32, 16, true> > > TwiddleFactor::CalculFactors(){
	vector<ac_complex<ac_fixed<32, 16, true> > > v(512);
	ac_complex<ac_fixed<32, 16, true> > value;
	for(ac_int<32, true> i = 0; i< N/2; i++){
		value.set_r(value_cos[i]);
		value.set_i(value_sin[i]);
		v[i] = value;
	}
	return v;
}
