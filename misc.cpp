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
