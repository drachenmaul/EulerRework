/*
 * solutions.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: drachenmaul
 */


#include <iostream>
#include "misc.h"
#include "primes.h"


//Basecost to for main and time measurement: 2.182.036


void euler1(){
	//TASK: Find the sum of all the multiples of 3 or 5 below 1000.
	//"Callgrindscore" improved by 46263

	unsigned limit=1000;

	std::cout << SumDivisibleBy(3,limit) + SumDivisibleBy(5,limit) - SumDivisibleBy(15,limit) << std::endl;
}


void euler2(){
	/*By considering the terms in the Fibonacci sequence whose values do not exceed four million,
	 find the sum of the even-valued terms.*/
	//Sequence starts with 1,2! Not 1,1
	//"Callgrindscore" improved by 13726


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
	//Worse by 426.836.935, however primefactors function very sophisticated
	//See improvement of problem 47

	unsigned long long number=600851475143;
	std::vector<unsigned> factors, primes;
	primefactors(number, factors,primes);

	std::cout << factors[factors.size()-1] << std::endl;


}




void euler7(){
	//What is the 10 001st prime number?
	//Slower than original, but for larger primes it should be faster
	std::vector<unsigned> primes;
	initprimelist(105000,primes);

	std::cout << primes[10000] << std::endl;
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


	//Improved by 1.305.853.335

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
	//Callgrind improvement of 57244

	unsigned n=20;
	std::cout << CountRoutes(n) << std::endl;
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



void euler21(){
	/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
	 */

	//Improvement of 654864845
	unsigned sum=0;
	for(unsigned a = 2 ; a<10000 ; a++){
		unsigned b = SumOfProperDivisors(a);
		if(a<b)
			if(SumOfProperDivisors(b)==a)
				sum+=a+b;
	}


	std::cout << sum << std::endl;





}













void euler47(){
//Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
//Improvement of 7.811.492.937, that's a factor 17 on runtime


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




















