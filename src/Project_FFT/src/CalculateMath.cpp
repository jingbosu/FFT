/*
 * CalculateMath.cpp
 *
 *  Created on: 1 déc. 2015
 *      Author: su
 */


#include <iostream>
#include <vector>
#include <complex>
#include "ac_fixed.h"
#include "ac_complex.h"
#define N 1024
#define PI 3.14

using namespace std;

void CalculateSin(){
		vector<ac_fixed<32, 16, true> > cos_value(512);
		vector<ac_fixed<32, 16, true> > sin_value(512);

		float  r, theta_radians;
		r = 1;

		complex<float> temp;

		for(int i = 0; i < N/2; i++){
			theta_radians = -(PI*i)/256;
			temp = polar(r, theta_radians);

			//cos_value[i] = temp.real();
			sin_value[i] = temp.imag();

			//cout << "cos_value[" << i << "] = " << cos_value[i] << endl;
			//cout << "sin_value[" << i << "] = " << sin_value[i] << endl;
			cout<<sin_value[i]<<","<<endl;
		}
}

int main(){
	CalculateSin();
	return 0;
}
