/*
 * primes.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: drachenmaul
 */


#include <iostream>
#include <cmath>
#include "primes.h"


void initprimesieve(long long size, std::vector<bool> &liste){
	liste.resize(size+1,true);
	liste[0]=false;
	liste[1]=false;
	for(long long i=2;i*i<=size;i++){
		if(liste[i]==true){
			for(int j=2;j*i<=size;j++){
				liste[i*j]=false;
			}
		}
	}
}


void initprimelist(long long maxprime, std::vector<unsigned> &liste){
	std::vector<bool> primes;
	initprimesieve(maxprime,primes);
	int i, j, n;
	for( i=0, n=0 ; i <= maxprime ; i++){
		if(primes[i])
			n++;
	}
	liste.resize(n);
	for( i=0, j=0 ; i<=maxprime ; i++){
		if(primes[i])
			liste[j++]=i;
	}
}


//This function writes the DISTINCT prime factors in the vector factors
unsigned primefactors(unsigned long long number, std::vector<unsigned> &factors, std::vector<unsigned> &primes){
	factors.clear();
	if(number==0)
		return 0;
	unsigned maxfactor;
	if(number%2==0){
		factors.push_back(2);
		number/=2;
		while(number%2==0){
			number/=2;
		}
	}

	maxfactor=sqrt(number);
	if(primes.size()==0 || (primes.back()<maxfactor))
		initprimelist(maxfactor, primes);

	for(int i=1; number > 1 && primes[i]<=maxfactor;i++){
		if(number%primes[i]==0){
			factors.push_back(primes[i]);
			number/=primes[i];
			while(number%primes[i]==0){
				number/=primes[i];
			}
		}
	}
	if(number!=1)
		factors.push_back(number);
	return factors.size();
}





