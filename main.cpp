/*
 * main.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: drachenmaul
 */

#include <ctime>
#include <iostream>
#include "solutions.h"



int main(){
	double start, stop;
	start=clock();



	euler48();


	stop=clock();

	std::cout << "Runtime: " << (stop - start)/CLOCKS_PER_SEC << "s" <<std::endl;



	return 0;
}
