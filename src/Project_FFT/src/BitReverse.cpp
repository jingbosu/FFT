/*
 * BitReverse.cpp
 *
 *  Created on: 17 nov. 2015
 *      Author: su
 */

#include "BitReverse.h"

BitReverse::BitReverse() {
	// TODO Auto-generated constructor stub

}

BitReverse::~BitReverse() {
	// TODO Auto-generated destructor stub
}

vector<float> BitReverse::ReverseVector(vector<float> tableau){
	int size = tableau.size();
	vector<float> vectors(size);

	for(int i = 0; i<size;i++){
		string s, s_inv;
		int nb;
		s = ConvertIntToBinary(tableau[i]);
		s_inv = ReverseString(s);
		nb = ConvertBinaryToInt(s_inv);
		vectors[i] = nb;
	}

	return vectors;
}

string BitReverse::ConvertIntToBinary(int n){
	string r;
	while(n!=0){
		r = (n%2 == 0 ? "0":"1")+r;
		n/=2;
	}
	return r;
	//cout<<"R = "<<r<<endl;
}

string BitReverse::ReverseString(string s){
	string r;
	for(int i = s.length(); i>0;i--){
		r = r+s[i-1];
	}
	return r;
}

int BitReverse::ConvertBinaryToInt(string s){
	int r = 0;
	int size = s.length();
	for(int i = 0; i < size; i++){
		if (s[i]=='1') {
			r = 1 + 2*r;
		} else {
			r = 2*r;
		}
	}
	return r;
}
