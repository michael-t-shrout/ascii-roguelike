#include "Character.h"
#include <cstdlib>

using namespace std;

Character::Character()
{
}

int Character::getHealth()
{
	return m_iHealth;
}

void Character::setHealth(int iHealth)
{
	m_iHealth = iHealth;
}

void Character::attack(Character & target)
{
}

void Character::dumpObjectData()
{
	Entity::dumpObjectData();

	cout << "   Health : " << getHealth() << endl;
}

void Character::dumpObject()
{
	cout << "Character:" << endl;

	dumpObjectData();
}

void Character::writeFragment(ostream & output)
{
	output << " <Character>" << endl;

	writeDataAsFragment(output);

	output << " </Character>" << endl;
}

void Character::writeDataAsFragment(ostream & output)
{
	Entity::writeDataAsFragment(output);

	output << "   <health>"
		<< getHealth()
		<< "</health>"
		<< endl;
}

void Character::setElementData(string sElementName, 
		string sValue)
{
	Entity::setElementData(sElementName, sValue);

	int iValue = atoi(sValue.c_str());

	if (sElementName == "health")
	{
		setHealth(iValue);
	}
	else
	{
		return;
	}
}

