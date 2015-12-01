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

vector<ac_complex<ac_fixed<32, 16, true> > > FFT::calculFFT(vector<ac_fixed<32, 16, true> > data_in){
	//calculer l'etage de papillon
	ac_int<32, true> nb_etage = log2(N);

	ac_int<32, true> decalage_ligne = 0;
	ac_int<32, true> etage, j, p, k, decale;
	vector<ac_complex<ac_fixed<32, 16, true> > > data_final(N);

	/////////////////////Calculer bit reverse/////////////
	BitReverse bit;
	vector<ac_complex<ac_fixed<32, 16, true> > > data_reversed;
	data_reversed = bit.ReverseVector(data_in);

	///////////////////Calculer les coefficients//////////
	TwiddleFactor* tw = new TwiddleFactor();
	for (etage = 1; etage <= nb_etage; etage++){
		decalage_ligne =  (1 << (etage-1));
		for (j = 0; j <= decalage_ligne-1; j++){
			p = j << (nb_etage-etage);
			decale = 1 << etage;
			for (k = j; k <= N-1; k += decale){
				data_final[k] = data_reversed[k] + data_reversed[k+decalage_ligne]*tw->vec_comp[p];
				data_final[k+decalage_ligne] = data_reversed[k] - data_reversed[k+decalage_ligne]*tw->vec_comp[p];
			}
		}

		for(int i=0; i<N;i++){
			data_reversed[i] = data_final[i];
		}
	}
	return data_final;
}
