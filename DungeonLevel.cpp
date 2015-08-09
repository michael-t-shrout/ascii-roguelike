#include "DungeonLevel.h"
#include <random>
#include <ctime>
#include <sstream>

#include "parser.h"

#include "Armor.h"
#include "Weapon.h"
#include "Creature.h"
#include "Player.h"
#include "Consumable.h"
#include "Item.h"
#include "Tools.h"



int ijIncrease(int place, int ij)
{
	return place + ij;
}

int ijDecrease(int place, int ij)
{
	return place - ij;
}

// Practicum 8 : Implement this method
void markPosition(vector<vector<Tile>> & vLevel, int x, int y)
{
	if ( y < 0 || y > vLevel.size() )
		return;
	if ( x < 0 || x > vLevel[y].size() )
		return;
	if ( vLevel[y][x].getTraversable() == false)
		return; 

	vLevel[y][x].useTemplate(9);
	
	markPosition( vLevel, x+1, y);
	markPosition( vLevel, x-1, y);
	markPosition( vLevel, x, y+1);
	markPosition( vLevel, x, y-1);
}

bool testLevel(vector<vector<Tile>> & vLevel)
{
	// Display the initial state
	int numBadTiles = 0;
	//cout << "Initial state: " << endl;
	//cout << vLevel.size() << " " << vLevel[1].size() << endl;
	/*
	for (int i = 0; i < vLevel.size(); i++)
	{
		for (int j = 0; j < vLevel[i].size(); j++)
		{ 
			cout << vLevel[i][j].getSymbol();
		}
		cout << endl;
	}
	cout << endl;
	*/

	int x = -1;
	int y = -1;

	// pick a starting position
	for( int i = 0; i < vLevel.size(); i++ )
	{
		for( int j = 0; j < vLevel[i].size(); j++ )
		{
			if( vLevel[i][j].getTraversable() == true)
			{
				// Starting position just has to be a room or
				// tunnel tile
				x = j;
				y = i;
				
			}
		}
	}

	if( x == -1 )
	{
		//cout << "Unable to find starting position!" << endl;
		return false;
	}
	
	// Call the function which actually marks the tiles -- it should mark
	// the starting tile, then any adjacent to it, etc -- so after it's done,
	// everything that can be connected to the starting tile should be
	// marked.
	markPosition(vLevel, x, y);

	bool bCorrect = true;

	//cout << endl << "Marked state: " << endl;
	// Outer loop
	for( auto itOuter = vLevel.begin(); itOuter != vLevel.end(); itOuter++ )
	{
		// Inner loop
		for( auto itInner = (*itOuter).begin(); itInner != (*itOuter).end(); itInner++ )
		{
			//cout << (*itInner).getSymbol();


			// Now, test if it's a room/tunnel tile -- if it's still
			// one after we've 
			if( (*itInner).getSymbol() == '.' || (*itInner).getSymbol() == '#' )
			{
				bCorrect = false;
				numBadTiles++;
			}
		}

		//cout << endl;
	}

	//cout << endl;

	if( !bCorrect )
	{
		
		//cout << "Unreached room/tunnel tile detected!" << endl;
		//cout << numBadTiles << " total unreachable tiles... " << endl;
		//cout << "Bad Level" << endl;
		
	}
	else
	{
		//cout << "Good Level" << endl;
	}


	return bCorrect;

}

DungeonLevel::DungeonLevel()
{
	m_iFloor = 0;
	m_stairsUnlocked = false;
}

int DungeonLevel::getFloor()
{
	return m_iFloor;
}

void DungeonLevel::setFloor(int iFloor)
{
	m_iFloor = iFloor;
}

int DungeonLevel::getxIn()
{
	return m_xIn;
}

void DungeonLevel::setxIn(int ixIn)
{
	m_xIn = ixIn;
}
int DungeonLevel::getyIn()
{
	return m_yIn;
}
void DungeonLevel::setyIn(int iyIn)
{
	m_yIn = iyIn;
}
int DungeonLevel::getxOut()
{
	return m_xOut;
}
void DungeonLevel::setxOut(int ixOut)
{
	m_xOut = ixOut;
}
int DungeonLevel::getyOut()
{
	return m_xOut;
}
void DungeonLevel::setyOut(int iyOut)
{
	m_yOut = iyOut;
}
int DungeonLevel::getnumEnemies()
{
	return m_numEnemies;
}
void DungeonLevel::setnumEnemies(int inumEnemies)
{
	m_numEnemies = inumEnemies;
}
bool DungeonLevel::getstairsUnlocked()
{
	return m_stairsUnlocked;
}
void DungeonLevel::setstairsUnlocked(bool bstairsUnlocked)
{
	m_stairsUnlocked = bstairsUnlocked;
}

