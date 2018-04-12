/*
 * solutions.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: drachenmaul
 */


#include <iostream>
#include <cmath>
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


void euler4(){
	/*Find the largest palindrome made from the product of two 3-digit numbers.*/
	//speed improvement factor 193

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


	//Performance x17; reduced calls by 7.598.866.502



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
	//Slightly less efficient than original but scales a lot better
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
	//Improved score by 1.278.750.506, 2x faster than original
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

	//Performance increased by factor 110

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





void euler23(){
	/*	A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
	 * and perfect if the sum equals n.
	 * all integers greater than 28123 can be written as the sum of two abundant numbers
	 * Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
	 */



	//Performance increased x4, reduced calls by 6.108.994.945
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





void euler27(){
	/* n*n + an + b, where |a| < 1000 and |b| < 1000
	 *  Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
	 */
	//Speed up x4
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
	//performance x8.5

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







void euler41(){
	//What is the largest n-digit pandigital prime that exists?
	// Wichtig ist es zu erkennen, dass es keine 8,9 und 10 stelligen pandigitalen Primzahlen geben kann, da diese immer durch 3 Teilbar wäre (Summe 1-8/9/10 ist durch 3 teilbar)

	//Speed up by factor 5, improved callgrindscore by 15.000.000.000
	std::vector<unsigned> primes;
	initprimelist(1e7,primes);

	unsigned gpand;
	unsigned i;


	for(i=0, gpand=0 ; i<primes.size() ; i++){
		if(IsPandigital(primes[i])==1)
			if(primes[i]>gpand)
				gpand=primes[i];
	}

	std::cout << gpand << std::endl;
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



void euler48(){
	//Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
	//Performance improved by factor of 3000
  unsigned long long sum = 0;
  for (unsigned i = 1; i <= 1000; i++)
    {
      unsigned long long tmp = i;
      for (unsigned j = 1; j < i; j++)
        (tmp *= i) %= 10000000000;
      sum += tmp;
    }
  std::cout << sum % 10000000000 << std::endl;
}



void euler50(){
	//Which prime, below one-million, can be written as the sum of the most consecutive primes?
	//Twice as fast as original,
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
	//Reduced refs by ~120Million
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
	//Performance verdoppelt dank neuer IsPrime Funktion, reduced calls by ~50% um 465.871.876

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

	//Reduced callgrindscore by 9.5 Million, execution time reduced by factor of 2.5
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

















void euler145(){
	/*

Some positive integers n have the property that the sum [ n + reverse(n) ] consists entirely of odd (decimal) digits. For instance, 36 + 63 = 99 and 409 + 904 = 1313. We will call such numbers reversible; so 36, 63, 409, and 904 are reversible. Leading zeroes are not allowed in either n or reverse(n).

There are 120 reversible numbers below one-thousand.

How many reversible numbers are there below one-billion (10^9)?

	*/
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






void euler357(){
/*
	Consider the divisors of 30: 1,2,3,5,6,10,15,30.
	It can be seen that for every divisor d of 30, d+30/d is prime.

	Find the sum of all positive integers n not exceeding 100 000 000
	such that for every divisor d of n, d+n/d is prime.
*/
	//Runtime reduced by a third, reduced Ref calls by 15 Million
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









