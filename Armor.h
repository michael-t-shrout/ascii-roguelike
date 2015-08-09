#ifndef _Armor_included_
#define _Armor_included_

#include "Equipment.h"

class Armor : public Equipment
{
public:
	Armor();
	int getDefenseBonus();
	void setDefenseBonus(int iDefenseBonus);

	virtual void dumpObjectData();
	virtual void dumpObject();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, 
		std::string sValue);

private:
	int m_iDefenseBonus;
};


#endif

