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
#define N 4

void ReverseVector(ac_complex<ac_fixed<32, 16, true> > tableau[N], ac_complex<ac_fixed<32, 16, true> > vectors[N]){
	ac_int<32, true> k = 0;
	//int logN = log2(N);
	ac_int<32, true> logN = ac::log2_ceil<N>::val;
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

void calculAmplitude(ac_complex<ac_fixed<32, 16, true> >data_in[N], ac_fixed<32, 16, true> data_ampli[N]){
	int i;
	ac_fixed<32, 16, true> carre;
	double carre_double;
	for (i = 0; i < N; i++){
		carre = data_in[i].mag_sqr();
		carre_double = carre.to_double();
		carre_double = sqrt(carre_double);
		data_ampli[i] = (ac_fixed<32, 16, true>) carre_double;
	}
}

void calculFFT(ac_complex<ac_fixed<32, 16, true> > data_in[N], ac_complex<ac_fixed<32, 16, true> >data_final[N]){
	//calculer l'etage de papillon
	//ac_int<32, true> nb_etage = log2(N);
	ac_int<32, true> nb_etage = ac::log2_ceil<N>::val;

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

void binningData(ac_complex<ac_fixed<32, 16, true> > matrix_entry[N][N], ac_complex<ac_fixed<32, 16, true> > vector[N]){
	int i,j;
	for (i = 0; i < N; i++){
		ac_complex<ac_fixed<32, 16, true> > somme = 0;
		for (j = 0; j < N; j++){
			somme += matrix_entry[j][i];
		}
		vector[i] = somme;
	}
}

int main() {
	ac_complex<ac_fixed<32, 16, true> > tableau[N];
	ac_complex<ac_fixed<32, 16, true> > tableau_c[N];
	ac_complex<ac_fixed<32, 16, true> > matrix_entry[N][N];
	ac_fixed<32, 16, true> tableau_ampli[N];

	matrix_entry[0][0] = 0;
	matrix_entry[0][1] = 1;
	matrix_entry[0][2] = 2;
	matrix_entry[0][3] = 3;
	matrix_entry[1][0] = 4;
	matrix_entry[1][1] = 5;
	matrix_entry[1][2] = 6;
	matrix_entry[1][3] = 7;
	matrix_entry[2][0] = 8;
	matrix_entry[2][1] = 9;
	matrix_entry[2][2] = 10;
	matrix_entry[2][3] = 11;
	matrix_entry[3][0] = 12;
	matrix_entry[3][1] = 13;
	matrix_entry[3][2] = 14;
	matrix_entry[3][3] = 15;


	binningData(matrix_entry, tableau);
	cout << "--------------TAB------------"<<endl;
	for (ac_int<32, true> i = 0; i < N; i++) {
			cout << "tab[" << i << "] = " << tableau[i] << endl;
	}

	calculFFT(tableau, tableau_c);
	cout << "--------------TAB_C------------"<<endl;
	for (ac_int<32, true> i = 0; i < N; i++) {
		cout << "tab[" << i << "] = " << tableau_c[i] << endl;
	}

	calculAmplitude(tableau_c, tableau_ampli);
	cout << "--------------TAB_AMPLI------------"<<endl;
	for (ac_int<32, true> i = 0; i < N; i++) {
		cout << "tab[" << i << "] = " << tableau_ampli[i] << endl;
	}
	return 0;
}

