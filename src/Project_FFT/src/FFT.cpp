/*
 * FFT.cpp
 *
 *  Created on: 17 nov. 2015
 *      Author: su
 */

#include "FFT.h"

FFT::FFT() {
	// TODO Auto-generated constructor stub

}

FFT::~FFT() {
	// TODO Auto-generated destructor stub
}

vector<complex<float>> FFT::calculFFT(vector<float> data_in){
	//calculer l'etage de papillon
	int nb_etage = log2(N);

	int decalage_ligne = 0;
	int etage, j, p, k;
	vector<complex<float>> data_final(N);

	/////////////////////Calculer bit reverse/////////////
	BitReverse bit;
	vector<float> data_reversed;
	data_reversed = bit.ReverseVector(data_in);

	///////////////////Calculer les coefficients//////////
	TwiddleFactor tw;
	vector<complex<float>> vec_comp;
	vec_comp = tw.CalculFactors();

	for (etage = 1; etage<=nb_etage; etage++){
		decalage_ligne = pow(2, etage-1);
		for (j = 0; j<=decalage_ligne-1; j++){
			p = pow(2, nb_etage-etage)*j;
			for (k = j; j<=N-1; pow(2,etage)){
				//Mais la relation entre data_in et data_out?
//				data_final(k) = data_final(k) + data_final(k+decalage_ligne)*vec_comp(p);
//				data_final(k+decalage_ligne) = data_final(k) - data_final(k+decalage_ligne)*vec_comp(p);
			}
		}
	}
	return data_final;
}

complex<float> multiplicationComplex(float f, complex<float> cp){
	complex<float> result;
	complex<float> temp;
	temp = (complex<float>)f;
	result = temp * cp;
	return result;
}

complex<float> additionComplex(float f, complex<float> cp){
	complex<float> result;
	complex<float> temp;
	temp = (complex<float>)f;
	result = temp + cp;
	return result;
}

complex<float> soustractionComplex(float f, complex<float> cp){
	complex<float> result;
	complex<float> temp;
	temp = (complex<float>)f;
	result = temp - cp;
	return result;
}
