/*
 * solutions.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: drachenmaul
 */


#include <iostream>
#include <cmath>
#include <algorithm>
#include "misc.h"
#include "primes.h"


//Basecost to for main and time measurement: 2.182.036


void euler1(){
	//TASK: Find the sum of all the multiples of 3 or 5 below 1000.
	//basicly same speed

	unsigned limit=1000;

	std::cout << SumDivisibleBy(3,limit) + SumDivisibleBy(5,limit) - SumDivisibleBy(15,limit) << std::endl;
}


void euler2(){
	/*By considering the terms in the Fibonacci sequence whose values do not exceed four million,
	 find the sum of the even-valued terms.*/
	//Sequence starts with 1,2! Not 1,1
	//basicly same speed


	unsigned limit=4000000;
	unsigned sum=0;
	unsigned a=1;
	unsigned b=1;
	unsigned c=a+b;
	while(c<limit){ // 1, 1, 2, 3, 5, 8... you can see every 3rd number is even, so only add every third number
	   sum+=c;
	   a=b+c;
	   b=c+a;
	   c=a+b;
	}
	std::cout << sum << std::endl;
}



void euler3(){
	//What is the largest prime factor of the number 600851475143 ?
	//twice as fast

	unsigned long long number=600851475143;
	std::vector<unsigned> factors, primes;
	primefactors(number, factors,primes);

	std::cout << factors[factors.size()-1] << std::endl;


}


void euler4(){
	/*Find the largest palindrome made from the product of two 3-digit numbers.*/
	//speed improvement factor 142

	unsigned largestpal = 0;
	unsigned a=999;
	while(a>=100){
		unsigned b=999;
		while(b>=a){
			if(a*b<=largestpal)
				break;
			if(IsPalindrom(a*b))
				largestpal=a*b;
			b--;
		}
		a--;
	}
	std::cout << largestpal << std::endl;


}









void euler5(){
	/*What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?*/

	/*Die Schleife testet für alle Zahlen ob sie durch die Zahlen 1-20 restlos teilbar sind, findet es die erste solche Zahl
	 * bricht sie ab und das Ergebniss wird ausgegeben.*/


	//Performance x19



	unsigned ziel=20;	//erste zahl die durch 20 teilbar ist
	for(unsigned i = 11; i<21 ; i++){   //teste nur 11 aufwärts, da fälle 1-10 durch 11-20 abgedeckt werden
		if(ziel%i!=0){
			ziel+=20;	//wird immer um 20 erhöht damit teilbarkeit durch 20 gegeben ist
			i=3;
		}
	}
	std::cout << ziel << std::endl;
}















void euler6(){
	//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
	//basicly no difference
	unsigned limit=100;

	std::cout << SumOfNumbers(limit)*SumOfNumbers(limit)-SumOfSquares(limit) << std::endl;
}


void euler7(){
	//What is the 10 001st prime number?
	//Slower than original, but for larger primes it should be faster
	std::vector<unsigned> primes;
	initprimelist(105000,primes);

	std::cout << primes[10000] << std::endl;
}


void euler9(){
	/*A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.*/

	//Performance x5

	int a,b,c;


	for(a=1;a<1000;a++){
		for(b=a;b<1000;b++){
			c=1000-a-b;
				if(a*a+b*b==c*c){
					std::cout << a*b*c << std::endl;
					return;
				}
			}
		}

}




void euler10(){
	//Find the sum of all the primes below two million.
	//perf x37
	std::vector<unsigned> primes;
	unsigned limit = 2e6;
	initprimelist(limit,primes);
	unsigned long long sum = 0;

	for(unsigned i = 0 ; i < primes.size() ; i++){
		sum+=primes[i];
	}


	std::cout << sum << std::endl;
}



void euler12(){
	/*What is the value of the first triangle number to have over five hundred divisors?*/

	//Explanation see euler12 overview

	//Performance increased by factor 175

	std::vector<unsigned> primes;
	initprimelist(1000,primes);
	unsigned size=primes.size();

	unsigned n=3;
	unsigned Dn=2; //divisors per prime
	unsigned cnt=0;
	unsigned n1, Dn1, i, exponent;

	while( cnt <= 500){
		n++;
		n1=n;
		if(n1%2==0){
			n1/=2;
		}
		Dn1=1;
		for(i=0 ; i<size; i++){
			if(primes[i]*primes[i]>n1){
				Dn1*=2;
				break;
			}
			exponent=1;
			while(n1%primes[i]==0){
				exponent++;
				n1/=primes[i];
			}
			if(exponent > 1)
				Dn1*=exponent;
			if(n1==1)
				break;
		}
		cnt=Dn*Dn1;
		Dn=Dn1;
	}

	std::cout << n*(n-1)/2 << std::endl;

}










