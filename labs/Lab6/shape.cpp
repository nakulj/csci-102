#include "shape.h"

using namespace std;

Shape::Shape(int x,int y)
: center(x,y)
{
	//empty
}
		
Point Shape::getCenter() const
{ 
	return center;
}

void Shape::setCenter(Point p)
{ 
	center = p; 
}

string Shape::getType() const
{
	return "Shape";
}
