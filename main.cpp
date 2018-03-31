/*
 * main.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: drachenmaul
 */

#include <ctime>
#include <iostream>





int main(){
	double start, stop;
	start=clock();

	//main code here


	stop=clock();

	std::cout << "Runtime: " << (stop - start)/CLOCKS_PER_SEC << "s" <<std::endl;
	std::cout << "Runtime: " << (stop - start) << " CPU Cycles" <<std::endl;



	return 0;
}
