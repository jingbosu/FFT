/*
 * FFT.cpp
 *
 *  Created on: 17 nov. 2015
 *      Author: su
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <complex>
#include "ac_complex.h"
#include "Sin.h"
#include "Cos.h"
using namespace std;
#define PI 3.141592653589793
#define N 8

void ReverseVector(ac_complex<ac_fixed<32, 16, true> > tableau[N], ac_complex<ac_fixed<32, 16, true> > vectors[N]){
	ac_int<32, true> k = 0;
	int logN = log2(N);
	for (ac_int<32, true> i = 0; i < N; i++) {
		for (int j = 0; j < logN; j++) {
			k[j] = i[logN - 1 - j];
		}
		vectors[i] = tableau[k];
		k = 0;
	}
}

void CalculFactors(ac_complex<ac_fixed<32, 16, true> > v[512]){
	ac_complex<ac_fixed<32, 16, true> > value;
	for(ac_int<32, true> i = 0; i< N/2; i++){
		value.set_r(value_cos[i]);
		value.set_i(value_sin[i]);
		v[i] = value;
	}
}

void calculFFT(ac_complex<ac_fixed<32, 16, true> > data_in[N], ac_complex<ac_fixed<32, 16, true> >data_final[N]){
	//calculer l'etage de papillon
	ac_int<32, true> nb_etage = log2(N);

	ac_int<32, true> decalage_ligne = 0;
	ac_int<32, true> etage, j, p, k, decale;

	/////////////////////Calculer bit reverse/////////////
	ac_complex<ac_fixed<32, 16, true> > data_reversed[N];
	ReverseVector(data_in, data_reversed);

	///////////////////Calculer les coefficients//////////
	ac_complex<ac_fixed<32, 16, true> > vec_comp[512];
	CalculFactors(vec_comp);
	for (etage = 1; etage <= nb_etage; etage++){
		decalage_ligne =  (1 << (etage-1));
		for (j = 0; j <= decalage_ligne-1; j++){
			p = j << (nb_etage-etage);
			decale = 1 << etage;
			for (k = j; k <= N-1; k += decale){
				data_final[k] = data_reversed[k] + data_reversed[k+decalage_ligne]*vec_comp[p];
				data_final[k+decalage_ligne] = data_reversed[k] - data_reversed[k+decalage_ligne]*vec_comp[p];
			}
		}

		for(int i=0; i<N;i++){
			data_reversed[i] = data_final[i];
		}
	}
}

int main() {

	// define N 8 dans tw.h
	ac_complex<ac_fixed<32, 16, true> > tableau[N];
	tableau[0] = 0;
	tableau[1] = 15;
	tableau[2] = 2;
	tableau[3] = 30;
	tableau[4] = 4;
	tableau[5] = 57;
	tableau[6] = 6;
	tableau[7] = 7;

	// {0, 15, 2, 30, 4, 57, 6, 7};
	ac_complex<ac_fixed<32, 16, true> > tableau_c[N];

	calculFFT(tableau, tableau_c);
	for (ac_int<32, true> i = 0; i < N; i++) {
		cout << "tab[" << i << "] = " << tableau_c[i] << endl;
	}
	return 0;
}

