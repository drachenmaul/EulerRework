/*
 * primes.h
 *
 *  Created on: Mar 31, 2018
 *      Author: drachenmaul
 */

#ifndef PRIMES_H_
#define PRIMES_H_


#include <vector>

void initprimesieve(unsigned size, std::vector<bool> &liste);
void initprimelist(unsigned maxprime, std::vector<unsigned> &liste);
unsigned primefactors(unsigned long long number, std::vector<unsigned> &factors, std::vector<unsigned> &primes);
bool IsPrime(int number);
unsigned NextPrime(int number);
void primelistfromsieve(std::vector<bool> sieve, std::vector<unsigned> &liste);
bool Truncatable(int prime);


#endif /* PRIMES_H_ */
