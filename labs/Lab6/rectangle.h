#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "shape.h"

class Rectangle : public Shape
{
	private:
	
		int length;
		int width;
	
	public:
		Rectangle(int l,int w,int x,int y);
		
		int getLength() const;
		void setLength(int len);
		int getWidth() const;
		void setWidth(int w);
		
		virtual std::string getType() const;
                virtual int getPerimeter() const;
};

#endif
