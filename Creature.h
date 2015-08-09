#ifndef _Creature_included_
#define _Creature_included_
#include "Character.h"
#include "Player.h"

class Player;

class Creature : public Character
{
public:
	Creature();
	bool isHostile();
	void setHostile(bool bHostile);

	virtual string attack(Player * target, int dmg, int random);

	virtual void dumpObjectData();
	virtual void dumpObject();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, 
		std::string sValue);

private:
	bool m_bHostile;
};

#endif

