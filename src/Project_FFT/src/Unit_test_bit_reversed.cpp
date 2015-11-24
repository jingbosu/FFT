/*
 * Unit_test_bit_reversed.cpp
 *
 *  Created on: 24 nov. 2015
 *      Author: su
 */

#include "BitReverse.h"
#include <iostream>
using namespace std;

int main() {

	BitReverse bitReverse;

	vector<float> tableau = {0, 15, 2, 30, 4, 57, 6, 7};
	vector<complex<float>> tableau_c;
	tableau_c = bitReverse.ReverseVector(tableau);

	for (int i = 0; i < tableau.size(); i++) {
		cout << "tab[" << i << "] = " << tableau_c[i] << endl;
	}

	return 0;
}