/*vector<vector<Tile>> DungeonLevel::getVector()
{
	return dLevel;
}
*/
void DungeonLevel::generateLevel()
{
	//cout << "generating Warehouse..." << endl;
	mt19937 mt;
	mt.seed( time(NULL) );
	unsigned int roomWidth = mt();
	unsigned int roomHeight = mt();
	unsigned int NSRandom = mt();
	unsigned int EWRandom = mt();
	unsigned int setNSAnchor = mt();
	unsigned int setEWAnchor = mt();
	int NSAnchor = 0;
	int EWAnchor = 0;
	int oldNSAnchor = 0;
	int oldEWAnchor = 0;
	int pathNSTunnel = 0;
	int pathEWTunnel = 0;
	int stairInNS = 0;
	int stairInEW = 0;
	int stairOutNS = 0;
	int stairOutEW = 0;
	int totalTiles = 0;
	bool roomThere = false;
	int numTries = 0;

	function<int(int,int)> itJ; 
	function<int(int,int)> itI;

	dLevel.clear();
	int num_of_row = 20;
	int num_of_col = 79;
	Tile initValue;
	initValue.useTemplate(0);
	dLevel.resize( num_of_row, vector<Tile>(num_of_col, initValue) );
	v_cLevel.resize( num_of_row, vector<char>(num_of_col, ' ') );

	while (totalTiles < 250)
	{
		roomWidth = 0, roomHeight = 0, NSRandom = 100, EWRandom = 100;
		if (numTries > 5000)
		{
			numTries = 0;
			totalTiles = 0;
			for (int i = 0; i < dLevel.size(); i++)
			{
				for (int j = 0; j < dLevel[i].size(); j++)
				{
					dLevel[i][j].useTemplate(0);
				}
			}
		}
		roomThere = false;
		while (((NSRandom + roomHeight) > 17)||((EWRandom + roomWidth) > 76))
		{

			NSRandom = randomNumber(20);
			EWRandom = randomNumber(79);
			while ((roomWidth < 4)||(roomHeight < 4))
			{
				roomWidth = randomNumber(10) + 1;
				roomHeight = randomNumber(10) + 1;
			}
		}
		

		for (int i = 0; i <= (roomHeight + 2); i++)
		{
			for(int j = 0; j <= (roomWidth + 2); j++)
			{
				if ((dLevel[NSRandom+i][EWRandom+j].getSymbol() == '.')||(dLevel[NSRandom+i][EWRandom+j].getSymbol() == '#'))
				{
					roomThere = true;
					numTries++;
				}
			}
		}

		if (roomThere == false)
		{
			
			for (int i = 0; i <= (roomHeight + 1); i++)
			{
				for (int j = 0; j <= (roomWidth + 1); j++)
				{
					if (i == 0)
					{
						dLevel[(NSRandom + i)][(EWRandom + j)].useTemplate(5);
					}
					else if (j == 0)
					{
						dLevel[(NSRandom + i)][(EWRandom + j)].useTemplate(8);
					}
					else if (j == (roomWidth + 1))
					{
						dLevel[(NSRandom + i)][(EWRandom + j)].useTemplate(6);
					}
					else if (i == (roomHeight + 1))
					{
						dLevel[(NSRandom + i)][(EWRandom + j)].useTemplate(7);
					}
					else
					{
						dLevel[(NSRandom + i)][(EWRandom + j)].useTemplate(1);
					}
					
					if (totalTiles == 0)
					{
						dLevel[(NSRandom + i)][(EWRandom + j)].revealHidden();
					}
				}
			}
				oldNSAnchor = NSAnchor;
				oldEWAnchor = EWAnchor;
				setNSAnchor = randomNumber(roomHeight);
				NSAnchor = setNSAnchor + NSRandom + 1;
				setEWAnchor = randomNumber(roomWidth);
				EWAnchor = setEWAnchor + EWRandom + 1;
		
				
				if (totalTiles == 0)
				{
					stairInNS = NSAnchor;
					stairInEW = EWAnchor;
				}
				if ((totalTiles + (roomHeight * roomWidth)) >= 250)
				{
					stairOutNS = NSAnchor;
					stairOutEW = EWAnchor;
				}
								
				pathNSTunnel = (NSAnchor - oldNSAnchor);
				pathEWTunnel = (EWAnchor - oldEWAnchor);

				if (totalTiles != 0)
				{
					if ((pathNSTunnel <= 0)&&(pathEWTunnel <= 0))
					{
						itI = ijIncrease;
						itJ = ijIncrease;
					}
					if ((pathNSTunnel >= 0)&&(pathEWTunnel <= 0))
					{
						itI = ijDecrease;
						itJ = ijIncrease;
					}
					if ((pathNSTunnel <= 0)&&(pathEWTunnel >= 0))
					{
						itI = ijIncrease;
						itJ = ijDecrease;
					}
					if ((pathNSTunnel >= 0)&&(pathEWTunnel >= 0))
					{
						itI = ijDecrease;
						itJ = ijDecrease;
					}
					
					for (int i = 0; i <= abs(pathNSTunnel); i++)
					{
						if (!((dLevel[itI(NSAnchor,i)][EWAnchor].getSymbol() == '_')&&(dLevel[itI(NSAnchor,(i+1))][EWAnchor].getSymbol() == '.')))
						{								
							if (dLevel[itI(NSAnchor,i)][EWAnchor].getSymbol() != '.')
							{
								if ((dLevel[itI(NSAnchor,i)][EWAnchor].getSymbol() == '_')&&(i != abs(pathNSTunnel)))
								{
									if (dLevel[itI(NSAnchor,i+1)][EWAnchor].getSymbol() == '|')
									{
										dLevel[itI(NSAnchor,i)][EWAnchor].useTemplate(2);
										dLevel[itI(NSAnchor,i+1)][EWAnchor].useTemplate(1);
										i =+ abs(pathNSTunnel);
									}
									else
									{
									dLevel[itI(NSAnchor,i)][EWAnchor].useTemplate(1);
									}
								}
								if (dLevel[itI(NSAnchor,i)][EWAnchor].getSymbol() == ' ')
								{
									dLevel[itI(NSAnchor,i)][EWAnchor].useTemplate(2);
								}
								if (dLevel[itI(NSAnchor,i)][EWAnchor].getSymbol() == '|')
								{
									dLevel[itI(NSAnchor,i)][EWAnchor].useTemplate(2);
									dLevel[itI(NSAnchor,(i+1))][EWAnchor].useTemplate(1);
									i =+ abs(pathNSTunnel);
								}
							}
						}
						else
						{
							dLevel[itI(NSAnchor,i)][EWAnchor].useTemplate(1);
							i = abs(pathNSTunnel);
						}
					}
					for (int j = 0; j <= abs(pathEWTunnel); j++)
					{
						
						if (!((dLevel[oldNSAnchor][itJ(EWAnchor,j)].getSymbol() == '|')&&(dLevel[oldNSAnchor][itJ(EWAnchor,j+1)].getSymbol() == '.')))
						{
							if (dLevel[oldNSAnchor][itJ(EWAnchor,j)].getSymbol() != '.')
							{
								if (dLevel[oldNSAnchor][itJ(EWAnchor,j)].getSymbol() == '|')
								{
									dLevel[oldNSAnchor][itJ(EWAnchor,j)].useTemplate(1);
									if (dLevel[oldNSAnchor][itJ(EWAnchor,j+1)].getSymbol() == '_')
									{
										dLevel[oldNSAnchor][itJ(EWAnchor,j)].useTemplate(2);
										dLevel[oldNSAnchor - 1][itJ(EWAnchor,j)].useTemplate(1);
										j = abs(pathEWTunnel);
									}
								}
								if (dLevel[oldNSAnchor][itJ(EWAnchor,j)].getSymbol() == ' ')
								{
									dLevel[oldNSAnchor][itJ(EWAnchor,j)].useTemplate(2);
								}
								if (dLevel[oldNSAnchor][itJ(EWAnchor,j)].getSymbol() == '_')
								{
									if ((dLevel[oldNSAnchor][itJ(EWAnchor,j-1)].getSymbol() == '_')||(dLevel[oldNSAnchor][itJ(EWAnchor,j-1)].getSymbol() == '|'))
									{
										while ((dLevel[oldNSAnchor][itJ(EWAnchor,j+1)].getSymbol() == '_')||(dLevel[oldNSAnchor][itJ(EWAnchor,j+1)].getSymbol() == '|'))
										{
											j++;
											if (!((dLevel[oldNSAnchor][itJ(EWAnchor,j+1)].getSymbol() == '_')||(dLevel[oldNSAnchor][itJ(EWAnchor,j+1)].getSymbol() == '|')))
											{
												dLevel[oldNSAnchor][itJ(EWAnchor,j-1)].useTemplate(1);
												dLevel[oldNSAnchor][itJ(EWAnchor,j)].useTemplate(2);
											}
											else if (dLevel[oldNSAnchor][itJ(EWAnchor,j+2)].getSymbol() == '.')
											{
												dLevel[oldNSAnchor][itJ(EWAnchor,j-1)].useTemplate(1);
												dLevel[oldNSAnchor][itJ(EWAnchor,j)].useTemplate(2);
												dLevel[oldNSAnchor][itJ(EWAnchor,j+1)].useTemplate(1);
											}
											else if ((dLevel[oldNSAnchor+1][itJ(EWAnchor,j)].getSymbol() == '|')||(dLevel[oldNSAnchor-1][itJ(EWAnchor,j)].getSymbol() == '|'))
											{
												if ((dLevel[oldNSAnchor+1][itJ(EWAnchor,j)].getSymbol() == '.')||(dLevel[oldNSAnchor-1][itJ(EWAnchor,j)].getSymbol() == '.'))
												{
													dLevel[oldNSAnchor][itJ(EWAnchor,j-1)].useTemplate(1);
													dLevel[oldNSAnchor][itJ(EWAnchor,j)].useTemplate(1);
												}
												if ((dLevel[oldNSAnchor+1][itJ(EWAnchor,j+1)].getSymbol() == '.')||(dLevel[oldNSAnchor-1][itJ(EWAnchor,j+1)].getSymbol() == '.'))
												{
													dLevel[oldNSAnchor][itJ(EWAnchor,j-1)].useTemplate(1);
													dLevel[oldNSAnchor][itJ(EWAnchor,j)].useTemplate(2);
													dLevel[oldNSAnchor][itJ(EWAnchor,j+1)].useTemplate(1);
												}
											}
										}
									}
									else
									{
										dLevel[oldNSAnchor][itJ(EWAnchor,j)].useTemplate(2);
										dLevel[oldNSAnchor][itJ(EWAnchor,j+1)].useTemplate(1);
										j = abs(pathEWTunnel);
									}
								}
							}
						}
						else
						{
							dLevel[oldNSAnchor][itJ(EWAnchor,j)].useTemplate(1);
							j = abs(pathEWTunnel);
						}
					}
				}
				//Un-Comment to see room-by-room progress with Anchor points
				/*
				for (int i = 0; i <= 19; i++)
				{		
					for (int j = 0; j <= 78; j++)
					{	
						if (((i==oldNSAnchor)&&(j==oldEWAnchor))||((i==NSAnchor)&&(j==EWAnchor)))
							cout << 'A';
						else
							cout << dLevel[i][j].getSymbol();
					}
					cout << endl;
				}
				*/
					totalTiles += (roomHeight * roomWidth);
				}
			}
		
			dLevel[stairInNS][stairInEW].useTemplate(4);
			setxIn(stairInNS);
			setyIn(stairInEW);
			dLevel[stairOutNS][stairOutEW].useTemplate(3);
			setxOut(stairOutNS);
			setyOut(stairOutEW);
			setnumEnemies(0);
					
}

