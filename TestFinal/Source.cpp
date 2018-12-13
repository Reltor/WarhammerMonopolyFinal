#include <iostream>
#include <sstream>
#include <iomanip>
#include "Game.h"
#include "Coord.h"

using namespace std;


int main()
{
	//do things
	ostringstream introString;
	introString << "#############################\n" <<  "Welcome to Warhammer Monopoly\n" << "#############################" << endl;
	cout << introString.str();
	Game newGame = Game();
	newGame.display();
	int numPlayers;
	cout << "How Many Players?: ";
	cin >> numPlayers;
	cout << numPlayers << endl;
	newGame.display();
	system("pause");
	

};