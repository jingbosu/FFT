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
	vector<complex<float>> data_temp(N);

	for(int i=0; i<N;i++){
		data_temp[i] = (complex<float>) data_in[i];
	}
	/////////////////////Calculer bit reverse/////////////
	BitReverse bit;
	vector<float> data_reversed;
	data_reversed = bit.ReverseVector(data_in);

	///////////////////Calculer les coefficients//////////

	TwiddleFactor* tw = new TwiddleFactor();
	for (etage = 1; etage<=nb_etage; etage++){
		decalage_ligne = pow(2, etage-1);
		for (j = 0; j<=decalage_ligne-1; j++){
			p = pow(2, nb_etage-etage)*j;
			for (k = j; j<=N-1; pow(2,etage)){
				//Mais la relation entre data_in et data_out?
				data_final[k] = data_temp[k] + data_temp[k+decalage_ligne]*tw->vec_comp[p];
				data_final[k+decalage_ligne] = data_temp[k] - data_temp[k+decalage_ligne]*tw->vec_comp[p];
			}
		}

		for(int i=0; i<N;i++){
			data_temp[i] = data_final[i];
		}
	}
	return data_final;
}
