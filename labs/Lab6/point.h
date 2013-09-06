#ifndef POINT_H_
#define POINT_H_

#include <iostream>

class Point
{
	private:
		
		int x;
		int y;
		
	public:
		
		Point();
		Point(int newx,int newy);
		
		int getX() const;
		int getY() const;
		void setX(int newx);
		void setY(int newy);
};

#endif
