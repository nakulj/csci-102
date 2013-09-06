#ifndef TRAPEZOID_H_
#define TRAPEZOID_H_

#include "shape.h"

class Trapezoid : public Shape
{
	private:

		int a, b, c, d;

	public:
		Trapezoid(int a,int b,int c,int d,int x, int y);

		virtual std::string getType() const;
                virtual int getPerimeter() const;
};

#endif
