#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(int l,int w,int x,int y) 
: Shape(x,y), length(l), width(w)
{
	//empty
}
		
string Rectangle::getType() const
{
	return "Rectangle";
}

int Rectangle::getLength() const
{ 
	return length;
}

void Rectangle::setLength(int len) 
{ 
	length = len; 
}

int Rectangle::getWidth() const 
{ 
	return width; 
}

void Rectangle::setWidth(int w) 
{ 
	width = w; 
}

int Rectangle::getPerimeter() const
{
    return 2*(length+width);
}
