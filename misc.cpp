/*
 * misc.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: drachenmaul
 */




unsigned SumDivisibleBy(unsigned n, unsigned limit){ //Erklärung in Problem 1 Overview
	unsigned elements=(limit-1)/n;
	return n*(elements*(elements+1))/2;
}



unsigned long long CountRoutes(unsigned n){
	unsigned long long result=1;
	for(unsigned i=1 ; i<=n ; i++){
		result*=(n+i);
		result/=i;;
	}
	return result;
}
