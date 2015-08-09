#ifndef _Character_included_
#define _Character_included_

#include "Entity.h"

class Character : public Entity
{
public:
	Character();
	int getHealth();
	void setHealth(int iHealth);

	virtual void attack(Character & target);

	virtual void dumpObjectData();
	virtual void dumpObject();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, 
		std::string sValue);

private:
	int m_iHealth;
};

#endif