string DungeonLevel::displayLevel()
{
	ostringstream level;
	for (int i = 0; i <= 19; i++)
	{
		for (int j = 0; j <= 78; j++)
		{ 
			level << dLevel[i][j].getDisplaySymbol();
		}
		level << endl;
	}
	return level.str();
}

void DungeonLevel::setStart(Player * p1)
{
	dLevel[m_xIn][m_yIn].setPlayer(p1);
	p1->setPosX(m_xIn);
	p1->setPosY(m_yIn);
}

void DungeonLevel::setEnd(Player * p1)
{
	dLevel[m_xOut][m_yOut].setPlayer(p1);
	p1->setPosX(m_xOut);
	p1->setPosY(m_yOut);
}

void DungeonLevel::spawnEntities()
{
	int quota = 0;
	int cHealth = 0;
	if (getFloor() == 4)
	{
		while (quota < (4 * (getFloor() + 1)))
		{
			for (int i = 8; i < getVector().size(); i++)
			{
				for (int j = 0; j < getVector()[i].size(); j++)
				{
					if((getVector()[i][j].getTraversable() == true)&&(!((getVector()[i][j].getType()=="stairs up")||(getVector()[i][j].getType()=="stairs down"))))
					{
						if (randomNumber(150) == 1)
						{
							Creature * pCreature = GenericFactory::instance().generateSmallCreature(500);
							cHealth = pCreature->getHealth();
							pCreature->setHealth((cHealth * getFloor()) + (cHealth * (getFloor() - 1)));
							getVector()[i][j].setCreature(pCreature);
							getVector()[i][j].getCreature()->setPosX(i);
							getVector()[i][j].getCreature()->setPosY(j);
							quota++;
						}
					}
				}
			}
		}
	}
	else if (getFloor() == 8)
	{
		while (quota < 4)
		{
			for (int i = 8; i < getVector().size(); i++)
			{
				for (int j = 0; j < getVector()[i].size(); j++)
				{
					if((getVector()[i][j].getTraversable() == true)&&(!((getVector()[i][j].getType()=="stairs up")||(getVector()[i][j].getType()=="stairs down"))))
					{
						if (randomNumber(300) == 1)
						{
							Creature * pCreature = GenericFactory::instance().generateBigCreature(500);
							//cHealth = pCreature->getHealth();
							//pCreature->setHealth((cHealth * getFloor()) + (cHealth * (getFloor() - 1)));
							getVector()[i][j].setCreature(pCreature);
							getVector()[i][j].getCreature()->setPosX(i);
							getVector()[i][j].getCreature()->setPosY(j);
							quota++;
						}
					}
				}
			}
		}
	}
	else
	{		
		for (int i = 0; i < getVector().size(); i++)
		{
			for (int j = 0; j < getVector()[i].size(); j++)
			{
				if (getVector()[i][j].get_holdsCreature() == true)
				{
					getVector()[i][j].setCreature(NULL);
					getVector()[i][j].set_holdsCreature(false);
				}
			}
		}

	
	//cout << "Floor: " << getFloor() << endl;
	

		while (quota < (4 * (getFloor() + 1)))
		{
		//cout << "Floor: " << getFloor() << endl;
			for (int i = 0; i < getVector().size(); i++)
			{
				for (int j = 0; j < getVector()[i].size(); j++)
				{
					if((getVector()[i][j].getTraversable() == true)&&(!((getVector()[i][j].getType()=="stairs up")||(getVector()[i][j].getType()=="stairs down"))))
					{
						if (randomNumber(150) == 1)
						{
							//cout << endl;
							//cout << i << " setting creature" << endl;
							Creature * pCreature = GenericFactory::instance().generateSmallCreature(500);
							cHealth = pCreature->getHealth();
							pCreature->setHealth((cHealth * getFloor()) + (cHealth * (getFloor() - 1)));
							//pCreature->dumpObject();
							getVector()[i][j].setCreature(pCreature);
							getVector()[i][j].getCreature()->setPosX(i);
							getVector()[i][j].getCreature()->setPosY(j);

							//cout << "creature set" << endl;
							quota++;
							//cout << "quota is: " << quota << endl;
						}
						if (randomNumber(250) == 1)
						{
							//cout << "setting item" << endl;
							if(randomNumber(3) == 0)
							{
								Armor * pArmor = GenericFactory::instance().generateArmor();
								pArmor->setDefenseBonus(pArmor->getDefenseBonus() + getFloor() + 1);
								pArmor->setValue(pArmor->getValue() * getFloor());
								//pArmor->dumpObject();
								getVector()[i][j].setArmors(pArmor);
								getVector()[i][j].getArmorVec().back()->setPosX(i);
								getVector()[i][j].getArmorVec().back()->setPosY(j);
							}
							if(randomNumber(3) == 1)
							{
								Weapon * pWeapon = GenericFactory::instance().generateWeapon();
								if (pWeapon->getWeaponType() == 3)
								{
									delete pWeapon;
								}
								else
								{
									pWeapon->setAttackBonus(pWeapon->getAttackBonus() * getFloor());
									pWeapon->setValue(pWeapon->getValue() * getFloor());
								//pWeapon->dumpObject();
									getVector()[i][j].setWeapons(pWeapon);
									getVector()[i][j].getWeaponVec().back()->setPosX(i);
									getVector()[i][j].getWeaponVec().back()->setPosY(j);
								}
							}
							if(randomNumber(3) == 3)
							{
								Consumable * pConsumable = GenericFactory::instance().generateConsumable();
								if (pConsumable->getWeight() == 0)
								{
									delete pConsumable;
								}
								else
								{
									//pConsumable->dumpObject();
									getVector()[i][j].setConsumables(pConsumable);
									getVector()[i][j].getConsumableVec().back()->setPosX(i);
									getVector()[i][j].getConsumableVec().back()->setPosY(j);
								}
							}
						}
					}
				}
			}
		}
	}
	setnumEnemies(getnumEnemies() + quota);
}


bool DungeonLevel::dTest()
{
	vector<vector<Tile>> vLevel = getVector();
	return testLevel(vLevel);	
}

int DungeonLevel::randomNumber(int iMax)
 {
     static mt19937 mt(time(NULL));
     return mt() % iMax;
 }



