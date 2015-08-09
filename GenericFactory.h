#ifndef _GenericFactory_included_
#define _GenericFactory_included_

#include "Creature.h"
#include "Item.h"
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include "Consumable.h"
#include "EntityVector.h"

#include <vector>

class GenericFactory
{
public:	
	static GenericFactory & instance();
	virtual ~GenericFactory();
	Creature * generateBigCreature(int iMaxHealth);
	Creature * generateSmallCreature(int iMaxHealth);
	Item * generateItem();
	Player * generatePlayer();
	Weapon * generateWeapon();
	Weapon * generateSpecificWeapon(int iType);
	Armor * generateArmor();
	Consumable * generateConsumable();
	Consumable * generateKeyConsumable(int iWeight);
	Consumable * generateNotKeyConsumable(int iWeight);

private:
	GenericFactory();
	EntityVector<Creature> m_vCreatures;
	EntityVector<Item> m_vItems;
	EntityVector<Player> m_vPlayer;
	EntityVector<Weapon> m_vWeapon;
	EntityVector<Armor> m_vArmor;
	EntityVector<Consumable> m_vConsumable;
};

#endif
