#include "Game.h";
#include <array>
#include <string>
#include <iostream>
#include<iomanip>
#include "Coord.h"
using namespace std;

void Game::display()
{

	
	array<string, 11> line1{};
	array<string, 11> line2{};
	array<string, 11> line3{};
	array<string, 11> line4{};
	array<string, 11> line5{};
	array<string, 11> line6{};
	array<string, 11> line7{};
	array<string, 11> line8{};
	array<string, 11> line9{};
	array<string, 11> line10{};
	array<string, 11> line11{ " GO", "KIKI", "COCH", "KIPR", "ITAX", "TRUW","TKKH", "CHAN", "TKZA","TKLA","JAIL" };
	array<array<string,11>, 11> dummyBoard{line1,line2,line3,line4,line5,line6,line7,line8,line9,line10,line11};
	cout << "----------------------------------------------------------------------------------------" << endl;


	array<string, 11> line110{};
	array<string, 11> line21{};
	array<string, 11> line31{};
	array<string, 11> line41{};
	array<string, 11> line51{};
	array<string, 11> line61{};
	array<string, 11> line71{};
	array<string, 11> line81{};
	array<string, 11> line91{};
	array<string, 11> line101{};
	array<string, 11> line111{};
	array<array<string, 11>, 11> playerArray{ line110,line21,line31,line41,line51,line61,line71,line81,line91,line101,line111 };
	Coord playerCoord;
	for (Player p: this->playerList)
	{
		playerCoord = translateLoc(p.getLoc());
		playerArray[playerCoord.getY()][playerCoord.getX()] += "x";


	}
	


	for (int i = 0; i < 11; ++i)
	{
		array<string, 11> line = dummyBoard[i];

		for (int k = 0; k < 11; ++k)
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
		
		if (i == 0 || i == 10)
		{
			cout << endl; 
			for (int j = 0; j < 11; ++j)
			{
				cout  << "|" << setw(6) << playerArray[i][j] << "|";
			}
		}
		else
		{
			cout << endl << "|" << setw(6) << playerArray[i][0] << "|" << setw(73) << "|" << setw(6) << playerArray[i][10] << "|";
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
		y = 21-loc;
	}
	else if (loc >= 21 && loc < 31)
	{
		y = 0;
		x = loc-21;
	}

	else if (loc >= 31)
	{
		x = 10;
		y = loc - 31;
	}

	return Coord(x, y);
}


void Game::move(Player* p, int numSpaces)
{
	int newLoc;
	if (p->getLoc() + numSpaces > 39)
	{
		newLoc = p->getLoc() + numSpaces - 39;
		//add money to player for passing go!!
	}
	else
	{
		newLoc = p->getLoc() + numSpaces;
	}
	p->setLoc(newLoc);
	display();
}

Player* Game::getPlayer(int playerNum)
{
	return &(this->playerList[playerNum]);
}