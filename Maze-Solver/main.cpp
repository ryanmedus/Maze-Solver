#include <iostream>
#include <ctime>
#include <cassert>
#include "DoublyLinkedList.h"
#include "stack.h"
#include "queue.h"
#include "map.h"
#include "Tracker.h"

using namespace std;

int main()
{
	Map map("3x3map.txt");
	Map map1("6x6map.txt");
	Map map2("10x10map.txt");
	Tracker tracker(map.getStartCell());
	Tracker tracker1(map1.getStartCell());
	Tracker tracker2(map2.getStartCell());
	map.printMap();
	tracker.findPath();
	map.printPathThroughMap();
	map1.printMap();
	tracker1.findPath();
	map1.printPathThroughMap();
	map2.printMap();
	tracker2.findPath();
	map2.printPathThroughMap();

	return 0;
}