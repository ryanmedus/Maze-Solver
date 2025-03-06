#pragma once
#include "Map.h"
#include "Stack.h"

using namespace std;

class Tracker
{
public:
	Tracker(Cell* start);
	void findPath();
private:
	Stack<Cell*> stack;
	void backtrack();
};

