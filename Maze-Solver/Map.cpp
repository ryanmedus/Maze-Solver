#include "Map.h"


Map::Map(string pathToMapFile)
{
	ifstream infile;

	Queue<char> cells;
	
	infile.open(pathToMapFile);

	if (infile.good())
	{
		char type;
		infile >> type;
		while (infile.good())
		{
			cells.enqueue(type);
			infile >> type;
		}
	}
	dimension = sqrt(cells.size());
	int row = 1;
	int col = 0;
	while (!cells.isEmpty())
	{
		col++;
		Cell* cell = new Cell;
		map.insertAtRear(cell);
		cell->setType(cells.front());
		cell->setX(col);
		cell->setY(row);
		if (cell->getType() == 'S')
		{
			startCell = cell;
		}
		if (col % dimension == 0)
		{
			row++;
			col = 0;
		}
		cells.dequeue();
	}
	setDirections();
}

Map::~Map()
{
	for (int i = 0; i < map.size(); i++)
	{
		delete map[i];
	}
}

void Map::setDirections()
{
	for (int i = 0; i < map.size()-1; i++)
	{
		if (i < dimension)
		{
			map[i]->setNorth(0);
			map[i]->setSouth(map[i + dimension]);
		}
		else if (i >= dimension * (dimension - 1))
		{
			map[i]->setSouth(0);
			map[i]->setNorth(map[i - dimension]);
		}
		else
		{
			map[i]->setNorth(map[i - dimension]);
			map[i]->setSouth(map[i + dimension]);
		}
		if (i % dimension == 0)
		{
			map[i]->setWest(0);
			map[i]->setEast(map[i + 1]);
		}
		else if (i % dimension == dimension - 1)
		{
			map[i]->setEast(0);
			map[i]->setWest(map[i - 1]);
		}
		else
		{
			map[i]->setWest(map[i - 1]);
			map[i]->setEast(map[i + 1]);
		}
	}
}

void Map::printMap()
{
	for (int i = 0; i < map.size(); i++)
	{
		if (i % dimension == 0 && i != 0)
		{
			cout << endl;
		}
		cout << map[i]->getType() << " ";
	}
	cout << endl;
}

void Map::printPathThroughMap()
{
	for (int i = 0; i < map.size(); i++)
	{
		if (i % dimension == 0 && i != 0)
		{
			cout << endl;
		}
		if (map[i]->getIsOnPath())
		{
			cout << "O ";
		}
		else
		{
			cout << "X ";
		}
	}
	cout << endl;
}

Cell* Map::getStartCell()
{
	return startCell;
}