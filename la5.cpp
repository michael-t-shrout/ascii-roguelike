#include <iostream>
#include <string>
#include <map>
#include <functional>

#include "Item.h"
#include "Armor.h"
#include "Weapon.h"
#include "Creature.h"

using namespace std;

XMLSerializable * constructItem()
{
	return new Item;
}

/*int main( int argc, char * argv[] )
{
	map<string,function<XMLSerializable*()>>mapConstructor;

	mapConstructor["Item"] = constructItem;
	mapConstructor["Creature"] = []() { return new Creature; };
	mapConstructor["Armor"] = []() { return new Armor; };
	mapConstructor["Weapon"] = []() { return new Weapon; };

	cout << "What class should I look up? ";

	string sLookup;
	cin >> sLookup;

	function<XMLSerializable*()> pFunc = mapConstructor[sLookup];
		if( pFunc == NULL )
		{
			cout << "Could not find a class of name " <<
			sLookup << "." << endl;
		}
		else
		{
			cout << "Constructing class." << endl;
			XMLSerializable * pObject = pFunc();

			if( pObject != NULL )
			{
				cout << "New object constructed!" <<
				endl;
			}
			else
			{
				cout << "Unable to construct object." <<
				endl;
			}
		}
	}
*/