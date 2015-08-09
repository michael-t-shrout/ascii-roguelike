#ifndef _DungeonLevel_included_
#define _DungeonLevel_included_

#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#include <functional>
#include <string>
#include <vector>
#include "Tile.h"
#include "Player.h"
#include "GenericFactory.h"

using namespace std;

class DungeonLevel
{
public:
	DungeonLevel();
	virtual int getFloor();
	virtual void setFloor(int iFloor);
	virtual int getxIn();
	virtual void setxIn(int ixIn);
	virtual int getyIn();
	virtual void setyIn(int iyIn);
	virtual int getxOut();
	virtual void setxOut(int ixOut);
	virtual int getyOut();
	virtual void setyOut(int iyOut);
	virtual int getnumEnemies();
	virtual void setnumEnemies(int inumEnemies);
	virtual bool getstairsUnlocked();
	virtual void setstairsUnlocked(bool bstairsUnlocked);

	virtual vector<vector<Tile>> &getVector() {return dLevel;}
	//virtual void setVector(vector<vector<Tile>> vLevel);

	virtual void setStart(Player * p1); 	
	virtual void setEnd(Player * p1);
	virtual void spawnEntities();


	virtual void generateLevel();
	virtual string displayLevel();
	virtual bool dTest();
	virtual int randomNumber(int iMax);

private:
	vector<vector<Tile>> dLevel;
	vector<vector<char>> v_cLevel;
	int m_iFloor;
	int m_xIn;
	int m_yIn;
	int m_xOut;
	int m_yOut;
	int m_numEnemies;
	bool m_stairsUnlocked;
	
	
	
};

void markPosition(vector<vector<Tile>> & vLevel, int x, int y);
bool testLevel(vector<vector<Tile>> & vLevel);

#endif

