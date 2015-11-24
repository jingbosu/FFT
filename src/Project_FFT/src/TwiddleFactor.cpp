/*
 * TwiddleFactor.cpp
 *
 *  Created on: 17 nov. 2015
 *      Author: su
 */

#include "TwiddleFactor.h"


TwiddleFactor::TwiddleFactor() {
	vec_comp = CalculFactors();
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
		theta_radians = -PI*i/256;
//		cout<<"----------------"<<endl;
//		cout<<"theta_radians("<<i<<") = "<<theta_radians<<endl;
//		cout<<"cos("<<theta_radians<<") = "<< cos(theta_radians)<<endl;
//		cout<<"sin("<<theta_radians<<") = "<< sin(theta_radians)<<endl;
		c = polar(r, theta_radians);
//		cout<<"c["<<i<<"] = "<<c<<endl;
		v[i] = c;
	}
	return v;
}
