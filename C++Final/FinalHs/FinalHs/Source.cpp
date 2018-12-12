#include <iostream>
#include <sstream>
#include <iomanip>
#include "Game.h""

using namespace std;


int main()
{
	//do things
	ostringstream introString;
	introString << "#############################\n" <<  "Welcome to Warhammer Monopoly\n" << "#############################" << endl;
	cout << introString.str();
	Game::display();
	system("pause");

};