#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include "node.h"

template <typename T>
class Queue
{
	private:
		Node<T>* head;
		Node<T>* tail;
		int listSize;
	
	public:
		Queue();
		int size() const;
		bool empty() const;
		
		void push(const T& value);
		void pop();
		T& front() const;
		T& back() const;
		void print() const;
};

template <typename T>
Queue<T>::Queue() {
    head= NULL;
    tail= NULL;
    listSize= 0;
}

template <typename T>
int Queue<T>::size() const {
    return listSize;
}

template <typename T>
bool Queue<T>::empty() const {
    return (listSize == 0);
}

template <typename T>
void Queue<T>::push(const T& value) {
    Node<T>* newNode= new Node<T>(value);
    newNode->data= value;
    if(head == NULL) {
        head= newNode;
        tail= newNode;
        return;
    }
    Node<T>* temp= tail;
    tail= newNode;
    temp->next= tail;
    listSize++;
}

template <typename T>
void Queue<T>::pop() {
    if(head == NULL) {
        std::cout<<"Cannot pop an empty queue"<<std::endl;
        return;
    }
    Node<T>* ptr= head;
    head= head->next;
    delete ptr;
    listSize--;
}

template <typename T>
T& Queue<T>::front() const {
    try {
        if(head == NULL)
            throw 0;
        else
            return head->data;
    }
    catch(int &x) {
        std::cerr<<"No front for an empty queue"<<std::endl;
    }
}

template <typename T>
T& Queue<T>::back() const {
    try {
        if(tail == NULL)
            throw 0;
        else
            return tail->data;
    }
    catch(int &x) {
        std::cerr<<"No tail for an empty queue"<<std::endl;
    }
}

template <typename T>
void Queue<T>::print() const {
    Node<T>* ptr= head;
    while(ptr != NULL) {
        std::cout<<ptr->data<<"<-";
        ptr= ptr->next;
    }
    std::cout<<"*"<<std::endl;
}

#endif
