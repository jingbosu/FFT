/*
 * Unit_test_FFT.cpp
 *
 *  Created on: 24 nov. 2015
 *      Author: su
 */


#include "FFT.h"
#include <iostream>
using namespace std;

int main() {

	FFT cal;
	// define N 8 dans tw.h
	vector<float> tableau = {0, 15, 2, 30, 4, 57, 6, 7};
	vector<complex<float>> tableau_c;

	tableau_c = cal.calculFFT(tableau);
	for (int i = 0; i < tableau_c.size(); i++) {
		cout << "tab[" << i << "] = " << tableau_c[i] << endl;
	}
	return 0;
}


