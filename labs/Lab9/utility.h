#ifndef UTILITY_H_
#define UTILITY_H_

#include <stdexcept>
#include <vector>
#include <iomanip>
#include <iostream>

/**
	Generate a random number between 0 and x.
*/
int getRandomNumber(int x=999);

/**
	Generate a random number between "start" and "end" (inclusive).
*/
int getRandomNumber(int start,int end);

/*
	Returns the current time as the number of seconds
	since 01/01/1970.
*/
double getCurrentTime();

/*
	Generate a vector full of random numbers.
*/
std::vector<int> getRandomVector(int size=50);

/*
	Generate a vector full of ordered numbers.
*/
std::vector<int> getSortedVector(int size=50);

/*
	Print out a vector with N digits per line.
*/
template <typename T>
void printVector(const std::vector<T>& numbers,int numbersPerLine=10)
{
	for(int i=0; i < numbers.size(); i++)
	{
		if((i % numbersPerLine) == 0 && i > 0)
		{
			std::cout << std::endl;
		}
		std::cout.width(4);
		std::cout << numbers.at(i) << " ";
	}
	std::cout << std::endl;
}

#endif
