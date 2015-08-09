#include <iostream>
#include <functional>
#include "DungeonLevel.h"
#include "Tile.h"




using namespace std;

int main(int argc, char * argv[])
{
	DungeonLevel dung;
	vector<DungeonLevel> dLevels;
	for (int i = 1; i < 6; i++)
	{
		dung.generateLevel();

		if (dung.dTest() == true)
		{
			dung.setFloor(i);
			dLevels.push_back(dung);

		}
	}

	for ( auto it = dLevels.begin(); it != dLevels.end(); it++ )
	{
		cout << "Floor " << (*it).getFloor() << ":" << endl;
		(*it).displayLevel();
	}
}
