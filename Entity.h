#ifndef _Entity_included_
#define _Entity_included_

#include <string>
using namespace std;

#include "XMLSerializable.h"

class Entity : public XMLSerializable
{
public:
	Entity();
	virtual std::string getName();
	virtual void setName(std::string sString);
	virtual char getSymbol();
	virtual void setSymbol(char cSymbol);
	virtual int getPosX();
	virtual void setPosX(int iPosX);
	virtual int getPosY();
	virtual void setPosY(int iPosY);

	
	virtual void dumpObjectData();
	virtual void dumpObject();
	virtual void writeFragment(std::ostream & output);
	virtual void writeDataAsFragment(std::ostream & output);
	virtual void setElementData(std::string sElementName, 
		std::string sValue);

private:
	std::string m_sName;
	char m_cSymbol;
	int m_iPosX;
	int m_iPosY;
};

#endif

