#include "utility.h"

#include <cstdlib>
#include <time.h>
#include <sys/time.h>
#include <stdexcept>
#include <vector>
#include <iostream>

/** A boolean indicating whether or not the random number generator
has been seeded yet. */
bool seeded = false;

/**
	Seed the random number generator with the current
	time.  This is how we can guarantee new random numbers
	each time the code is run.
	
	This function will only actually seed the random number
	generator once per application run.
	
	@pre None
	@post None
*/
void seed()
{
	//make sure we only seed once
	if(seeded)
	{
		return;
	}
	
	//grab the current time
	time_t seconds = 0;
	time(&seconds);
	
	//seed the random number generator
	srand((unsigned int) seconds);
	
	seeded = true;
}

int getRandomNumber(int start,int end)
{
	if(start > end)
	{
		throw std::out_of_range("start argument was greater than end argument.");
	}
	else if(start == end)
	{
		return(start);
	}
	
	seed();
	return rand()%(end-start+1) + start;
}

int getRandomNumber(int x)
{
	return(getRandomNumber(0,x));
}

double getCurrentTime()
{
	timeval tim;
    gettimeofday(&tim, NULL);
    double t = tim.tv_sec + (tim.tv_usec/1000000.0);
    return(t);
}

std::vector<int> getRandomVector(int size)
{
	std::vector<int> numbers;
	for(int i=0; i < size; i++)
	{
		numbers.push_back(getRandomNumber());
	}
	
	return(numbers);
}

std::vector<int> getSortedVector(int size)
{
	std::vector<int> numbers;
	for(int i=0; i < size; i++)
	{
		numbers.push_back(i);
	}
	
	return(numbers);
}
