#ifndef _Equipment_included_
#define _Equipment_included_

#include "Item.h"
#include <string>

class Equipment : public Item
{
public:
	std::string getSlot();
	void setSlot(std::string sSlot);

	virtual void dumpObjectData();
	virtual void dumpObject();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, 
		std::string sValue);

private:
	std::string m_sSlot;
};

#endif
