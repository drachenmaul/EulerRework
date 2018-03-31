/*
 * misc.h
 *
 *  Created on: Mar 31, 2018
 *      Author: drachenmaul
 */

#ifndef MISC_H_
#define MISC_H_


unsigned SumDivisibleBy(unsigned n, unsigned limit); //Gibt Summe aller Zahlen unter limit die durch n teilbar sind zurück
unsigned long long CountRoutes(unsigned n); //Counts Routes through a nxn Square from top-left to bottom-right moving only right and down
unsigned SumOfDivisors(unsigned number);
unsigned SumOfProperDivisors(unsigned number);
unsigned Lettercount(int number); //Gibt Buchstabenanzahl für ausgeschriebenezahl zurück; 342 (three hundred and forty two) gibt 23 zurück
unsigned GetLength(int number);


#endif /* MISC_H_ */
