/*
 * misc.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: drachenmaul
 */



#include <iostream>
#include "misc.h"


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




















