#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include "node.h"

template <typename T>
class Stack
{
	private:
		Node<T>* head;
		int listSize;
	
	public:
		Stack();
		int size() const;
		bool empty() const;
		
		void push(const T& value);
		void pop();
		T& top() const;
		void print() const;
};

template <typename T>
Stack<T>::Stack() {
    head= NULL;
    listSize= 0;
}

template <typename T>
int Stack<T>::size() const {
    return listSize;
}

template <typename T>
bool Stack<T>::empty() const {
    return (listSize==0);
}

template <typename T>
void Stack<T>::push(const T& value) {
    Node<T>* newNode= new Node<T>(value);
    newNode->data= value;
    listSize++;
    if(head == NULL) {
        head= newNode;
        return;
    }
    Node<T>* temp= head;
    head= newNode;
    newNode->next= temp;
}

template <typename T>
void Stack<T>::pop() {
    if(empty()) {
        std::cout<<"Cannot pop an empty stack!"<<std::endl;
        return;
    }
    Node<T>* temp= head->next;
    delete head;
    head= temp;
    listSize--;
}

template <typename T>
T& Stack<T>::top() const {
    try {
        if(head == NULL)
            throw 0;
        else
            return head->data;
    }
    catch(int& x) {
        std::cerr<<"List is empty, no top!"<<std::endl;
    }
}

template <typename T>
void Stack<T>::print() const {
    Node<T>* ptr= head;
    while(ptr != NULL) {
        std::cout<<(ptr->data)<<"<-";
        ptr= ptr->next;
    }
    std::cout<<"*"<<std::endl;
}

#endif
