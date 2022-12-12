#include "Point.h"
class Point
{
public:
	int x;
	int y;
	int dist;
	Point(int X, int Y) : x(X), y(Y) {}
	Point(int X, int Y, int Dist) : x(X), y(Y), dist(Dist) {}
};