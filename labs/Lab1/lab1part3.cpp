#include <iostream>

using namespace std;

int calculate(int* a, int* b)
{
	int x= (*a)*(*a);
	int y= (*b)*(*b);
	*a= x;
	*b= y;
	return x+y;
}

int main()
{
    int x = 10;
    int y = 20;
	cout<<"x: "<<x<<endl<<"y:"<<y<<endl;
	calculate(&x,&y);
	cout<<"x: "<<x<<endl<<"y:"<<y<<endl;
}
