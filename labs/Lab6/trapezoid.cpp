#include "trapezoid.h"

using namespace std;

Trapezoid::Trapezoid(int aa,int bb,int cc,int dd,int x,int y)
: Shape(x,y), a(aa), b(bb), c(cc), d(dd)
{
	//empty
}

string Trapezoid::getType() const
{
	return "Trapezoid";
}

int Trapezoid::getPerimeter() const
{
    return (a+b+c+d);
}