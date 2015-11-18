/*
 * TwiddleFactor.cpp
 *
 *  Created on: 17 nov. 2015
 *      Author: su
 */

#include "TwiddleFactor.h"


TwiddleFactor::TwiddleFactor() {
	// TODO Auto-generated constructor stub

}

TwiddleFactor::~TwiddleFactor() {
	// TODO Auto-generated destructor stub
}

vector<complex<float>> TwiddleFactor:: CalculFactors(){
	vector<complex<float>> v(512);
	complex<float> c;
	float r, theta_radians;
	r = 1;

	for(int i = 0; i< N/2; i++){
		theta_radians = -2*PI*i/N;
		c = polar(r, theta_radians);
		v[i] = c;
	}
	return v;
}
