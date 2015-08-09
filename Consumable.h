#ifndef _Consumable_included_
#define _Consumable_included_

#include "Item.h"
#include "Character.h"

class Consumable : public Item
{
public:
	Consumable();
	
	int getQuantity();
	void setQuantity(int iQuantity);

	virtual void use(Character & user);

	virtual void dumpObjectData();
	virtual void dumpObject();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, 
		std::string sValue);

private:
	int m_iQuantity;
};

#endif
