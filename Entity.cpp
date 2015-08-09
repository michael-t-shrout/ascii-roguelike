#include "Entity.h"

using namespace std;

Entity::Entity()
{
	m_cSymbol = 'X';
}

void Entity::setName(string sName)
{
	m_sName = sName;
}

string Entity::getName()
{
	return m_sName;
}

void Entity::setSymbol(char cSymbol)
{
	m_cSymbol = cSymbol;
}

char Entity::getSymbol()
{
	return m_cSymbol;
}

int Entity::getPosX()
{
	return m_iPosX;
}
void Entity::setPosX(int iPosX)
{
	m_iPosX = iPosX;
}
int Entity::getPosY()
{
	return m_iPosY;
}
void Entity::setPosY(int iPosY)
{
	m_iPosY = iPosY;
}

void Entity::dumpObjectData()
{
	cout << "     Name : " << getName() << endl;
	cout << "   Symbol : " << getSymbol() << endl;
}

void Entity::dumpObject()
{
	cout << "Entity:" << endl;

	dumpObjectData();
}

void Entity::writeFragment(ostream & output)
{
	output << " <Entity>" << endl;

	writeDataAsFragment(output);

	output << " </Entity>" << endl;
}

void Entity::writeDataAsFragment(ostream & output)
{
	output << "   <name>"
		<< getName()
		<< "</name>"
		<< endl
		<< "   <symbol>"
		<< getSymbol()
		<< "</symbol>"
		<< endl;
}

void Entity::setElementData(string sElementName, 
		string sValue)
{
	if (sElementName == "name")
	{
		setName(sValue);
	}
	else if (sElementName == "symbol")
	{
		setSymbol(sValue[0]);
	}
	else
	{
		return;
	}
}

