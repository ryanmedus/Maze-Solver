#include "Tracker.h"

Tracker::Tracker(Cell* start)
{
	stack.push(start);
	stack.top()->setIsOnPath(1);
	stack.top()->setTraversed(1);
}

void Tracker::findPath()
{
	while (stack.top()->getType() != 'E')
	{
		if (stack.top()->getNorth() != 0 && (stack.top()->getNorth()->getType() == 'F' || stack.top()->getNorth()->getType() == 'E') 
			&& !stack.top()->getNorth()->getTraversed())
		{
			stack.push(stack.top()->getNorth());
			stack.top()->setTraversed(1);
			stack.top()->setIsOnPath(1);
			cout << "Going North row: " << stack.top()->getY() << " col: " << stack.top()->getX() << " Type: " << stack.top()->getType() << endl;
		}
		else if (stack.top()->getEast() != 0 && (stack.top()->getEast()->getType() == 'F' || stack.top()->getEast()->getType() == 'E') 
			&& !stack.top()->getEast()->getTraversed())
		{
			stack.push(stack.top()->getEast());
			stack.top()->setTraversed(1);
			stack.top()->setIsOnPath(1);
			cout << "Going East row: " << stack.top()->getY() << " col: " << stack.top()->getX() << " Type: " << stack.top()->getType() << endl;
		}
		else if (stack.top()->getSouth() != 0 && (stack.top()->getSouth()->getType() == 'F' || stack.top()->getSouth()->getType() == 'E') 
			&& !stack.top()->getSouth()->getTraversed())
		{
			stack.push(stack.top()->getSouth());
			stack.top()->setTraversed(1);
			stack.top()->setIsOnPath(1);
			cout << "Going South row: " << stack.top()->getY() << " col: " << stack.top()->getX() << " Type: " << stack.top()->getType() << endl;
		}
		else if (stack.top()->getWest() != 0 && (stack.top()->getWest()->getType() == 'F' || stack.top()->getWest()->getType() == 'E') 
			&& !stack.top()->getWest()->getTraversed())
		{
			stack.push(stack.top()->getWest());
			stack.top()->setTraversed(1);
			stack.top()->setIsOnPath(1);
			cout << "Going West row: " << stack.top()->getY() << " col: " << stack.top()->getX() << " Type: " << stack.top()->getType() << endl;
		}
		else
		{
			backtrack();
		}
	}
}

void Tracker::backtrack()
{
	stack.top()->setIsOnPath(0);
	stack.pop();
	cout << "Backtracking to row: " << stack.top()->getY() << " col: " << stack.top()->getX() << " Type: " << stack.top()->getType() << endl;
}