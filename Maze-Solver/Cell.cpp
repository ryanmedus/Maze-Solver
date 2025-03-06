#include "Cell.h"

Cell::Cell()
{
	type = ' ';
	col = 0;
	row = 0;
	isTraversed = 0;
	isOnPath = 0;
	north = 0;
	east = 0;
	south = 0;
	west = 0;
}

void Cell::setX(int x)
{
	col = x;
}

int Cell::getX()
{
	return col;
}

void Cell::setY(int y)
{
	row = y;
}

int Cell::getY()
{
	return row;
}

void Cell::setIsOnPath(bool b)
{
	isOnPath = b;
}

bool Cell::getIsOnPath()
{
	return isOnPath;
}

void Cell::setTraversed(bool b)
{
	isTraversed = b;
}

bool Cell::getTraversed()
{
	return isTraversed;
}

char Cell::getType()
{
	return type;
}

Cell* Cell::getNorth()
{
	return north;
}

Cell* Cell::getEast()
{
	return east;
}

Cell* Cell::getSouth()
{
	return south;
}

Cell* Cell::getWest()
{
	return west;
}

void Cell::setType(char c)
{
	type = c;
}

void Cell::setNorth(Cell* ptr)
{
	north = ptr;
}

void Cell::setEast(Cell* ptr)
{
	east = ptr;
}

void Cell::setSouth(Cell* ptr)
{
	south = ptr;
}

void Cell::setWest(Cell* ptr)
{
	west = ptr;
}
