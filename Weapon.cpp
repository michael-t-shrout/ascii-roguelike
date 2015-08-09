#include "Weapon.h"
#include <cstdlib>

using namespace std;

Weapon::Weapon()
{
	m_iAttackBonus = 0;
	m_iWeaponType = 0;
}

int Weapon::getAttackBonus()
{
	return m_iAttackBonus;
}

void Weapon::setAttackBonus(int iAttackBonus)
{
	m_iAttackBonus = iAttackBonus;
}

int Weapon::getWeaponType()
{
	return m_iWeaponType;
}

void Weapon::setWeaponType(int iWeaponType)
{
	m_iWeaponType = iWeaponType;
}

void Weapon::dumpObjectData()
{
	Equipment::dumpObjectData();

	cout << "   AttackBonus : " << getAttackBonus() << endl;
	cout << "    WeaponType : " << getWeaponType() << endl;
}

void Weapon::dumpObject()
{
	cout << "Weapon:" << endl;

	dumpObjectData();
}

void Weapon::writeFragment(ostream & output)
{
	output << " <Weapon>" << endl;

	writeDataAsFragment(output);

	output << " </Weapon>" << endl;
}

void Weapon::writeDataAsFragment(ostream & output)
{
	Equipment::writeDataAsFragment(output);

	output << "   <attackBonus>"
		<< getAttackBonus()
		<< "</attackBonus>"
		<< endl
		<< "   <weaponType>"
		<< getWeaponType()
		<< "</weaponType>"
		<< endl;
}

void Weapon::setElementData(string sElementName, 
		string sValue)
{
	Equipment::setElementData(sElementName, sValue);

	int iValue = atoi(sValue.c_str());

	if (sElementName == "attackBonus")
	{
		setAttackBonus(iValue);
	}
	else if (sElementName == "weaponType")
	{
		setWeaponType(iValue);
	}
	else
	{
		return;
	}
}


