#include "Game.h"
#include <array>
#include <string>
#include <iostream>
#include <iomanip>
#include "Coord.h"
#include "Utilities.h"
#include "Railroads.h"
#include "CommunitySpace.h"
#include "ChanceSpace.h"
#include "TaxSpace.h"
#include <sstream>
#include "EmptySpace.h"
#include <typeinfo>


using namespace std;



Game::Game(int numPlayers)
{
	for (int i = 0; i < numPlayers; ++i)
	{
		this->playerList.push_back(Player());
	}
	initBoard();
	this->numPlayers = numPlayers;
	this->engine.seed(static_cast<unsigned int>(time(0)));
}

int Game::getNumPlayers()
{
	return numPlayers;
}
Game::~Game()
{
	delete &boardArray;
}
void Game::display(int playerNum)
{
	Player* displayPlayer = &(this->playerList[playerNum]);
	system("cls");
	array<string, 11> line1{"FREE", "DWKA", "CHAN", "DWEP", "DWAK", "TRWR", "VCVC", "VCCD", "UTLL", "VCTE", "GOJA"};
	array<string, 11> line2{"BRTU","","","","","","","","","","EMAL" };
	array<string, 11> line3{"BRCC","","","","","","","","","","EMNU"};
	array<string, 11> line4{"COMC","","","","","","","","","","COMC" };
	array<string, 11> line5{"BRCB","","","","","","","","","","EMMA" };
	array<string, 11> line6{"TREP","","","","","","","","","","TRSR" };
	array<string, 11> line7{"WEVA","","","","","","","","","","CHAN" };
	array<string, 11> line8{"WEKB","","","","","","","","","","VENA" };
	array<string, 11> line9{"UTEG","","","","","","","","","","LTAX" };
	array<string, 11> line10{"WEWP","","","","","","","","","","VELO" };
	array<string, 11> line11{"JAIL","TKLA","TKZA","CHAN","TKKH","TRUW","ITAX","KIPR","COCH","KIKI","GO"};
	array<array<string,11>, 11> dummyBoard{line1,line2,line3,line4,line5,line6,line7,line8,line9,line10,line11};
	cout << "----------------------------------------------------------------------------------------" << endl;


	array<string, 11> line1p{};
	array<string, 11> line2p{};
	array<string, 11> line3p{};
	array<string, 11> line4p{};
	array<string, 11> line5p{};
	array<string, 11> line6p{};
	array<string, 11> line7p{};
	array<string, 11> line8p{};
	array<string, 11> line9p{};
	array<string, 11> line10p{};
	array<string, 11> line11p{};
	array<array<string, 11>, 11> playerArray{ line1p,line2p,line3p,line4p,line5p,line6p,line7p,line8p,line9p,line10p,line11p };
	Coord playerCoord;
	for (Player p: this->playerList)
	{
		playerCoord = translateLoc(p.getLoc());
		playerArray[playerCoord.getY()][playerCoord.getX()] += "x";


	}
	Space* curSpace;
	curSpace = boardArray[displayPlayer->getLoc()];
	array<string, 11> titleArray = curSpace->getTitleDeed();
	
	for (int i = 0; i < 11; ++i)
	{
		array<string, 11> line = dummyBoard[i];

		for (int k = 0; k < 11; ++k) //printing rows of the board
		{
			if (i == 0 || i == 10)
			{
				cout << "| " << setw(4) << line[k] << " |"; //printing top and bottom rows
			}
			else
			{
				if (k == 0 || k == 10)
				{
					cout << "| " << setw(4) << line[k] << " |"; //printing all center rows
				}
				else
				{
					cout << "        "; //printing empty spaces in between
				}
				
			}
			
			
		}
		

		cout << titleArray[i];
		
		if (i == 0 || i == 10)
		{
			cout << endl; 
			for (int j = 0; j < 11; ++j)
			{
				cout  << "|" << setw(6) << playerArray[i][j] << "|"; //print player icon if they exist
			}
		}
		else
		{
			cout << endl << "|" << setw(6) << playerArray[i][0] << "|" << setw(73) << "|" << setw(6) << playerArray[i][10] << "|"; //print player icon if they exist
		}
		
		cout << endl;
		if (i == 0 || i ==9 || i == 10)
		{
			cout << "----------------------------------------------------------------------------------------" << endl; //displaying border

		}
		else
		{
			cout << "--------                                                                        --------" << endl; //displaying border
		}
	}
}

Coord Game::translateLoc(int loc)
{
	int x = 0;
	int y = 0;
	if (loc >= 0 && loc < 11)
	{
		y = 10;
		x = 10-loc;
		return Coord(x, y);
	}
	else if (loc >= 11 && loc < 21)
	{
		x = 0;
		y = 20-loc;
	}
	else if (loc >= 21 && loc < 31)
	{
		y = 0;
		x = loc-20;
	}

	else if (loc >= 31)
	{
		x = 10;
		y = loc - 30;
	}

	return Coord(x, y);
}


