#ifndef __RECTANGLE_H_
#define __RECTANGLE_H_
#include "Point.h"

class Rectangle
{
public:
	Rectangle(const int &x1, const int &y1, const int &x2, const int &y2);
	void ShowRecInfo() const;

private:
	Point upLeft;
	Point lowRight;
};
#endif // !__RECTANGLE_H_
