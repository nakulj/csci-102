#include <iostream>
#include "stack.h"
#include "queue.h"
#include "deque.h"

using namespace std;

int main()
{
	cout << "It runs!" << endl;
	
	//create a stack & show it works
	Stack<int> s;
        s.pop();
        s.print();
        cout<<"Empty?  "<<s.empty()<<endl;
        cout<<s.size()<<endl;
        for(int i=0; i<10; i++) {
            s.push(2*i+1);
            s.print();
            cout<<s.size()<<endl<<endl;
        }
        cout<<"Empty?  "<<s.empty()<<endl;
        cout<<"The top is "<<(s.top())<<endl;
        for(int i=0; i<12; i++) {
            s.pop();
            s.print();
        }
        cout<<"The top is "<<(s.top())<<endl;
	//create a queue & show it works
	Queue<int> q;
        q.print();
        cout<<"Empty?  "<<q.empty()<<endl;
        cout<<q.size()<<endl;
        for(int i=0; i<10; i++) {
            q.push(2*i+1);
            q.print();
            cout<<q.size()<<endl<<endl;
        }
        cout<<"Empty?  "<<q.empty()<<endl;
        cout<<"The front is "<<(q.front())<<endl;
        cout<<"The rear is "<<(q.back())<<endl;
        for(int i=0; i<12; i++) {
            q.pop();
            q.print();
        }
        cout<<"The front is "<<(q.front())<<endl;
        cout<<"The rear is "<<(q.back())<<endl;

        Deque<int> d;
        d.print();
        for(int i=0; i<10; i++) {
            d.push_back(i);
            d.print();
        }
        for(int i=0; i<10; i++) {
            if(i%2==0) {cout<<"back"<<endl;
                d.pop_back();}
            else{cout<<"front"<<endl;
                d.pop_front();}
            d.print();
        }
}
