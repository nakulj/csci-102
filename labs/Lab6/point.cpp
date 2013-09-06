#include "point.h"

using namespace std;

Point::Point()
{ 
	x=0;
	y=0;
}

Point::Point(int newx,int newy)
{ 
	x=newx; 
	y=newy;
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{ 
	return y; 
}

void Point::setX(int newx) 
{ 
	x=newx;
}

void Point::setY(int newy)
{ 
	y=newy;
}

