#ifndef _Player_included_
#define _Player_included_
#include "Character.h"
#include "Creature.h"
#include "Weapon.h"
#include "Armor.h"
#include <string>

class Creature;
class Weapon;
class Armor;

class Player : public Character
{
public:
	Player();
	int getExperience();
	void setExperience(int iExperience);
	int getLevel();
	void setLevel(int iLevel);
	Weapon * getWeaponSlot();
	void setWeaponSlot(Weapon * wWeapon);
	Armor * getArmorSlot();
	void setArmorSlot(Armor * aArmor);

	virtual string attack(Creature * target, int random, int chain);
	//virtual void move(char cInput, DungeonLevel dung);

	virtual void dumpObjectData();
	virtual void dumpObject();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, 
		std::string sValue);

private:
	int m_iExperience;
	int m_iLevel;
	Weapon * m_wWeapon;
	Armor * m_aArmor;
};

#endif

