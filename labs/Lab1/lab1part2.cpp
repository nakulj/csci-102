#include <iostream>

using namespace std;

int calculate(int& a, int& b)
{
	a*=a;b*=b;
	return a+b;
}

int main()
{
    int x = 10;
    int y = 20;
	cout<<"x: "<<x<<endl<<"y:"<<y<<endl;
	calculate(x,y);
	cout<<"x: "<<x<<endl<<"y:"<<y<<endl;
}