void euler14(){
	/*The following iterative sequence is defined for the set of positive integers:

n -> n/2 (n is even)
n -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?
	 * */


	//perf x2

	unsigned chainmax, chainl, chainlmax, n, i;

	for( i = 1 , chainmax = 0 , chainlmax = 0 ; i < 1e6 ; i++){
		for( n = i , chainl = 0 ; n!=1 ; chainl++){
			if(n%2 == 0)
				n/=2;
			else
				n=3*n+1;
		}
		if(chainl > chainlmax){
			chainmax = i;
			chainlmax = chainl;
		}
	}

	std::cout << chainmax << std::endl;


}

void euler15(){
	//How many routes(top left -> bottom right) are there through a 20×20 grid moving only right and down?
	//Lässt sich über Binomialkoeff lösen
	//basicly same speed

	unsigned n=20;
	std::cout << CountRoutes(n) << std::endl;
}


void euler16(){
	//What is the sum of the digits of the number 2^1000?

	//25% slower but no Bigints

	std::vector<unsigned> zahl;			//Hier werden die einzelnen Ziffern gespeichert
	zahl.push_back(1);					//Initialisiere mit 1

	for(unsigned i=0 ; i<1000 ; i++){
		for(unsigned j=0 ; j<zahl.size() ; j++)	//Multipliziere alles mit 2
			zahl[j]*=2;
		for(unsigned j=0 ; j<zahl.size()-1 ; j++)	//Gucke ob irgendwas größer als 10 ist, wenn ja übertrage ins nächste Feld
			if(zahl[j]>9){
				zahl[j+1]+=(zahl[j]/10);
				zahl[j]%=10;
			}
		if(zahl[zahl.size()-1]>9){ //Gucke ob letzter Eintrag größer als 10 ist wenn ja füge neues element an
			zahl.push_back(zahl[zahl.size()-1]/10);
			zahl[zahl.size()-2]%=10;

		}
	}
	unsigned summe,i;
	for(summe=0, i=0 ; i<zahl.size() ; i++) //Summiere alle Elemente auf
		summe+=zahl[i];


	std::cout << summe << std::endl;

}




void euler17(){
	/*

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
	 *
	 */
	int sum=0;
	for(int i=1; i <=1000;i++)
		sum+=Lettercount(i);

	std::cout << sum << std::endl;
}

void euler19(){
	//How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
	//Wird schon statistisch verteilt sein...
	std::cout << (12*100)/7 << std::endl;
}

void euler21(){
	/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
	 */

	//perf x79
	unsigned sum=0;
	for(unsigned a = 2 ; a<10000 ; a++){
		unsigned b = SumOfProperDivisors(a);
		if(a<b)
			if(SumOfProperDivisors(b)==a)
				sum+=a+b;
	}


	std::cout << sum << std::endl;
}





void euler23(){
	/*	A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
	 * and perfect if the sum equals n.
	 * all integers greater than 28123 can be written as the sum of two abundant numbers
	 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
	 */



	//perf x40
	unsigned i,j;
	std::vector<unsigned> abundantnbrs; //all abundant numbers go here
	std::vector<bool> numbers(28124,false);//here I check if numbers can be written as sum of abundant nmbrs
	unsigned sum;
	for(i=0;i<28124;i++){//find all abundant numbers and add them to the vector
		if(SumOfProperDivisors(i)>i){
			abundantnbrs.push_back(i);
		}
	}

	unsigned size = abundantnbrs.size();
	for(i=0;i<size;i++){
		for(j=i;j<size;j++){
			unsigned tmp = abundantnbrs[i]+abundantnbrs[j];
			if(tmp<28124)
					numbers[tmp]=true;
			else
				break;
		}
	}


	for(sum=0,i=0;i<28124;i++)
		if(numbers[i]==false)
			sum+=i;


	std::cout << sum << std::endl;
}

void euler24(){
	//What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?


	long long zahl=0;
	int ziffern[10]={0,1,2,3,4,5,6,7,8,9};
	for(unsigned i=1 ; i<1e6 ; i++){
		std::next_permutation(ziffern,ziffern+10);
	}

	for(unsigned i=0 ; i<10 ; i++)
		zahl+=(long long)ziffern[9-i]*pow(10,i);

	std::cout << zahl << std::endl;
}


