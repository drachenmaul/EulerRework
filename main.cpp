/*
 * main.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: drachenmaul
 */

#include <ctime>
#include <iostream>
#include "solutions.h"

using namespace std;


int main(){
	double start, stop;
	start=clock();


	euler635();




	stop=clock();

	cout << "Runtime: " << (stop - start)/CLOCKS_PER_SEC << "s" <<endl;


	return 0;
}
