#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include <iostream>
#include <vector>
#include <stdexcept>

/**
	A templated Priority Queue class.
*/	
template <typename T>
class PriorityQueue
{
	private:
	
		//the backing array for the Heap
		std::vector<T> data; //length is data.size()
		
		//the actual size of the heap
		//(always <= to data.size())
		int heapSize;
		
	public:
	
		/**
			Default constructor to create an empty priority queue.
		*/
		PriorityQueue();
		
		/**
			Return true if the heap is empty or false otherwise.
		*/
		bool empty();
		
		/**
			Return the size of the heap
		*/
		int size();
		
		/**
			Print out the priority queue to the console. Order of items
			in the printout is the order of items in the array, not necessarily
			the order of the priority.
		*/
		void print() const;
		
	private:
	
		/**
			Return the index of the parent of the item at index i.
		*/
		int parent(int i);
		/**
			Return the index of the left child of the item at index i.
		*/
		int left(int i);
		/**
			Return the index of the right child of the item at index i.
		*/
		int right(int i);
	
	/////////////////////////////////////////////
	//Here is the stuff to implement for lab 12
	/////////////////////////////////////////////
	
	private:
	
		void maxHeapify(int i);
		
	public:
	
		T& top();
		void push(const T& value);
		void pop();
};

template <typename T>
PriorityQueue<T>::PriorityQueue()
: data(5) //default the vector to a reasonable size
{
	heapSize = 0;
}

template <typename T>
int PriorityQueue<T>::parent(int i)
{
	return((i-1)/2);
}

template <typename T>
int PriorityQueue<T>::left(int i)
{
	return(2*i + 1);
}

template <typename T>
int PriorityQueue<T>::right(int i)
{
	return(2*i + 2);
}

template <typename T>
bool PriorityQueue<T>::empty()
{
	return heapSize == 0;
}

template <typename T>
int PriorityQueue<T>::size()
{
	return heapSize;
}

template <typename T>
void PriorityQueue<T>::print() const
{
	std::cout << "[ ";
	for(int i=0; i < heapSize; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << "]" << std::endl;
}

/////////////////////////////////////////////
//Here is the stuff to implement for lab 12
/////////////////////////////////////////////

template <typename T>
void PriorityQueue<T>::maxHeapify(int i) {
    if(left(i)>=heapSize)
        return;
    maxHeapify(left(i));
    if(right(i)>=heapSize) {
        if(data[left(i)]>data[i]) {
            T temp= data[left(i)];
            data[left(i)]= data[i];
            data[i]= temp;
        }
        return;
    }
    maxHeapify(right(i));
    int greater= data[left(i)]>data[right(i)]?left(i):right(i);
    if(data[greater]>data[i]) {
            T temp= data[greater];
            data[greater]= data[i];
            data[i]= temp;
    }
}

template <typename T>
T& PriorityQueue<T>::top()
{
    try{
        if(heapSize==0)
            throw -1;
        else
            return data[0];
    }
    catch(int& ex) {
        std::cerr<<"No top for empty heap"<<std::endl;
    }
}

template <typename T>
void PriorityQueue<T>::push(const T& value)
{
	//leave this here...it will make sure the vector
	//always has enough room
	if(heapSize >= data.size())
		data.resize(heapSize*2);
        data[heapSize++]= value;
        maxHeapify(0);
}

template <typename T>
void PriorityQueue<T>::pop() {
    try {
        if(heapSize==0)
            throw 0;
        else {
            data[0]= data[--heapSize];
            maxHeapify(0);
        }
    }
    catch(int &ex) {
        std::cerr<<"Cannot pop an empty heap"<<std::endl;
    }
}

#endif
