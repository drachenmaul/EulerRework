/*
 * primes.h
 *
 *  Created on: Mar 31, 2018
 *      Author: drachenmaul
 */

#ifndef PRIMES_H_
#define PRIMES_H_


#include <vector>

void initprimesieve(long long size, std::vector<bool> &liste);
void initprimelist(long long maxprime, std::vector<unsigned> &liste);
unsigned primefactors(unsigned long long number, std::vector<unsigned> &factors, std::vector<unsigned> &primes);



#endif /* PRIMES_H_ */
