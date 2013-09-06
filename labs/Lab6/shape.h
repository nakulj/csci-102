#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
#include <string>
#include "point.h"

/**
	A base class "Shape" that represents a geometric shape
	and stores its location on a 2D plane.
*/
class Shape
{
	protected:
		
		/* The center point of the shape in 2D coordinates (X,Y) */
		Point center;
	
	public:
		
		Shape(int x,int y);
		
		Point getCenter() const;
		void setCenter(Point p);
		
		virtual std::string getType() const; //normal virtual function
                virtual int getPerimeter() =0;
};

#endif
