#pragma once
#include "Cell.cpp"
#include "Point.cpp"
class Programme3
{
public:
	void Play();
	Cell** generate(int);
	Cell** GrowTree(Cell**, int);
	void PrintLabyrinthe(Cell**, int);
	bool checkEnd(Cell**, int);
	char getDirection(Cell**, int, int, int);
	void  BFS(Cell**, int, Point, Point);
	void  A(Cell**, int, Point, Point);
	double calculateD(int, int, Point);
	void makePath(Cell** , Point );
};

