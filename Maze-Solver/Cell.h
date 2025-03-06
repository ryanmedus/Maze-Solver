#pragma once

using namespace std;

class Cell
{
public:
	Cell();
	char getType();
	Cell* getNorth();
	Cell* getEast();
	Cell* getSouth();
	Cell* getWest();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	void setTraversed(bool b);
	bool getTraversed();
	void setIsOnPath(bool b);
	bool getIsOnPath();
	void setType(char c);
	void setNorth(Cell* ptr);
	void setEast(Cell* ptr);
	void setSouth(Cell* ptr);
	void setWest(Cell* ptr);
private:
	char type;
	int col;
	int row;
	bool isTraversed;
	bool isOnPath;
	Cell* north;
	Cell* east;
	Cell* south;
	Cell* west;
};