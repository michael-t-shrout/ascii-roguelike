#ifndef _Tile_included_
#define _Tile_included_

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Creature.h"
#include "Item.h"
#include "Consumable.h"

using namespace std;

class Tile 
{
public:
	Tile();
	virtual int getTemplate();
	virtual void setTemplate(int iTemplate);
	virtual string getType();
	virtual void setType(string sType);
	virtual char getSymbol();
	virtual void setSymbol(char cSymbol);
	virtual char getDisplaySymbol();
	virtual bool getTraversable();
	virtual void setTraversable(bool bTraversable);
	virtual bool getHidden();
	virtual void setHidden(bool bHidden);
	virtual bool get_holdsPlayer();
	virtual void set_holdsPlayer(bool bholdsPlayer);
	virtual bool get_holdsCreature();
	virtual void set_holdsCreature(bool bholdsCreature);
	virtual bool get_holdsArmors();
	virtual void set_holdsArmors(bool bholdsArmors);
	virtual bool get_holdsWeapons();
	virtual void set_holdsWeapons(bool bholdsWeapons);
	virtual bool get_holdsConsumables();
	virtual void set_holdsConsumables(bool bholdsConsumables);
	virtual Creature * getCreature();
	virtual void setCreature(Creature * cCreature);
	virtual Player * getPlayer();
	virtual void setPlayer(Player * pPlayer);
	virtual vector<Armor*> &getArmorVec() {return m_vArmors;}
	virtual void setArmors(Armor * iArmor);
	virtual void pickupArmor();
	virtual vector<Weapon*> &getWeaponVec() {return m_vWeapons; }
	virtual void setWeapons(Weapon * iWeapon);
	virtual void pickupWeapon();
	virtual vector<Consumable*> &getConsumableVec() {return m_vConsumables;}
	virtual void setConsumables(Consumable * iConsumables);
	virtual void pickupConsumable();
	virtual void set_holdsBomb(bool bholdsBomb);
	virtual bool get_holdsBomb();
	virtual void set_holdsBombRadius(bool bholdsBombRadius);
	virtual bool get_holdsBombRadius();
	virtual void set_bombCounter(int ibombCounter);
	virtual int get_bombCounter();

	
	virtual void revealHidden();
	virtual void useTemplate(int iTemplate);
	

private:
	int m_iTemplate;
	string m_sType;
	char m_cSymbol;
	bool m_bTraversable;
	bool m_bHidden;
	bool m_bholdsPlayer;
	bool m_bholdsCreature;
	bool m_bholdsArmors;
	bool m_bholdsWeapons;
	bool m_bholdsConsumables;
	bool m_bholdsBomb;
	bool m_bholdsBombRadius;
	int m_ibombCounter;
	Creature * m_Creature;
	Player * m_Player;
	vector<Armor*> m_vArmors;
	vector<Weapon*> m_vWeapons;
	vector<Consumable*>m_vConsumables;
};

#endif