void Game::move(int playerNum, int numSpaces)
{
	int newLoc;
	Player* p = getPlayer(playerNum);
	if (p->getLoc() + numSpaces > 39)
	{
		newLoc = p->getLoc() + numSpaces - 40;
		p->addMoney(200);
		system("pause");
	}
	else
	{
		newLoc = p->getLoc() + numSpaces;
	}
	p->setLoc(newLoc);
}

void Game::move(Player* p, int numSpaces, bool passGo = true)
{
	int newLoc;
	if (p->getLoc() + numSpaces > 39)
	{
		newLoc = p->getLoc() + numSpaces - 40;
		

		if (passGo == true)
		{
			p->addMoney(200);
		}
		else
		{
			//do nothing
		}
		system("pause");

	}

	else
	{
		newLoc = p->getLoc() + numSpaces;
	}
	p->setLoc(newLoc);

	//handle all the fuckaroo

	Space* curSpace = boardArray[newLoc];
	string spaceType = curSpace->getSpaceType();
	if (spaceType == "Empty")
	{
		if (curSpace->getName() == "Go To Jail")
		{
			p->jail();
			p->resetDoubles();
		}
		else if (curSpace->getName() == "Go")
		{
			p->addMoney(200);
		}
	}
	else if (spaceType == "Railroad" || spaceType == "Property" || spaceType == "Utilities")
	{
		if (curSpace->getOwned() == false)
		{
			//buyProperty(p);
		}
		else if (spaceType == "Railroad" && curSpace->getOwner() == p->getName())
		{
			//move to another railroad or nein?
			
		}
		else
		{
			//chargeRent
		}
	}
	else if (spaceType == "Tax")
	{
		p->addMoney(-200);
	}

	else if (spaceType == "Chance" || spaceType == "Community")
	{
		//apply card effects

	}

}


Player* Game::getPlayer(int playerNum)
{
	return &(this->playerList[playerNum]);
}

void Game::initBoard()
{
	
	//purple
	EmptySpace* go =new  EmptySpace("Go");
	Properties* kiki  = new Properties("Kislev");
	CommunitySpace* com1 = new CommunitySpace("Community Chest");
	Properties* kipr = new Properties("Praag");
	TaxSpace* itax = new TaxSpace("Income Tax");
	Railroads* truw = new Railroads("Underways");

	//light blue
	Properties* tkkh = new Properties("Khemri");
	//boardArray[6] = Properties("Khemri");
	ChanceSpace* chan1 = new ChanceSpace("Chance");
	Properties* tkza = new Properties("Zandri");
	Properties* tkla = new Properties("Lahmia");
	EmptySpace* jail = new EmptySpace("Jail");

	//pink
	Properties* wewp = new Properties("Waterfall Palace");
	Utilities* uteg = new Utilities("Engineer's Guild");
	Properties* wekb = new Properties("King's Blade");
	Properties* weva = new Properties("Vaul's Anvil");
	Railroads* trep =  new Railroads("East Paths");

	//orange
	Properties* brcb = new Properties("Castle Bastonne");
	CommunitySpace* com2 = new CommunitySpace("Community Chest");
	Properties* brcc = new Properties("Castle Couronne");
	Properties* brtu = new Properties("Turin");
	EmptySpace* free = new EmptySpace("Free Parking");

	//red
	Properties* dwka = new Properties("Karak Kadrin");
	ChanceSpace* chan2 = new ChanceSpace("Chance");
	Properties* dwep = new Properties("Karak Eight-Peaks");
	Properties* dwak = new Properties("Karaz-a-Karak");
	Railroads* trwr = new Railroads("World Roots");

	//yellow
	Properties* vcvc = new Properties("Castle Von Carstein");
	Properties* vccd = new Properties("Castle Drakenhoff");
	Utilities* utll = new Utilities("Libraries of Lothern");
	Properties* vcte = new Properties("Castle Templehoff");
	EmptySpace* tojail = new EmptySpace("Go To Jail");

	//green
	Properties* emal = new Properties("Altdorf");
	Properties* emnu = new Properties("Nuln");
	CommunitySpace* com3 = new CommunitySpace("Community Chest");
	Properties* emma = new Properties("Marienburg");
	Railroads* trsr = new Railroads("Shadow Realm");

	//dark blue
	ChanceSpace* chan3 = new ChanceSpace("Chance");
	Properties* vena = new Properties("Naggarond");
	TaxSpace* ltax = new TaxSpace("Luxury Tax");
	Properties* velo = new Properties("Lothern");

	array<Space*, 40> tempBoardArray{ go,kiki,com1,kipr,itax,truw,tkkh,chan1,tkza,tkla,jail,wewp,uteg,wekb,weva,trep,brcb,com2,brcc,brtu,free,dwka,chan2,dwep,
									dwak,trwr,vcvc,vccd,utll,vcte,tojail,emal,emnu,com3,emma,trsr,chan3,vena,ltax,velo };

	Space builtinBoardArray[40];

	for (int i = 0; i < 40; ++i)
	{
		boardArray[i] = tempBoardArray[i];
		
	}
}

