#include <iostream>
#include <sstream>
#include <iomanip>
#include "Game.h"
#include "Coord.h"
#include "Enums.h"
#include "Functions.h"

using namespace std;


int main()
{
	default_random_engine engine{ static_cast<unsigned int>(time(0))};
	uniform_int_distribution<unsigned int> randomInt{ 1,6 };
	//do things
	ostringstream introString;
	introString << "#############################\n" <<  "Welcome to Warhammer Monopoly\n" << "#############################" << endl;
	cout << introString.str();
	int numPlayers = 0;

	while (numPlayers < 2 || numPlayers > 6)
	{
		cout << "How Many Players? (2-6)";
		cin >> numPlayers;
	}
	string playerName;
	Game newGame = Game(numPlayers);
	for (int i = 0; i < numPlayers; ++i)
	{
		cout << "Please give the name for Player " << i << ":";
		cin >> playerName;
		Player* newPlayer = newGame.getPlayer(i);
		newPlayer->setName(playerName);

	}
	
	newGame.display(1);
	bool gameOver = false;
	int counter = 1;
	int playerCount = 0;
	int die1 = 0;
	int die2 = 0;
	while (!gameOver)
	{
		int playerCount = 0;
		for (int i = 0; i < newGame.getNumPlayers(); ++i)
		{
			Player* curPlayer = newGame.getPlayer(i);

			if (curPlayer->getState() == 1)
			{
				die1 = newGame.rollDie();
				die2 = newGame.rollDie();
				
				int totalMove = die1 + die2;
				curPlayer->setLastRoll(totalMove);
				bool endTurn = false;
				bool wasThirdDouble = false;
				if (die1 == die2)
				{
					wasThirdDouble = newGame.doubles(curPlayer); //Handling what happens if a third double is rolled
					if (wasThirdDouble == true)
					{
						if (curPlayer->getJailedState() == true) //checks if the move function jailed the player and ends the turn if it did
						{
							endTurn = true;
							cout << "You were Jailed. Roll 3 doubles in a row or pay $50 to get out " << endl;
						}
						else if (curPlayer->getJailedState() == false) // checks if the move function removed the player from jail
						{
							cout << "You were freed from jail by your rolls" << endl;
						}
					}
				}
				if (endTurn == false)
				{
					newGame.move(i, totalMove);
				}
				
				newGame.display(i);
				cout << "Rolled a " << die1 << " and a " << die2 << endl;
				while (!endTurn)
				{
					int menuChoice = 0;
					bool validChoice = false;
					while (!validChoice)
					{
						newGame.displayPlayer(curPlayer);
						cout << endl;
						newGame.displayMenu();
						cin >> menuChoice;
						if (menuChoice < 1 || menuChoice > 6)
						{
							validChoice = false;
						}
						else
						{
							validChoice = true;
						}


					}
					if (menuChoice == 1)
					{
						newGame.cheatMenu(curPlayer);
					}
					else if (menuChoice == 2)
					{
						//newGame.trade(newGame.getPlayer(i));
					}
					else if (menuChoice == 3)
					{
						newGame.mortgage(curPlayer);
					}
					else if (menuChoice == 4)
					{
						//use a card
					}
					else if (menuChoice == 5)
					{
						//buy a house
					}
					else if (menuChoice == 6)
					{
						endTurn = true;
					}

					newGame.display(i);
				}
				if (curPlayer->showMoney() <= 0 && curPlayer->allMortgaged())
				{
					curPlayer->setState(static_cast<int>(PlayerState::LOST));
				}
				else
				{
					++playerCount;
				}
			}
		}

		if (playerCount <= 0)
		{
			
			gameOver = true;
		}
	}
	cout << "Game Over";

		system("pause");
	

};