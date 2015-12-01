/*
 * BitReverse.cpp
 *
 *  Created on: 17 nov. 2015
 *      Author: su
 */

#include "BitReverse.h"
#include "ac_int.h"
BitReverse::BitReverse() {
	// TODO Auto-generated constructor stub
}

BitReverse::~BitReverse() {
	// TODO Auto-generated destructor stub
}

vector<ac_complex<ac_fixed<32, 16, true> > > BitReverse::ReverseVector(vector<ac_fixed<32, 16, true> > tableau){
	ac_int<32, true> size = tableau.size();
	cout<<size<<endl;
	if(size != N){
		cout << "You need to change value of N !";
		exit(EXIT_FAILURE);
	}
	vector<ac_complex<ac_fixed<32, 16, true> > > vectors(size);
	string s, s_inv;
	ac_int<32, true> nb;
	ac_int<32, true> t = ac::log2_ceil<N>::val;
	for (ac_int<32, true> i = 0; i < size; i++){
		s = ConvertIntToBinary(i, t);
		s_inv = ReverseString(s);
		nb = ConvertBinaryToInt(s_inv);
		vectors[i] = tableau[nb];
	}

	return vectors;
}

string BitReverse::ConvertIntToBinary(ac_int<32, true> n, ac_int<32, true> size){
	string r;
	while(n!=0){
		r = (n%2 == 0 ? '0':'1') + r;
		n /= 2;
	}

	while (r.size() < size) {
		r = '0' + r;
	}

	return r;
}

string BitReverse::ReverseString(string s){
	string r;
	for(ac_int<32, true> i = s.length(); i > 0; i--){
		r = r + s[i-1];
	}
	return r;
}

ac_int<32, true> BitReverse::ConvertBinaryToInt(string s){
	ac_int<32, true> r = 0;
	ac_int<32, true> size = s.length();
	for(ac_int<32, true> i = 0; i < size; i++){
		if (s[i]=='1') {
			r = 1 + 2*r;
		} else {
			r = 2*r;
		}
	}
	return r;
}
