#include "GenericFactory.h"

#include <random>
#include <ctime>

#include "parser.h"

#include "Armor.h"
#include "Weapon.h"
#include "Creature.h"
#include "Player.h"
#include "Consumable.h"
#include "Item.h"
#include "Tools.h"

using namespace std;


GenericFactory & GenericFactory::instance()
{
	static GenericFactory factory;
	return factory;
}

GenericFactory::GenericFactory()
{
	map<string, function<XMLSerializable*()>> mConstructors;
	mConstructors["Item"] = []() { return new Item; };
	mConstructors["Consumable"] = []() { return new Consumable; };
	mConstructors["Creature"] = []() { return new Creature; };
	mConstructors["Weapon"] = []() { return new Weapon; };
	mConstructors["Armor"] = []() { return new Armor; };
	mConstructors["Player"] = []() { return new Player; };
	vector<XMLSerializable*> vObjects;

    parseXML(mConstructors, "world.xml", vObjects);

	m_vCreatures.constructVector(vObjects);
	m_vItems.constructVector(vObjects);
	m_vPlayer.constructVector(vObjects);
	m_vArmor.constructVector(vObjects);
	m_vConsumable.constructVector(vObjects);
	m_vWeapon.constructVector(vObjects);

}

GenericFactory::~GenericFactory()
{
}

Creature * GenericFactory::generateBigCreature(int iMaxHealth)
{
	return m_vCreatures.generate( [=](Creature * pCreature) { return pCreature->getHealth() == iMaxHealth; });
}

Creature * GenericFactory::generateSmallCreature(int iMaxHealth)
{
	return m_vCreatures.generate( [=](Creature * pCreature) { return pCreature->getHealth() < iMaxHealth;  });
}
Item * GenericFactory::generateItem()
{
	return m_vItems.generate( [](Item * pItem) { return true; });
}

Player * GenericFactory::generatePlayer()
{
	return m_vPlayer.generate( [=](Player * pPlayer) { return true; });
}
Weapon * GenericFactory::generateWeapon()
{
	return m_vWeapon.generate( [=](Weapon * wWeapon) { return true; });
}
Weapon * GenericFactory::generateSpecificWeapon(int iType)
{
	return m_vWeapon.generate( [=](Weapon * wWeapon) { return wWeapon->getWeaponType() == iType; });
}
Armor * GenericFactory::generateArmor()
{
	return m_vArmor.generate( [=](Armor * aArmor) { return true; });
}
Consumable * GenericFactory::generateConsumable()
{
	return m_vConsumable.generate( [=](Consumable * cConsumable) { return true; });
}
Consumable * GenericFactory::generateKeyConsumable(int iWeight)
{
	return m_vConsumable.generate( [=](Consumable * cConsumable) { return cConsumable->getWeight() == iWeight; });
}
Consumable * GenericFactory::generateNotKeyConsumable(int iWeight)
{
	return m_vConsumable.generate( [=](Consumable * cConsumable) { return cConsumable->getWeight() > iWeight; });
}