void euler25(){
	//What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
	//Explanation: https://projecteuler.net/thread=25#1759

	//perf x20

	std::cout << round((999 * log(10) + log(5) / 2) / log((1+sqrt(5))/2)) << std::endl;


}





void euler27(){
	/* n*n + an + b, where |a| < 1000 and |b| < 1000
	 *  Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
	 */
	//Speed up x3
	std::vector<unsigned> primes;
	initprimelist(1000,primes);
	int size = primes.size();
	int a,b;
	int maxa,maxb;
	int primecount,maxprimecount;
	int n,i;


	for(maxprimecount=0,maxa=0,maxb=0,a=-999;a<1000;a++){
		//b must be positive and prime for n=0 to be prime
		for( i = 0 , b = primes[i] ; i<size ; i++ , b = primes[i] ){
			for(n=0,primecount=0;n==primecount;n++){
				if(IsPrime(n*n+a*n+b))
					primecount++;
			}
			if(primecount>maxprimecount){
				maxprimecount=primecount;
				maxa=a;
				maxb=b;
			}
		}
	}
	std::cout << "Produkt von " << maxa << " und " << maxb << " für maximale Primzahlen ist " << maxa*maxb << std::endl;
	std::cout << "Es enstehen " << maxprimecount << " Primzahlen!" << std::endl;
}


void euler28(){
	/*Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?*/
	//same perf
	int i,j;

	int sum;
	int summand;

	/*Per Hand hergeleitet, Grenze ergibt sich aus Gridgröße(ungerade)+1 geteilt durch 2*/
	for(sum=1,summand=1,i=1;i<501;i++){
		for(j=0;j<4;j++){
			summand+=i*2;
			sum+=summand;

		}
	}
	std::cout << sum << std::endl;


}





void euler30(){
	/*Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 1^4 + 6^4 + 3^4 + 4^4
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4

As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
	 * */

	//same perf

	/*Wichtigster Schritt: Erkennen, dass das maximum bei Faktor*9^5 liegt, Faktor
	 * ausrechnen und somit den maximalwert bestimmen*/
	int max=354295;
	int current;
	int sum;
	int i;
	int value;


	for(i=10,sum=0;i<max;i++){
		current=0;
		value=i;
		while(value>0){
			current+=pow(value%10,5);
			value/=10;
		}
		if(current==i)
			sum+=i;



	}

	std::cout << sum << std::endl;


}


void euler34(){
	/*145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
	 * */
	//performance x11

	int max=2600000; //7x9! is around 2.5mil which is much less than 9.999.999
	int i;
	int sum;
	int facsum;
	unsigned fac[10];

	for( i = 0 ; i < 10 ; i++)
		fac[i]=Faculty(i);


	for(i=10,sum=0;i<max;i++){
		unsigned tmp=i;
		facsum=0;
		while(tmp>0){
			facsum+=fac[tmp%10];
			tmp/=10;
		}
		if(facsum==i)
			sum+=facsum;
	}
	std::cout << sum << std::endl;
}

void euler35(){
	//A prime is circular if all rotations of the digits are themselves prime.
	//How many circular primes are there below one million?
	//performance improvement: x200

	std::vector<bool> prime;
	std::vector<unsigned> plist;
	initprimesieve(1e6,prime);
	primelistfromsieve(prime, plist);

	int circprimecount;
	int circ;
	int lang;
	int i,j;
	int check;


	//Starte circprimecount bei 2, da 2 und 5 übersprungen werden
	for( i=0, circprimecount=2 ; (unsigned)i<plist.size() ; i++){
		circ=plist[i];
		int tmp=circ;
		while(tmp>0){
			int digit=tmp%10;
			if(digit%2 == 0 || digit == 5)
				break;
			tmp/=10;
		}
		if(tmp!=0)
			continue;

		lang=GetLength(circ);
		for(j=0,check=0;j<lang;j++){
			circ+=(circ%10)*pow(10,lang);
			circ/=10;
			if(circ==-1)
				break;
			if(prime[circ]){
				check++;
			}
			if(check==lang){
				circprimecount++;
			}
		}
	}
	std::cout << "Es gibt " << circprimecount << " circular primes unter 1000000!" << std::endl;


}


