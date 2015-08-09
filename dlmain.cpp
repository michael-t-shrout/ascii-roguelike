/*
#include <iostream>
#include <random>
#include <ctime>
#include <ncurses.h>

#include "DungeonLevel.h"

using namespace std;

int main(int argc, char * argv[])
{
	mt19937 mt;
	mt.seed( time(NULL) );
	//DungeonLevel dl(79, 20, mt);
	
	initscr();
	do
	{
		DungeonLevel dl(79, 20, mt);
		clear();
		for (size_t x = 0; x < dl.getWidth(); x++)
		{
			for (size_t y = 0; y  < dl.getHeight(); y++)
			{
				move(y,x);
				addch(dl.at(x,y));
			}
		}
		refresh();
	}
	while (getch() != 'q');

	endwin();
	return 0;
}
*/