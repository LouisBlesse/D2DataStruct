#include "Cell.h"
class Cell
{
public:
	int data;
	bool know;
	bool visited;
	bool start;
	bool stop;
	double dist;
	int parentX;
	int parentY;
	int x;
	int y;
	Cell(): data(0), know(0){}
	//Cell(const Cell& n, const Cell& s, const Cell& e, const Cell& o, int d, bool k) : N(n), S(s),E(e), O(o), data(d), know(k) { }
	//Cell(int d, bool k) :data(d), know(k) { }
};