void euler36(){
	/*Find the sum of all numbers, less than one million,
	 *  which are palindromic in base 10 and base 2.*/
	//Speed up x15

	int sum;
	unsigned i;

	for(i=1,sum=0;i<1000000;i+=2){
		if(IsPalindrom(i)){
			if(IsBinaryPalindrom(i)){
				sum+=i;
			}
		}
	}
	std::cout << sum << std::endl;


}



void euler37(){
	/*
	The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

	Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

	NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
	 */
	int trunccount, i, sum;

	for(i=11,trunccount=0,sum=0;trunccount<11;i++){
		if(IsPrime(i))
			if(Truncatable(i)){
				sum+=i;
				trunccount++;
				//std::cout << "Got one: " << i << std::endl;
			}
	}

	std::cout << "Sum of truncatable primes: " << sum << std::endl;




}






void euler39(){
	/*
	 * If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
	 * {20,48,52}, {24,45,51}, {30,40,50}
	 * For which value of p ≤ 1000, is the number of solutions maximised?
	 */

	//perf x6

	int a,b,p,max,curr,maxp;


	for(max=0, maxp=0, p=2;p<=1000;p+=2){ //All Perimeters of interger triangles are even
		for(curr=0, a=1;a<p-1;a++){
			for(b=a;b<=p-a-b;b++){
				if(a*a+b*b==(p-a-b)*(p-a-b)){
					curr++;
				}
			}

		}
		if(curr>max){
			maxp=p;
			max=curr;
		}
	}
	std::cout << maxp << std::endl;




}


void euler41(){
	//What is the largest n-digit pandigital prime that exists?
	// Wichtig ist es zu erkennen, dass es keine 8,9 und 10 stelligen pandigitalen Primzahlen geben kann, da diese immer durch 3 Teilbar wäre (Summe 1-8/9/10 ist durch 3 teilbar)

	//Speed up by factor 45, improved callgrindscore by 15.000.000.000
	std::vector<unsigned> primes;
	initprimelist(1e7,primes);

	unsigned gpand;
	unsigned i;


	for(i=0, gpand=0 ; i<primes.size() ; i++){
		if(IsPandigital(primes[i]))
			if(primes[i]>gpand)
				gpand=primes[i];
	}

	std::cout << gpand << std::endl;
}


void euler43(){
	/*

The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

    d2d3d4=406 is divisible by 2
    d3d4d5=063 is divisible by 3
    d4d5d6=635 is divisible by 5
    d5d6d7=357 is divisible by 7
    d6d7d8=572 is divisible by 11
    d7d8d9=728 is divisible by 13
    d8d9d10=289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.
	 */

	unsigned teiler[7]={17,13,11,7,5,3,2};
	unsigned counter;
	long long zahl;
	long long sum = 0;
	long long tmp=0;
	int ziffern[10]={1,0,2,3,4,5,6,7,8,9};
	do{
		zahl=0;
		for(unsigned i=0 ; i<10 ; i++)
			zahl+=(long long)ziffern[9-i]*pow(10,i);
		tmp=zahl;
		for(counter = 0 ; counter<7 ; counter++){
			if((tmp%1000)%teiler[counter]!=0)
				break;
			tmp/=10;
		}
		if(counter==7)
			sum+=zahl;
	}while(std::next_permutation(ziffern,ziffern+10));





	std::cout << sum << std::endl;


}


void euler44(){
	//Find the pair of pentagonal numbers, Pj and Pk, for which their sum and difference are pentagonal and D = |Pk − Pj| is minimised; what is the value of D?
	//perf x 86

	int diff=0;
	int pentagon[2501]; //Pentagonal numbers go here
	pentagon[0]=0;
	for(int i=1;i<2501;i++)	//initialise array
		pentagon[i]=Pentagon(i);
	std::vector<bool> ptest;	//lookuptable for pentagonal numbers
	ptest.resize(2*pentagon[2500]+1,false);
	int i,p;
	for(i=1, p=1 ; p<2*pentagon[2500]+1 ; i++, p=Pentagon(i)){
		ptest[p]=true;
	}


	for(int i = 1; i < 2501; i++)
		for(int j = i+1 ; j < 2501 ; j++){
			if(ptest[pentagon[i]+pentagon[j]] && ptest[pentagon[j]-pentagon[i]]){
					diff=pentagon[j]-pentagon[i];
					std::cout << i << " " << j << std::endl;
					goto endloop;	//found solution, break out of both loops
			}
		}
	endloop:
	std::cout << diff << std::endl;


	//TODO: Anständiges Abbruchkriterium
}





