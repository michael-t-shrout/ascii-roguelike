#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <functional>


#include "Armor.h"
#include "Character.h"
#include "Consumable.h"
#include "Creature.h"
#include "DungeonLevel.h"
#include "Entity.h"
#include "Equipment.h"
#include "GenericFactory.h"
#include "Item.h"
#include "parser.h"
#include "Player.h"
#include "Tile.h"
#include "Tools.h"
#include "Weapon.h"
#include "XMLSerializable.h"

using namespace std;

void dumpObjects(vector<XMLSerializable*> & vObjects)
{
	for ( auto it = vObjects.begin(); it != vObjects.end();
	it++ )
	{
		(*it)->dumpObject();
		cout << endl;
	}
}

void outputXML(vector<XMLSerializable*> & vObjects, ostream & output)
{
	output << "<?xml version=\"1.0\" encoding = \"utf-8\"?>"
		<< endl
		<< "<World>"
		<< endl;
	output.setf(ios::boolalpha);
	for( auto it = vObjects.begin();
		it != vObjects.end();
		it++ )
	{
		(*it)->writeFragment(output);
	}

	output << "</World>" << endl;
}
/*
void parseElement(istream & input, XMLSerializable * pObject, 
	vector<XMLSerializable*>& vObjects, map<string, function<XMLSerializable*()>>& mapConstructor)
{
	string sElementName;
	getline(input, sElementName, '>');
	
	if( sElementName.back() == '/' )
	{
		cout << "Empty element: " << sElementName << endl;
		return;
	}
	else
	{
		if ((sElementName == "Armor")||(sElementName == "Character")||(sElementName == "Consumable")||
			(sElementName == "Creature")||(sElementName == "Entity")||(sElementName == "Equipment")||
			(sElementName == "Item")||(sElementName == "Player")||(sElementName == "Weapon"))
		{

			function<XMLSerializable*()> pFunc = mapConstructor[sElementName];
			if( pFunc == NULL )
			{
				cout << "Could not find a class of name " <<
				sElementName << "." << endl;
			}
			else
			{
				cout << "Constructing class." << endl;
				pObject = pFunc();
						
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
	}

	string sContent = "";


	while( true )
	{

		char c = input.get();

		while( c != '<' )
		{
			if( c != '\n' )
				sContent.push_back(c);

			c = input.get();
		}

		if( input.peek() == '/' )
		{
			input.get();
			string sEndElement;
			getline(input, sEndElement, '>');

			if( sEndElement != sElementName )
				cout << "Bad XML found" << endl;
			else if ((sElementName == "Armor")||(sElementName == "Character")||(sElementName == "Consumable")||
			(sElementName == "Creature")||(sElementName == "Entity")||(sElementName == "Equipment")||
			(sElementName == "Item")||(sElementName == "Player")||(sElementName == "Weapon")){
				cout << "Object added to vector" << endl;
				vObjects.push_back(pObject);}
			else if (sElementName == "World")
				cout << "End" << endl;
			else
			{
				cout << sElementName << " " << sContent << endl;
				pObject->setElementData(sElementName,sContent);
				pObject->dumpObject();
			}			
			return;
		}
		else
		{
			parseElement(input, pObject, vObjects, mapConstructor);
		}

	}

}

void parseXML(string sFilename, XMLSerializable * pObject, vector<XMLSerializable*>& vObjects, map<string, 
	function<XMLSerializable*()>>& mapConstructor)
{
	ifstream input;
	input.open(sFilename);
	int vSize = 0;

	while( input.get() != '?' );
	while( input.get() != '?' );
	
	if( input.get() != '>' )
	{
		cout << "Bad XML detected" << endl;
		return;
	}

	while( input.get() != '<' );

	
	parseElement(input, NULL, vObjects, mapConstructor);

	cout << (vObjects.size() - vSize) << " new objects created." << endl;	
}
*/

/*
int main(int argc, char * argv[])
{
	map<string,function<XMLSerializable*()>>mapConstructor;

	mapConstructor["Armor"] = []() { return new Armor; };
	mapConstructor["Character"] = []() { return new Character; };
	mapConstructor["Consumable"] = []() { return new Consumable; };
	mapConstructor["Creature"] = []() { return new Creature; };
	mapConstructor["Entity"] = []() { return new Entity; };
	mapConstructor["Equipment"] = []() { return new Equipment; };
	mapConstructor["Item"] = []() { return new Item; };
	mapConstructor["Player"] = []() { return new Player; };
	mapConstructor["Weapon"] = []() { return new Weapon; };

	vector<XMLSerializable*> vObjects;
	XMLSerializable * pObject = NULL; 

	cout << "What file should we parse? ";
	string sFilename;
	cin >> sFilename;

	parseXML(sFilename, pObject, vObjects, mapConstructor);

	dumpObjects(vObjects);
		
	cout << "What file should we output XML to? ";
	string xmlOutName;
	cin >> xmlOutName;

	ofstream outfile(xmlOutName + ".xml");
	outputXML(vObjects, outfile);

	system("PAUSE");

	return 0;
}
*/
