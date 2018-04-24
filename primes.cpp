/*
 * primes.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: drachenmaul
 */


#include <iostream>
#include <cmath>
#include "primes.h"


void initprimesieve(unsigned size, std::vector<bool> &liste){
	liste.resize(size+1,true);
	liste[0]=false;
	liste[1]=false;

	for(unsigned j=4;j<=size;j+=2){
		liste[j]=false;

	}
	for(unsigned i=3;i*i<=size;i+=2){
		if(liste[i]==true){
			for(unsigned j=3*i;j<=size;j+=2*i){
				liste[j]=false;
			}
		}
	}
}


void initprimelist(unsigned maxprime, std::vector<unsigned> &liste){
	std::vector<bool> primes;
	initprimesieve(maxprime,primes);
	unsigned i;
	for( i=0 ; i <= maxprime ; i++){
		if(primes[i])
			liste.push_back(i);
	}
}


//This function writes the DISTINCT prime factors in the vector factors and returns the number of distinct prime factors
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



bool IsPrime(int number){
	if(number<2)
		return false;
	if(number==2)
		return true;
	if(number%2==0)
		return false;
	for(int n=3 ; n*n<=number ; n+=2){
		if(number%n==0)
			return false;
	}
	return true;
}


unsigned NextPrime(int number){
	if(number<2)		//Alles kleiner als 2 gibt 2 zurück
		return 2;
	number++;			//Wir wollen nicht number selbst zurück geben
	if(number%2==0)    //Stelle sicher dass Nummer ungerade ist
		number++;
	int n=3;
	while(n*n<=number){
		if(number%n==0){
			number+=2;
			n=3;
		}
		else
			n+=2;
	}
	return number;
}




void primelistfromsieve(std::vector<bool> sieve, std::vector<unsigned> &liste){
	unsigned i;
	unsigned size = sieve.size();
	for( i=0 ; i < size ; i++){
		if(sieve[i])
			liste.push_back(i);
	}
}

bool Truncatable(int prim){
	int tmp;


	//Teste auf wegnehmen von rechter Seite

	for(tmp=prim ; tmp>0 ; tmp/=10){
		if(!IsPrime(tmp))
			return false;
	}

	int i,l;
	for(l=0,tmp=prim;tmp!=0;tmp/=10,l++); //bestimme länge der zahl
	//Teste auf wegnehmen von linker Seite

	int teiler;
	for(teiler=pow(10,l-1),tmp=prim,i=0;i<l;i++,tmp%=teiler,teiler/=10){
		if(!IsPrime(tmp))
			return false;


	}


	return true;
}







