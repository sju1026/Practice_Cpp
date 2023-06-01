#include <iostream>
#include "Point.h"
using namespace std;

Point1::Point(int x, int y) : xpos(x), ypos(y) { }

ostream& operator<<(ostream& os, const Point1& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}