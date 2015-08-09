#include "Tile.h"

using namespace std;

Tile::Tile()
{
	m_bHidden = true;
	m_bholdsPlayer = false;
	m_bholdsCreature = false;
	m_bholdsArmors = false;
	m_bholdsWeapons = false;
	m_bholdsConsumables = false;
	m_bholdsBomb = false;
	m_bholdsBombRadius = false;

}

int Tile::getTemplate()
{
	return m_iTemplate;
}

void Tile::setTemplate(int iTemplate)
{
	m_iTemplate = iTemplate;
}

void Tile::setType(string sType)
{
	m_sType = sType;
}

string Tile::getType()
{
	return m_sType;
}

void Tile::setSymbol(char cSymbol)
{
	m_cSymbol = cSymbol;
}

char Tile::getSymbol()
{
		return m_cSymbol;
}

char Tile::getDisplaySymbol()
{
	if (getHidden() == true)
		return ' ';
	else if (get_holdsPlayer() == true)
		return getPlayer()->getSymbol();
	else if (get_holdsCreature() == true)
		return getCreature()->getSymbol();
	else if (get_holdsBomb() == true)
		return static_cast<char>(m_ibombCounter + 48);
	else if (get_holdsBombRadius() == true)
		return 'x';
	else if (get_holdsWeapons() == true)
		return getWeaponVec().back()->getSymbol();
	else if (get_holdsArmors() == true)
		return getArmorVec().back()->getSymbol();
	else if (get_holdsConsumables() == true)
		return getConsumableVec().back()->getSymbol();
	else 
		return m_cSymbol;
}

bool Tile::getTraversable()
{
	return m_bTraversable;
}

void Tile::setTraversable(bool bTraversable)
{
	m_bTraversable = bTraversable;
}

bool Tile::getHidden()
{
	return m_bHidden;
}

void Tile::setHidden(bool bHidden)
{
	m_bHidden = bHidden;
}

bool Tile::get_holdsPlayer()
{
	return m_bholdsPlayer;
}
void Tile::set_holdsPlayer(bool bholdsPlayer)
{
	if (bholdsPlayer == false) {setTraversable(true);}
	else {setTraversable(false);}
	m_bholdsPlayer = bholdsPlayer;
}
bool Tile::get_holdsCreature()
{
	return m_bholdsCreature;
}
void Tile::set_holdsCreature(bool bholdsCreature)
{
	if (bholdsCreature == false) {setTraversable(true);}
	else {setTraversable(false);}
	m_bholdsCreature = bholdsCreature;
}
bool Tile::get_holdsArmors()
{
	return m_bholdsArmors;
}
void Tile::set_holdsArmors(bool bholdsArmors)
{
	m_bholdsArmors = bholdsArmors;
}
bool Tile::get_holdsWeapons()
{
	return m_bholdsWeapons;
}
void Tile::set_holdsWeapons(bool bholdsWeapons)
{
	m_bholdsWeapons = bholdsWeapons;
}
bool Tile::get_holdsConsumables()
{
	return m_bholdsConsumables;
}
void Tile::set_holdsConsumables(bool bholdsConsumables)
{
	m_bholdsConsumables = bholdsConsumables;
}

Player * Tile::getPlayer()
{
	return m_Player;
}
void Tile::setPlayer(Player * pPlayer)
{
	m_Player = pPlayer;
	set_holdsPlayer(true);
}
Creature * Tile::getCreature()
{
	return m_Creature;
}
void Tile::setCreature(Creature * cCreature)
{
	m_Creature = cCreature;
	set_holdsCreature(true);
}
void Tile::setArmors(Armor * iArmor)
{
	m_vArmors.push_back(iArmor);
	set_holdsArmors(true);
}
void Tile::pickupArmor()
{
	if(getArmorVec().empty()) {set_holdsArmors(false);}
	else 
	{
		getArmorVec().pop_back();
		if(getArmorVec().empty()) {set_holdsArmors(false);}
	}
}
void Tile::setWeapons(Weapon * iWeapon)
{
	m_vWeapons.push_back(iWeapon);
	set_holdsWeapons(true);
}
void Tile::pickupWeapon()
{
	if(getWeaponVec().empty()) {set_holdsWeapons(false);}
	else 
	{
		getWeaponVec().pop_back();
		if(getWeaponVec().empty()) {set_holdsWeapons(false);}	
	}
}
void Tile::setConsumables(Consumable * iConsumable)
{
	m_vConsumables.push_back(iConsumable);
	set_holdsConsumables(true);
}
void Tile::pickupConsumable()
{
	if(getConsumableVec().empty()) {set_holdsConsumables(false);}
	else 
	{
		getConsumableVec().pop_back();
		if(getConsumableVec().empty()) {set_holdsConsumables(false);}
	}
}
void Tile::set_holdsBomb(bool bholdsBomb)
{
	m_bholdsBomb = bholdsBomb;
}
bool Tile::get_holdsBomb()
{
	return m_bholdsBomb;
}
void Tile::set_holdsBombRadius(bool bholdsBombRadius)
{
	m_bholdsBombRadius = bholdsBombRadius;
}
bool Tile::get_holdsBombRadius()
{
	return m_bholdsBombRadius;
}
void Tile::set_bombCounter(int ibombCounter)
{
	m_ibombCounter = ibombCounter;
}
int Tile::get_bombCounter()
{
	return m_ibombCounter;
}



void Tile::revealHidden()
{
	m_bHidden = false;
}

void Tile::useTemplate(int iTemplate)
{
	if (iTemplate == 0)
	{
		setType("empty space");
		setSymbol(' ');
		setTraversable(false);
	}
	else if (iTemplate == 1)
	{
		setType("floor");
		setSymbol('.');
		setTraversable(true);
	}
	else if (iTemplate == 2)
	{
		setType("hallway");
		setSymbol('#');
		setTraversable(true);
	}
	else if (iTemplate == 3)
	{
		setType("stairs up");
		setSymbol('>');
		setTraversable(true);
	}
	else if (iTemplate == 4)
	{
		setType("stairs down");
		setSymbol('<');
		setTraversable(true);
	}
	else if (iTemplate == 5)
	{
		setType("north wall");
		setSymbol('_');
		setTraversable(false);
	}
	else if (iTemplate == 6)
	{
		setType("east wall");
		setSymbol('|');
		setTraversable(false);
	}
	else if (iTemplate == 7)
	{
		setType("south wall");
		setSymbol('_');
		setTraversable(false);
	}
	else if (iTemplate == 8)
	{
		setType("west wall");
		setSymbol('|');
		setTraversable(false);
	}
	else if (iTemplate == 9)
	{
		setType("Traversable Test");
		setSymbol('X');
		setTraversable(false);
	}
	else
	{
		return;
	}
}

