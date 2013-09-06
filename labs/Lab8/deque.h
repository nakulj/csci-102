#ifndef DEQUE_H_
#define DEQUE_H_

#include <iostream>
#include "node.h"

template <typename T>
class Deque
{
	private:
		Node<T>* head;
		Node<T>* tail;
		int listSize;

	public:
		Deque();
		int size() const;
		bool empty() const;

		void push_back(const T& value);
                void push_front(const T& value);
		void pop_front();
                void pop_back();
		T& front() const;
		T& back() const;
		void print() const;
};

template <typename T>
Deque<T>::Deque() {
    head= NULL;
    tail= NULL;
    listSize= 0;
}

template <typename T>
int Deque<T>::size() const {
    return listSize;
}

template <typename T>
bool Deque<T>::empty() const {
    return (listSize == 0);
}

template <typename T>
void Deque<T>::push_back(const T& value) {
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
void Deque<T>::push_front(const T& value) {
    Node<T>* newNode= new Node<T>(value);
    newNode->data= value;
    if(head == NULL) {
        head= newNode;
        tail= newNode;
        return;
    }
    Node<T>* temp= head->next;
    head= newNode;
    head->next= temp;
    listSize++;
}

template <typename T>
void Deque<T>::pop_front() {
    if(head == NULL) {
        std::cout<<"Cannot pop an empty deque"<<std::endl;
        return;
    }
    Node<T>* ptr= head;
    head= head->next;
    delete ptr;
    listSize--;
}

template <typename T>
void Deque<T>::pop_back() {
    if(tail == NULL) {
        std::cout<<"Cannot pop an empty deque"<<std::endl;
        return;
    }
    Node<T>* temp= tail;
    Node<T>* ptr= head;
    while(ptr->next != temp) {
        std::cout<<ptr->next<<"    "<<temp<<std::endl;
        ptr= ptr->next;
    }
    std::cout<<ptr->next<<"    "<<temp<<std::endl;
    delete temp;
    tail= ptr;
    listSize--;
}

template <typename T>
T& Deque<T>::front() const {
    try {
        if(head == NULL)
            throw 0;
        else
            return head->data;
    }
    catch(int &x) {
        std::cerr<<"No front for an empty deque"<<std::endl;
    }
}

template <typename T>
T& Deque<T>::back() const {
    try {
        if(tail == NULL)
            throw 0;
        else
            return tail->data;
    }
    catch(int &x) {
        std::cerr<<"No tail for an empty deque"<<std::endl;
    }
}

template <typename T>
void Deque<T>::print() const {
    Node<T>* ptr= head;
    while(ptr != NULL) {
        std::cout<<ptr->data<<"->";
        ptr= ptr->next;
    }
    std::cout<<"*"<<std::endl;
    while(ptr != NULL) {
        std::cout<<ptr<<"->";
        ptr= ptr->next;
    }
    std::cout<<"*"<<std::endl;
}

#endif
