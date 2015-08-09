#include "Creature.h"
#include <sstream>

using namespace std;

Creature::Creature()
{
	// Such a hostile world...
	m_bHostile = true;
}

bool Creature::isHostile()
{
	return m_bHostile;
}

void Creature::setHostile(bool bHostile)
{
	m_bHostile = bHostile;
}

string Creature::attack(Player * target, int dmg, int random)
{
	ostringstream message;
	if (getName() == "Shotgunner")
	{
		target->setHealth(target->getHealth() - 25 + target->getArmorSlot()->getDefenseBonus());
		message << "The " << getName() << " blasted you for 25 damage! Armor absorbed " << target->getArmorSlot()->getDefenseBonus() << ".";
		return message.str();
	}
	else if (random == 0)
	{
		message << "The " << getName() << " must be sauced... He throws a wild punch and misses."; 
		return message.str();
	}
	else if (random == 4)
	{
		target->setHealth(target->getHealth() - (7 * dmg) + target->getArmorSlot()->getDefenseBonus());
		message << "The " << getName() << " gets in a cheap shot for " << 7 * dmg << " CRITICAL damage! Armor absorbed " << target->getArmorSlot()->getDefenseBonus() << ".";
		return message.str();
	}
	else
	{
		
		if (random == 1)
		{
			message << "The " << getName() << " smacks you around for " << 4 * dmg + random << " damage! Armor absorbed " << target->getArmorSlot()->getDefenseBonus() << ".";
			target->setHealth(target->getHealth() - (4 * dmg +random) + target->getArmorSlot()->getDefenseBonus());
		}
		else if (random == 2)
		{
			message << "The " << getName() << " smashes a bottle on your head for " << 4 * dmg + random << " damage! Armor absorbed " << target->getArmorSlot()->getDefenseBonus() << ".";
			target->setHealth(target->getHealth() - (4 * dmg +random) + target->getArmorSlot()->getDefenseBonus());
		}
		else if (random == 3)
		{
			message << "The " << getName() << " sticks you with a knife for " << 4 * dmg + random << " damage! Armor absorbed " << target->getArmorSlot()->getDefenseBonus() << ".";
			target->setHealth(target->getHealth() - (4 * dmg +random) + target->getArmorSlot()->getDefenseBonus());
		}
		
		return message.str();
	}

}

void Creature::dumpObjectData()
{
	Character::dumpObjectData();

	cout << "   Hostile : " << isHostile() << endl;
}

void Creature::dumpObject()
{
	cout << "Creature:" << endl;

	dumpObjectData();
}

void Creature::writeFragment(ostream & output)
{
	output << " <Creature>" << endl;

	writeDataAsFragment(output);

	output << " </Creature>" << endl;
}

void Creature::writeDataAsFragment(ostream & output)
{
	output << "   <hostile>"
		<< isHostile()
		<< "</hostile>"
		<< endl;
}

void Creature::setElementData(string sElementName, 
		string sValue)
{
	Character::setElementData(sElementName, sValue);

	bool iValue = true;
	if (sValue == "false")
	{
		iValue = false;
	}

	if (sElementName == "hostile")
	{
		setHostile(iValue);
	}
	else
	{
		return;
	}
}