void euler45(){
	//It can be verified that T_285 = P_165 = H_143 = 40755.
	//Find the next triangle number that is also pentagonal and hexagonal.

	//perf x885

	int i;
	//All Triangle numbers are Hexagonal, only check pentagonal
	for(i = 286 ; !IsPentagonal(Triangle(i)) ;i++);

	std::cout << Triangle(i) << std::endl;


}




void euler46(){
	//What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
	//perf x1.5
	int test,prime,snumber,possible;
	for(possible=1,test=9;possible;test+=2){
		if(!IsPrime(test)){
			for(possible=0,prime=2;prime<test;prime=NextPrime(prime)){
				for(snumber=1;prime+2*snumber*snumber<=test;snumber++){
					if(prime+2*snumber*snumber==test)
						possible=1;
				}
			}
		}
	}

	std::cout << "Erster Fehlschlag bei " << test-2 << std::endl; //test-2 da letzte inkrementierung der for schleife rückgängig gemacht werden muss
}










void euler47(){
//Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
//perfx27


	std::vector<unsigned> primes;
	std::vector<unsigned> factors;
	initprimelist(150000,primes);

	int i, n;
	for( i = 0 , n = 0 ; n < 4 ; i++){
		if(primefactors(i,factors,primes)==4)
			n++;
		else
			n=0;
	}


	std::cout << i-4 << std::endl;
}



void euler48(){
	//Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
	//Performance improved by factor of 1351
  unsigned long long tmp, sum = 0;
  for (unsigned i = 1; i <= 1000; i++){
      tmp = i;
      for (unsigned j = 1; j < i; j++)
        (tmp *= i) %= 10000000000;	//Softwaregore
      sum += tmp;
    }
  std::cout << sum % 10000000000 << std::endl;
}



void euler49(){
	//The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.
	//There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.
	//What 12-digit number do you form by concatenating the three terms in this sequence?

	unsigned limit=1e4;				//Bis wo gucken
	std::vector<bool> ptest;		//primtester bis 10000
	initprimesieve(limit,ptest);
	std::vector<unsigned> primes;	//primliste bis 10000
	primelistfromsieve(ptest,primes);
	unsigned number=0;
	unsigned increase;
	unsigned i; 					//Zähler für primzahlen
	unsigned add1, add2;			//variablen für prim+increase und +2*increase
	for( i=0, number=primes[i] ; number<1000 ; i++, number=primes[i]); 		//finde erste 4 stellige primzahl

	for( ; i<primes.size()-1 ; number=primes[++i]){ 	//outer loop, increase prime whenever we reach end
		for(increase=2 , add1=number+increase , add2=add1+increase ; add2<limit ; increase+=2 , add1=number+increase , add2=add1+increase){		//increase immer gerade da prime+ungerade!=prime
			if( ptest[add1] && ptest[add2] ){
				if(SameDigits(number,add1) && SameDigits(number, add2)){
				std::cout << number << " mit increase: " << increase << std::endl;
				std::cout << number << add1 << add2 << std::endl;
				}
			}
		}
	}
}






void euler50(){
	//Which prime, below one-million, can be written as the sum of the most consecutive primes?
	//perf x2.6
	std::vector<unsigned> prime;
	initprimelist(500000,prime);

	unsigned i,j;
	unsigned current, highest, length, size;

	size = prime.size();

	for( i = 0, highest = 0, length = 0; i < size ; i++){
		current = 0;
		for( j = i ; j<size ; j++){
			current+=prime[j];
			if(current >= 1e6)
				break;
			if(IsPrime(current)){
				if(current > highest && (int)(j-i+1)>(int)length){
					length=j-i;
					highest=current;
				}
			}
		}
	}
	std::cout << "Primzahl: " << highest << std::endl;
	std::cout << "Kettenglieder: " << length << std::endl;

}

void euler52(){
	//Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
	//perf x3
	unsigned number;

	for(number=1;1;number++){
		if(SameDigits(number,2*number))
			if(SameDigits(number,3*number))
				if(SameDigits(number,4*number))
					if(SameDigits(number,5*number))
						if(SameDigits(number,6*number))
							break;
	}
	std::cout << number << std::endl;


}




