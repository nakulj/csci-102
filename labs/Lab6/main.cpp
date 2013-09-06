#include <iostream>
#include "shape.h"
#include "rectangle.h"
#include "trapezoid.h"

using namespace std;

int main()
{
	Rectangle r(8,12,98,100);
	cout << "I am a " << r.getType() << "!" << endl;
        cout << "My perimeter is" << r.getPerimeter() << "!" << endl;
}
