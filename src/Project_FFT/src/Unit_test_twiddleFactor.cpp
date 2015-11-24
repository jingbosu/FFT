/*
 * Unit_test_twiddleFactor.cpp
 *
 *  Created on: 24 nov. 2015
 *      Author: su
 */


#include "TwiddleFactor.h"
#include <iostream>
using namespace std;

int main() {

	TwiddleFactor twiddleFactor;

	for(int i = 0; i<10; i++){
		cout<<"TW["<<i<<"] = "<<twiddleFactor.vec_comp[i]<<endl;
	}


	return 0;
}


