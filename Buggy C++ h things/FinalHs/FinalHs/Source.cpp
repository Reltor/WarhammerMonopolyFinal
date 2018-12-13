#include <iostream>
#include <sstream>
#include <iomanip>
#include "Game.h"
using namespace std;
int main()
{
	default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	//do things
	ostringstream introString;
	introString << "#############################\n" << "Welcome to Warhammer Monopoly\n" << "#############################" << endl;
	cout << introString.str();
	Game::display();
	system("pause");
};