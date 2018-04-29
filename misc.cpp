/*
 * misc.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: drachenmaul
 */



#include <iostream>
#include <cmath>
#include <vector>
#include "misc.h"
#include "primes.h"


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



unsigned SumOfDivisors(unsigned number){
	if(number==0)
		return 0;
	unsigned sum=1;
	unsigned p=2;
	unsigned j;
	while(p*p<=number && number > 1){
		if(number%p==0){
			j=p*p;
			number/=p;
			while(number%p==0){
				j*=p;
				number/=p;
			}
			sum*=(j-1);
			sum/=(p-1);
		}
		if(p==2)
			p++;
		else
			p+=2;
	}
	if(number>1)
		sum*=(number+1);
	return sum;
}




unsigned SumOfProperDivisors(unsigned number){
	return SumOfDivisors(number)-number;
}





unsigned Lettercount(int number){
	if (number > 1000 || number < -1000){
		std::cout << "Funktion Lettercount funktioniert nur bis einschließlich +-1000" << std::endl;
		return -1;
	}
	if(number == 1000)
		return 11;				//Wenn 1000 return "one thousand"
	unsigned bis19[] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8}; 	//Länge der Worte zero - nineteen
	unsigned zehner[] = {6, 6, 5, 5, 5, 7, 6, 6};										//Länge von twenty - ninety
	unsigned hu = 7;																		//Länge von "hundred"
	unsigned und = 3;																		//Länge von und
	unsigned sum=0;																		//rückgabe
	if(number < 0){		//wenn zahl negative füge ein
		sum+=5;			//"minus" hinzu
		number*=-1;		//und mache die Zahl anschließend positiv
	}

	unsigned length=GetLength(number);




	if (length == 3){		//100 bis max 999
		unsigned tmp=number;
		tmp/=100;			//Finde hunderter Stelle raus
		sum+=bis19[tmp];	//Füge Hunderterzahl hinzu
		sum+=hu;			//Füge "hundred" hinzu
		if(number % 100 == 0)//Füge "and" hinzu wenn kein gerader hunderter
			return sum;		//Wenn glatter hunderter sind wir fertig
		sum+=und;			//Füge "and" hinzu
		number-=tmp*100;	//entferne Hunderterstelle
		length--;			//Passe länge an
	}

	if(length == 2){		//Zahl von 10 bis 99
		if(number < 20)
			sum+=bis19[number];
		else{
			if(number%10 != 0)			//20 ist nicht twenty-zero
				sum+=bis19[number%10];	//Zahl >= 20, füge einerstelle hinzu
		number/=10;
		sum+=zehner[number-2];			//Füge 10er-Stelle hinzu
		}
	}
	if(length == 1)
		sum+=bis19[number];


	return sum;
}



unsigned GetLength(int NUMBER){
	unsigned length;
	if(NUMBER==0)
		return 1;
	for(length=0;NUMBER>0;length++){
		NUMBER/=10;
	}
	return length;
}



unsigned SumOfNumbers(unsigned number){//Allg bekannte Formel
	return number*(number+1)/2;
}
unsigned SumOfSquares(unsigned number){//Kann man herleiten und dann per Induktion beweisen, vgl Problem 6 Overview
	return number*(2*number+1)*(number+1)/6;
}






bool CanReverse(unsigned number){
	if(number%10==0)
		return false;
	else
		return true;
}

unsigned reverse(unsigned number){
    unsigned reversed = 0;
    while (number > 0) {
        reversed = 10 * reversed + number % 10;
        number /= 10;
    }
   return reversed;
}

bool OnlyOddDigits(unsigned number){
    while (number > 0) {
        if ((number % 10) % 2 == 0)
        	return false;
        number /= 10;
    }
    return true;
}


bool IsReversible(unsigned number){
	if(!CanReverse(number))
		return false;

	number+=reverse(number);
	if(OnlyOddDigits(number))
		return true;
	else
		return false;
}


