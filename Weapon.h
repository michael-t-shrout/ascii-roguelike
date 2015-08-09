#ifndef _Weapon_included_
#define _Weapon_included_

#include "Equipment.h"

class Weapon : public Equipment
{
public:
	Weapon();
	int getAttackBonus();
	void setAttackBonus(int iAttackBonus);
	int getWeaponType();
	void setWeaponType(int iWeaponType);

	virtual void dumpObjectData();
	virtual void dumpObject();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, 
		std::string sValue);

private:
	int m_iAttackBonus;
	int m_iWeaponType;
};

#endif

