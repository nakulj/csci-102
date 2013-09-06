#include <iostream>

#include "search.h"
#include "sort.h"
#include "utility.h"

using namespace std;

int main()
{
	cout << "It runs!" << endl;
	
	/*
	Here's how you get a sorted vector of 100000 numbers (use this for searching).
	
	Make sure you use the same vector for all of your searches!
	*/
	vector<int> sortedList = getSortedVector(100000);
        int time= getCurrentTime();
        for(int i=0; i<1000; i++) {
            linearSearch(sortedList, -1);
        }
        time= getCurrentTime()-time;
        cout<<"Linear search took a total of "<<time<<" seconds";
	/*
	Here's how you get a random vector of 25000 numbers (use this for searching)
	
	Also make sure you use a new vector for each sorting run, otherwise you'll get weird results
	by sorting an already sorted vector!
	*/
	vector<int> randomList = getRandomVector(25000);
}


