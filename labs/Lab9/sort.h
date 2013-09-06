#ifndef SORT_H_
#define SORT_H_

#include <algorithm>
#include <vector>

/////////////////////////////////////
//INSERTION SORT functions
/////////////////////////////////////

/*
	A basic form of insertion sort that sorts the section of the input
	vector located between indexes "start" and "end".  When this function
	returns, the sequence numbers[start] through numbers[end] will be sorted.
*/
template <typename T>
void insertionSort(std::vector<T>& list,int start,int end)
{
	for(int i=start+1; i <= end; i++)
	{
		//see if the current number is out of order...
		//if so, get ready to move it
		if(list[i] < list[i-1])
		{
			//find where the current number goes in the
			//sorted section of the list and bump all the
			//other numbers over one spot
			T temp = list[i];
			int loc = i;
			do
			{
				list[loc] = list[loc-1];
				loc--;
			} while(loc > 0 && list[loc-1] > temp);
			
			//swap the current number into the location
			//where it belongs
			list[loc] = temp;
		}
	}
}

/*
	A convenience function to insertion sort an entire vector.
*/
template <typename T>
void insertionSort(std::vector<T>& list)
{
	insertionSort(list,0,list.size()-1);
}

/////////////////////////////////////
//QUICK SORT functions
/////////////////////////////////////

/*
	Run the quick sort partition routine.  This routine will choose
	the last element of the (sub)vector as the pivot and then reorganize
	all the elements between start & end-1 around it.  This function returns
	the index of the pivot after the pivot has been swapped back into the
	middle of the list.
*/
template <typename T>
int partition(std::vector<T>& list,int start,int end)
{
	T pivot = list[end];
	int i = start-1;
	for(int j=start; j < end; j++) {
		if(list[j] <= pivot) {
			i += 1;
			swap(list[i],list[j]);
		}
	}
	swap(list[i+1],list[end]);
	return(i+1);
}


/*
	Run the quick sort algorithm to sort elements between indexes
	"start" and "end" in "list".
*/
template <typename T>
void quickSort(std::vector<T>& list,int start,int end)
{
	if(start < end)
	{
		int pivot = partition(list,start,end);
		quickSort(list,start,pivot-1);
		quickSort(list,pivot+1,end);
	}
}

/*
	A convenience function to quick sort an entire vector.
*/
template <typename T>
void quickSort(std::vector<T>& list)
{
	quickSort(list,0,list.size()-1);
}

#endif
