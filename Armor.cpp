#include "Armor.h"
#include <cstdlib>

using namespace std;

Armor::Armor()
{
	m_iDefenseBonus = 0;
}

int Armor::getDefenseBonus()
{
	return m_iDefenseBonus;
}

void Armor::setDefenseBonus(int iDefenseBonus)
{
	m_iDefenseBonus = iDefenseBonus;
}

void Armor::dumpObjectData()
{
	Equipment::dumpObjectData();

	cout << "   DefenseBonus : " << getDefenseBonus() << endl;
}

void Armor::dumpObject()
{
	cout << "Armor:" << endl;

	dumpObjectData();
}

void Armor::writeFragment(ostream & output)
{
	output << " <Armor>" << endl;

	writeDataAsFragment(output);

	output << " </Armor>" << endl;
}

void Armor::writeDataAsFragment(ostream & output)
{
	Equipment::writeDataAsFragment(output);

	output << "   <defenseBonus>"
		<< getDefenseBonus()
		<< "</defenseBonus>"
		<< endl;
}

void Armor::setElementData(string sElementName, 
		string sValue)
{
	Equipment::setElementData(sElementName, sValue);

	int iValue = atoi(sValue.c_str());

	if (sElementName == "defenseBonus")
	{
		setDefenseBonus(iValue);
	}
	else
	{
		return;
	}
}
