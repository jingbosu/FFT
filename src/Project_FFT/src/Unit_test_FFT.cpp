/*
 * Unit_test_FFT.cpp
 *
 *  Created on: 24 nov. 2015
 *      Author: su
 */


#include "FFT.h"
#include <iostream>
using namespace std;

ac_int<32, true> main() {

	FFT cal;
	// define N 8 dans tw.h
	vector<ac_fixed<32, 16, true> > tableau(8);
	tableau[0] = 0;
	tableau[1] = 15;
	tableau[2] = 2;
	tableau[3] = 30;
	tableau[4] = 4;
	tableau[5] = 57;
	tableau[6] = 6;
	tableau[7] = 7;
	
	// {0, 15, 2, 30, 4, 57, 6, 7};
	vector<ac_complex<ac_fixed<32, 16, true> > > tableau_c;

	tableau_c = cal.calculFFT(tableau);
	for (ac_int<32, true> i = 0; i < tableau_c.size(); i++) {
		cout << "tab[" << i << "] = " << tableau_c[i] << endl;
	}
	return 0;
}


