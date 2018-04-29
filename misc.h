/*
 * misc.h
 *
 *  Created on: Mar 31, 2018
 *      Author: drachenmaul
 */

#ifndef MISC_H_
#define MISC_H_

#include <vector>


unsigned SumDivisibleBy(unsigned n, unsigned limit); //Gibt Summe aller Zahlen unter limit die durch n teilbar sind zurück
unsigned long long CountRoutes(unsigned n); //Counts Routes through a nxn Square from top-left to bottom-right moving only right and down
unsigned SumOfDivisors(unsigned number);
unsigned SumOfProperDivisors(unsigned number);
unsigned Lettercount(int number); //Gibt Buchstabenanzahl für ausgeschriebenezahl zurück; 342 (three hundred and forty two) gibt 23 zurück
unsigned GetLength(int number);
unsigned SumOfSquares(unsigned number); //Sum of square numbers till number
unsigned SumOfNumbers(unsigned number); //Sum of numbers till number
bool CanReverse(unsigned number); //checkt ob zahl in 0 endet
unsigned reverse(unsigned number);//dreht Zahl um
bool OnlyOddDigits(unsigned number);
bool IsReversible(unsigned number); //siehe roblem 145
bool IsPandigital(unsigned number);//1-n Pandigital
bool IsPandigital0n(unsigned number);//0-n Pandigital
bool SameDigits(unsigned n1, unsigned n2);
unsigned QuadratSumme(unsigned number); //Summe der Quadrate der Ziffern der Zahl
bool IsPalindrom(unsigned number);
unsigned Faculty(unsigned number);
bool IsBinaryPalindrom(unsigned number);
bool IsBasePalindrom(unsigned number, unsigned base);
bool IsBouncy(int number);
unsigned long long Triangle(unsigned n);	//Generates Triangle numbers
bool IsPentagonal(unsigned long long number);
unsigned long long Pentagon(unsigned n);
unsigned GCD(unsigned a, unsigned b);
unsigned EulerPhi(unsigned n, std::vector<unsigned> &primes);
bool IsTriangular(unsigned long long number);
unsigned long long BinomKoeff(int n, int r);


#endif /* MISC_H_ */