bool IsPandigital0n(unsigned number){
	unsigned lang;
	unsigned bins[10]={0};
	for(lang=0 ; number>0 ; lang++){
		bins[number%10]++;
		number/=10;
	}
	for(unsigned i=0 ; i<lang ; i++){
		if(bins[i] != 1)
			return false;
	}


	return true;
}


bool IsPandigital(unsigned number){
	unsigned lang;
	lang=GetLength(number);
	if(lang>9)
		return false;
	unsigned bins[10]={0};
	for(unsigned i=0 ; i<lang ; i++){
		bins[number%10]++;
		number/=10;
	}
	for(unsigned i=1 ; i<=lang ; i++){
		if(bins[i] != 1)
			return false;
	}


	return true;
}



bool SameDigits(unsigned n1, unsigned n2){
	unsigned lang1, lang2;
	lang1=GetLength(n1);
	lang2=GetLength(n2);
	if(lang1!=lang2)
		return false;
	unsigned digits1[10]={0};
	unsigned digits2[10]={0};

	for(unsigned i=0 ; i<lang1 ; i++){
		digits1[n1%10]++;
		n1/=10;
	}


	for(unsigned i=0 ; i<lang1 ; i++){
			digits2[n2%10]++;
			n2/=10;
		}

	for(unsigned i=0 ; i<10 ; i++){
		if(digits1[i]!=digits2[i])
			return false;
	}

	return true;


}






unsigned QuadratSumme(unsigned number){
	unsigned summe=0;
	unsigned tmp;
	while(number>0){
		tmp=number%10;
		summe+= tmp*tmp;
		number/=10;
	}
	return summe;

}




bool IsPalindrom(unsigned number){
	return (number==reverse(number));
}


unsigned Faculty(unsigned number){
	unsigned fac=1;
	for(unsigned i=2 ; i <= number; i++)
		fac*=i;
	return fac;
}



bool IsBinaryPalindrom(unsigned number){
	unsigned reversed=0;
	unsigned tmp=number;
	while(tmp>0){
		reversed=2*reversed+(tmp%2);
		tmp/=2;
	}

	return (number==reversed);
}


bool IsBasePalindrom(unsigned number, unsigned base){
	unsigned reversed=0;
	unsigned tmp=number;
	while(tmp>0){
		reversed=base*reversed+(tmp%base);
		tmp/=base;
	}

	return (number==reversed);
}

bool IsBouncy(int number){
	if(number<101)
		return false;
	bool ascending=false;
	bool descending=false;
	int curr, last;
	curr=number%10;
	while(number>9){ //Schleife checkt immer einen Eintrag weiter länge deshalb hören wir bei number>9 auf und nicht number>0
		last=curr;
		number/=10;
		curr=number%10;
		if(curr<last)
			ascending=true;
		if(curr>last)
			descending=true;
		if(ascending && descending)
			return true;
	}

	return false;
}



unsigned long long Triangle(unsigned n){
	return (unsigned long long) n*(n+1)/2;
}



bool IsPentagonal(unsigned long long number){
	double result = (sqrt(1 + 24 * number) + 1.0) / 6.0;
	double intpart;
	return std::modf(result, &intpart) == 0.0;
}


unsigned long long Pentagon(unsigned n){
	return (unsigned long long)(n*(3*n-1))/2;
}



unsigned GCD(unsigned a, unsigned b){
	while( a != 0 && b != 0){
		if(a < b)
			b%=a;
		else
			a%=b;
	}
	if(a==0)
		return b;
	else
		return a;
}






unsigned EulerPhi(unsigned n, std::vector<unsigned> &primes){
	std::vector<unsigned> factors;
	unsigned anzahl=primefactors(n, factors, primes);
	double ret=n;
	for(unsigned i=0 ; i <anzahl ; i++){
		ret*=(1-1./factors[i]);
	}
	return ret;
}

bool IsTriangular(unsigned long long number){
	double result = (sqrt(1+8*number)-1)/2.;
	double intpart;
	return std::modf(result, &intpart) == 0.0;
}








unsigned long long BinomKoeff(int n, int r) {
    if(r > n / 2)
    	r = n - r; // because C(n, r) == C(n, n - r)
    unsigned long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}











