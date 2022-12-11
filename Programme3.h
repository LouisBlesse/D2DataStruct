#pragma once
#include "Cell.cpp"
class Programme3
{
public:
	void Play();
	Cell** generate(int);
	Cell** GrowTree(Cell**, int);
	void PrintLabyrinthe(Cell**, int);
	bool checkEnd(Cell**, int);
	char getDirection(Cell**, int, int, int);
};