void euler58(){
	/*

Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?
	 */
	//perf x2

	int i, layer, primes, total;
	int ecken[4];
	layer=0;
	primes=0;
	total=1;

	do{
		layer++;
		total+=4;
		ecken[0]=(2*layer+1)*(2*layer+1);
		for(i=1 ; i<4 ; i++){
			ecken[i]=ecken[i-1]-2*layer;
		}
		for(int i = 1; i<4 ; i++){
				if(IsPrime(ecken[i])){
					primes++;
				}
		}
	}while(100*primes>=10*total);


	std::cout << "Verhätlnis ist " << (double)primes/total << std::endl;
	std::cout << "Seitenlänge ist " << 2*layer+1 << std::endl;
}








void euler75(){
	/*

It turns out that 12 cm is the smallest length of wire that can be bent to form an integer sided right angle triangle in exactly one way, but there are many more examples.

12 cm: (3,4,5)
24 cm: (6,8,10)
30 cm: (5,12,13)
36 cm: (9,12,15)
40 cm: (8,15,17)
48 cm: (12,16,20)

In contrast, some lengths of wire, like 20 cm, cannot be bent to form an integer sided right angle triangle, and other lengths allow more than one solution to be found; for example, using 120 cm it is possible to form exactly three different integer sided right angle triangles.

120 cm: (30,40,50), (20,48,52), (24,45,51)

Given that L is the length of the wire, for how many values of L ≤ 1,500,000 can exactly one integer sided right angle triangle be formed?
	 */

	std::vector <int> zahlen(1500001,0);
	std::vector<long long> square(1500001);
	for( long long i = 0; i<=1500000;i++)
		square[i]=i*i;

	int a,b,i,res;
	int limit=1500000;
	for(a=1;a<limit;a++){
		for(b=a;b<limit-a-1;b++){
			long long tmp = square[a]+square[b];
			for(i=sqrt(tmp);i<limit-a-b;i++){
				if(tmp==square[i]){
					zahlen[a+b+i]++;
					break;
				}
				else if(tmp<square[i])
					break;
			}

		}
	}

	for(res=0,i=0;i<1500001;i++)
		if(zahlen[i]==1){
			res++;
		}

	//TODO: THIS ONE TAKE AN HOUR+
	std::cout << res << std::endl;



}








void euler87(){
	//How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?
	//Performance doubled if primelist not present, else roughly equal
	unsigned i, j, k;
	std::vector<bool> numbers(50000000, false);
	std::vector<unsigned> prime;
	initprimelist(7072,prime);
	long long num;
	unsigned size=prime.size();
	for(i=0;i<size;i++){
		num=0;
		for(j=0;j<size;j++){
			for(k=0;k<size;k++){
				num=(long long)prime[i]*prime[i];
				num+=(long long)prime[j]*prime[j]*prime[j];
				num+=(long long)prime[k]*prime[k]*prime[k]*prime[k];
				if(num<50000000)
					numbers[num]=true;
				else break;
			}
		}
	}

	for(i=0,num=0;i<50000000;i++)
		if(numbers[i]==true){
			num++;
		}


	std::cout << num << std::endl;

}



void euler92(){

/*

A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.

For example,

44 → 32 → 13 → 10 → 1 → 1
85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

How many starting numbers below ten million will arrive at 89?
 */

	//perf x4
	unsigned i,anzahl,qsumme;
	std::vector<unsigned> starter(1e7,0);
	std::vector<unsigned> buffer;



	for(i=1,anzahl=0;i<1e7;i++){
		if(starter[i]==89){
			anzahl++;
			continue;
		}else if(starter[i]==1){
			continue;
		}
		qsumme=i;
		buffer.clear();
		while(qsumme != 1 && qsumme!=89){
			buffer.push_back(qsumme);
			qsumme=QuadratSumme(qsumme);
			if(qsumme==89 || starter[qsumme]==89){
				anzahl++;
				for(unsigned j = 0 ; j < buffer.size() ; j++){
					starter[buffer[j]]=89;
				}
				break;
			}
			else if(qsumme==1 || starter[qsumme]==1){
				for(unsigned j = 0 ; j < buffer.size() ; j++){
					starter[buffer[j]]=1;
				}
				break;
			}
		}
	}
	std::cout << anzahl << " Anfangszahlen unter 10000000 enden mit 89." << std::endl;




}









