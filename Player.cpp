#include "Player.h"
#include <cstdlib>
#include <sstream>

using namespace std;

Player::Player()
{
	m_iExperience = 0;
	m_iLevel = 1;
}

int Player::getExperience()
{
	return m_iExperience;
}

void Player::setExperience(int iExperience)
{
	m_iExperience = iExperience;
}

int Player::getLevel()
{
	return m_iLevel;
}

void Player::setLevel(int iLevel)
{
	m_iLevel = iLevel;
}

Weapon * Player::getWeaponSlot()
{
	return m_wWeapon;
}

void Player::setWeaponSlot(Weapon * wWeapon)
{
	m_wWeapon = wWeapon;
}

Armor * Player::getArmorSlot()
{
	return m_aArmor;
}

void Player::setArmorSlot(Armor * aArmor)
{
	m_aArmor = aArmor;
}

string Player::attack(Creature * target, int random, int chain)
{
	ostringstream log;
	int attack_power = 0;
	
	if (chain > 0)
	{
		chain++;
		log << "[CHAIN]";
		if (random < 5)
		{
			attack_power = (getLevel() * 5) + (chain * getWeaponSlot()->getAttackBonus()) + (random - 3);
		}
		if (random > 5)
		{
			attack_power = (chain * getLevel() * 5) + (getWeaponSlot()->getAttackBonus()) + (random - 3);
		}
		if (random == 5)
		{
			attack_power = chain * ((getLevel() * 5) + (getWeaponSlot()->getAttackBonus())) + (random - 3);
		}
	}
	else 
	{
		if (random == 6)
		{
			return "The " + target->getName() + " manages to dodge your attack.";
		}
		else if (random == 5)
		{
			attack_power = (getLevel() * 5) + (2 * (getWeaponSlot()->getAttackBonus())) + (random - 3);
		}
		else 
		{
			attack_power = (getLevel() * 5) + getWeaponSlot()->getAttackBonus() + (random - 3);
		}
	}
	target->setHealth(target->getHealth() - attack_power);
	int targHealth = target->getHealth();
	if (target->getHealth() < 0) {targHealth = 0;}
	if (random == 10)
	{
		log << "The " << target->getName() << " got blasted for " << attack_power << "DMG. " << targHealth << " life left.";
		return log.str();
	}
	else if (random < 5)
	{
		if (getWeaponSlot()->getWeaponType() == 1)
		{
			log << "You introduce the " << target->getName() << "'s face to Brass for " << attack_power << "DMG. " << targHealth << " life left.";
			return log.str();
		}
		if (getWeaponSlot()->getWeaponType() == 2)
		{
			log << "You go to work on the " << target->getName() << " for " << attack_power << "DMG. " << targHealth << " life left.";
			return log.str();
		}
		if (getWeaponSlot()->getWeaponType() == 3)
		{
			log << "The " << target->getName() << " got gun-butted for " << attack_power << "DMG. " << targHealth << " life left.";
			return log.str();
		}
		if (getWeaponSlot()->getWeaponType() == 4)
		{
			log << "You go NINJA on the " << target->getName() << "'s ass for " << attack_power << "DMG. " << targHealth << " life left.";
			return log.str();
		}
	}
	else if (random == 5)
	{
		log << "You unleash hell on the " << target->getName() << " for " << attack_power << " CRITICAL DMG. " << targHealth << " life left.";
		return log.str();
	}
	else if (random == 6)
	{
		log << "The " << target->getName() << " couldn't dodge. He takes " << attack_power << " DMG. " << targHealth << " life left.";
		return log.str();
	}
	else if (random == 7)
	{
		log << "You beat down the " << target->getName() << " for " << attack_power << " DMG. " << targHealth << " life left.";
		return log.str();
	}
	else if (random == 8)
	{
		log << "You head-butt the " << target->getName() << " for " << attack_power << " DMG. " << targHealth << " life left.";
		return log.str();
	}
	else if (random == 9)
	{
		log << "Your roundhouse sends the " << target->getName() << " flying for " << attack_power << " DMG. " << targHealth << " life left.";
		return log.str();
	}
}

void Player::dumpObjectData()
{
	Character::dumpObjectData();

	cout << "  Experience : " << getExperience() << endl;
	cout << "       Level : " << getLevel() << endl;
}

void Player::dumpObject()
{
	cout << "Player:" << endl;

	dumpObjectData();
}

void Player::writeFragment(ostream & output)
{
	output << " <Player>" << endl;

	writeDataAsFragment(output);

	output << " </Player>" << endl;
}

void Player::writeDataAsFragment(ostream & output)
{
	Character::writeDataAsFragment(output);

	output << "   <experience>"
		<< getExperience()
		<< "</experience>"
		<< endl
		<< "   <level>"
		<< getLevel()
		<< "</level>"
		<< endl;
}

void Player::setElementData(string sElementName, 
		string sValue)
{
	Character::setElementData(sElementName, sValue);

	int iValue = atoi(sValue.c_str());

	if (sElementName == "experience")
	{
		setExperience(iValue);
	}
	else if (sElementName == "level")
	{
		setLevel(iValue);
	}
	else
	{
		return;
	}
}

