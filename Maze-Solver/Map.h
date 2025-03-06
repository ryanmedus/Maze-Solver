#pragma once
#include "Queue.h"
#include "Cell.h"
#include <fstream>

using namespace std;

class Map
{
public:
	Map(string pathToMapFile);
	~Map();
	Cell* getStartCell();
	void printMap();
	void printPathThroughMap();
private:
	void setDirections();
	int dimension;
	Cell* topLeftCell;
	Cell* startCell;
	DoublyLinkedList<Cell*> map;
};