void euler97(){
	//Find the last ten digits of the prime 28433*2^7830457+1
	//same perf
	long long unsigned a,b;
	a=1;
	for(b=0;b<7830457;b++)
	{
		a%=10000000000;
		a*=2;
	}
	b=28433*a+1;
	b%=10000000000;
	std::cout << b << std::endl;
}


void euler112(){
	/*

Working from left-to-right if no digit is exceeded by the digit to its left it is called an increasing number; for example, 134468.

Similarly if no digit is exceeded by the digit to its right it is called a decreasing number; for example, 66420.

We shall call a positive integer that is neither increasing nor decreasing a "bouncy" number; for example, 155349.

Clearly there cannot be any bouncy numbers below one-hundred, but just over half of the numbers below one-thousand (525) are bouncy. In fact, the least number for which the proportion of bouncy numbers first reaches 50% is 538.

Surprisingly, bouncy numbers become more and more common and by the time we reach 21780 the proportion of bouncy numbers is equal to 90%.

Find the least number for which the proportion of bouncy numbers is exactly 99%.
	 *
	 */
	//Performance x 2.5


	int i, bouncy;



	for(i=101, bouncy=0;bouncy*100!=99*(i-1);i++){ // i-1, da die Bedingung das verhältnis vor inkrementierung checken muss
		if(IsBouncy(i))
			bouncy++;
	}
	std::cout << i-1 << std::endl; //i-1 entfernt die letzte inkrementierung wieder


}




void euler145(){
	/*

Some positive integers n have the property that the sum [ n + reverse(n) ] consists entirely of odd (decimal) digits. For instance, 36 + 63 = 99 and 409 + 904 = 1313. We will call such numbers reversible; so 36, 63, 409, and 904 are reversible. Leading zeroes are not allowed in either n or reverse(n).

There are 120 reversible numbers below one-thousand.

How many reversible numbers are there below one-billion (10^9)?

	*/
	//perf x13
	//TODO: mehr optimierung als nur 90% der zahlen auslassen

	unsigned i;
	unsigned count=0;
	unsigned limit=1e8;  //Should be 1e9, butThere are no 9 digit reversible numbers

	for(i=0;i<limit;i++){
		if(IsReversible(i))
			count++;
	}

	std::cout << count << std::endl;



}



void euler187(){
	//A composite is a number containing at least two prime factors.
	//How many composite integers, n < 10^8, have precisely two, not necessarily distinct, prime factors?

	//perf x2
	unsigned i,j;
	unsigned limit=1e8;
	int count;
	std::vector<unsigned> plist;

	initprimelist(limit/2,plist);


	for( count=0 , i=0 ; i<plist.size() ; i++ ){
		for( j=i ; j<plist.size() ; j++){
			if((unsigned long long)plist[i]*plist[j]>=limit)
				break;
			count++;
		}
	}


	std::cout << "Zahlen mit 2 Primfaktoren unter " << limit << " : " << count << std::endl;


}


void euler206(){
/* Find the unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0,
where each “_” is a single digit. */

	//No noticable performance difference

	long long i, j;
	long long val;
	int ziffer[]= {0,9,8,7,6,5,4,3,2,1};

	for(i=1e9, j=0 ; j<10 ; i++){
		val=i*i;
		for(j=0 ; j<10 ; j++){
			if(val % 10 !=ziffer[j])
				break;
			val/=100;
		}
	}
	std::cout << i << std::endl;
}


void euler357(){
/*
	Consider the divisors of 30: 1,2,3,5,6,10,15,30.
	It can be seen that for every divisor d of 30, d+30/d is prime.

	Find the sum of all positive integers n not exceeding 100 000 000
	such that for every divisor d of n, d+n/d is prime.
*/
	//perf x 1.1
	unsigned long long summe, grenze;
	std::vector<bool> sieve;
	grenze=100000000;
	initprimesieve(grenze,sieve);
	// 1 is the only odd number where i+1 is prime
	summe=1;
    // scan only even numbers >= 2 of the form 2+4k
	for (unsigned int n = 2; n <= grenze; n += 4){
		if (!sieve[n+1])       // checke für teiler 1
			continue;
		if (!sieve[2 + n/2]) //und für Teiler 2,
			continue;
		bool valid = true;
		for (unsigned teiler = 3; teiler*teiler <= n; teiler++){ //und den Rest
			if (n % teiler != 0)
				continue;
			if (!sieve[teiler + n / teiler]){
				valid = false;
	            break;
			}
		}
		if (valid)
			summe += n;
	}
	std::cout << summe << std::endl;
}









