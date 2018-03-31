/*
 * misc.cpp
 *
 *  Created on: Mar 31, 2018
 *      Author: drachenmaul
 */




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
