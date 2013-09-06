#ifndef SEARCH_H_
#define SEARCH_H_

#include <vector>

/*
	Basic linear search algorithm.  Loops through all of the elements
	in "list" to see if any of them are equal to "value".  If "value" is
	found, its index in the list is returned.  Otherwise -1 is returned.
*/
template <typename T>
bool linearSearch(const std::vector<T>& list,const T& value)
{
	for(int i=0; i < list.size(); i++)
	{
		//break out if we find the value we wanted
		if(list[i] == value)
		{
			return(true);
		}
	}
	
	//couldn't find the value
	return(false);
}

/*
	Basic binary search to see if "value" exists in "list".
	
	Start off by looking at the middle element in the list. If it's
	what you were looking for, you're done.  Otherwise figure out which
	half of the list the value you're looking for should be in and repeat
	the search on that subset of the list.  Continue until you either find the
	value you want or you're out of values to examine.  If "value" is
	found, its index in the list is returned.  Otherwise -1 is returned.
*/
template <typename T>
bool binarySearch(const std::vector<T>& list,const T& value)
{
	//first will always point to the beginning of the range we're searching
	//last will always point to the end of the range we're searching
	
	//first and last start off encompassing the entire list
	int first = 0;
	int last = list.size()-1;
	
	//if we don't find the value we're looking for, first and last will
	//pass each other
	while(first <= last)
	{
		//find the midpoint in the list (use integer division)
		int mid = (first+last)/2;
		int midVal = list[mid];
		
		//if the midpoint is our value, we're done
		if(midVal == value)
		{
			return(true);
		}
		//if the midpoint is greater than our search value, then our value
		//must be somewhere in the left half of the list we're searching
		else if(midVal > value)
		{
			last = mid-1;
		}
		//if the midpoint is less than our search value, then our value
		//must be somewhere in the right half of the list we're searching
		else
		{
			first = mid+1;
		}
	}
	
	//The value wasn't found in the list
	return(false);
}

#endif