void Game::displayMenu()
{
	cout << "1 - Open Cheat Menu" << endl;
	cout << "2 - Trade" << endl;
	cout << "3 - Mortgage Property" << endl;
	cout << "4 - Use Card" << endl;
	cout << "5 - End Your Turn";
}

void Game::cheatMenu(Player* p)
{
	system("cls");
	cout << "1 - Add or Subtract Money from Yourself" << endl;
	cout << "2 - Add or Subtract Money from a Player by Player # " << endl;
	cout << "3 - Move yourself" << endl;
	cout << "4 - Move another player" << endl;
	cout << "5 - Draw Community Chest Card" << endl;
	cout << "6 - Draw Chance Card" << endl;
	cout << "7 - Draw Special Card" << endl;
	cout << "8 - Un-Mortgage all your properties" << endl;

	int userChoice = 0;
	while (userChoice < 1 || userChoice > 8)
	{
		cout << "Enter Menu Choice: ";
		cin >> userChoice;
	}

	if (userChoice == 1)
	{
		int money;
		cout << "Add or Subtract how much money? (Use a negative number to subtract): ";
		cin >> money;
		p->addMoney(money);
		cout << "You now have: $" << p->showMoney();

	}
	else if (userChoice == 2)
	{
		for (int i = 0; i < numPlayers; ++i)
		{
			cout << "(" << i << ") " << playerList[i].getName() << endl;
		}
		int player = 0;
		cout << "Change money for which player? ";
		cin >> player;
		int money;
		cout << "Add or Subtract how much money? (Use a negative number to subtract): ";
		cin >> money;
		Player* otherPlayer = getPlayer(player);
		otherPlayer->addMoney(money);
		cout << "Player: " << player <<  " now has: $" << otherPlayer->showMoney();
	}
	else if (userChoice == 3)
	{
		int moveLen = 0;
		cout << "Move how many spaces? ";
		cin >> moveLen;
		move(p, moveLen);
		cout << "Player now at space: " << p->getLoc() + 1;
	}
	else if (userChoice = 4)
	{
		for (int i = 0; i < numPlayers; ++i)
		{
			cout << "(" << i << ") " << playerList[i].getName() << endl;
		}	int player = 0;
		cout << "Change position for which player? ";
		cin >> player;
		int moveLen = 0;
		cout << "Move how many spaces? ";
		cin >> moveLen;
		move(player, moveLen);
		cout << "Player now at space: " << getPlayer(player)->getLoc() + 1;
	}
	else if (userChoice == 5)
	{
		//draw Community Chest Card
	}

	else if (userChoice == 6)
	{
		//draw chance card
	}
	else if (userChoice == 7)
	{
		//draw special card
	}
	else if (userChoice == 8)
	{
		vector<Space*> propList = p->getProperties();
		for (int i = 0; i < sizeof(propList); ++i)
		{
			propList[i]->unMort();
		}
		cout << "All Properties no longer mortgaged";
	}
}


void Game::displayPlayer(Player* p)
{
	cout << "Current Money: $" << p->showMoney() << endl;
}

unsigned int Game::rollDie()
{
	
	uniform_int_distribution<unsigned int> randomInt{ 1,6 };
	unsigned int dieRoll = randomInt(this->engine);
	return dieRoll;
}

bool Game::doubles(Player* p)
{
	p->addDouble();
	int numDouble = p->getDoubles();
	if (numDouble >= 3 && p->getJailedState()==false)
	{
		p->resetDoubles();
		p->jail();
		return true;
	}
	else if (numDouble >= 3 && p->getJailedState() == true)
	{
		p->resetDoubles();
		p->removeFromJail();
		return true; 
	}
	else 
	{
		return false;
	}
}

void Game::mortgage(Player* p)
{
	vector<Space*> propList(0);
	
	propList= p->getProperties();
	int dataCount = 0;
	for (Space* x : propList)
	{
		++dataCount;
	}
	vector<Space*> unMortgagedPropList(0);
	int counter = 0;
	int sizeProp = dataCount;
	if (sizeProp > 0)
	{
		for (int i = 0; i < sizeof(propList); ++i)
		{
			if (propList[i]->getMort() == false)
			{
				unMortgagedPropList.push_back(propList[i]);
			}
		}
	}
	if (sizeof(unMortgagedPropList) == 0 || dataCount == 0)
	{
		cout << endl;
		cout << "No Un-Mortgaged Properties Available";
		system("pause");
	}
	else
	{
		bool done = false;
		while (!done)
		{
			for (int i = 0; i < sizeof(unMortgagedPropList); ++i)
			{
				cout << "(" << i << ")" << unMortgagedPropList[i]->getName() << endl;
			}
			int mortgageNum = -1;
			cout << "Choose A Property to Mortgage, or enter -1 to end";
			if (mortgageNum > -1 && mortgageNum < sizeof(unMortgagedPropList))
			{
				p->addMoney(unMortgagedPropList[mortgageNum]->mort());
				unMortgagedPropList.erase(unMortgagedPropList.begin() + mortgageNum);
				cout << "Your Current Money is $" << p->showMoney() << endl;
			}
		}
	}
}