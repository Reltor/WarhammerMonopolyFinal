#include <iostream>
#include <sstream>
#include <iomanip>
#include "Player.h"
#include "Space.h"
#include "Functions.h"
//#include "Game.h"
using namespace std;
int main()
{
	//default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	//do things
	ostringstream introString;
	introString << "#############################\n" << "Welcome to Warhammer Monopoly\n" << "#############################" << endl;
	cout << introString.str();
	//Game::display();
	system("pause");
	Player p;
	Player b;
	Space s("javaBetter","JIB",2,0,50,false,10,false);
	Properties pro;
	Properties prop("JeffsPizza");
	cout << "Get money test" << endl;
	cout << p.showMoney() << endl;
	p.getMoney(100);
	cout << p.showMoney() << endl;
	system("pause");
	cout << "Payrent test" << endl;
	s.setOwner("billy");
	cout << p.showMoney() << endl;
	Functions::payRent(p, s, 1);
	cout << p.showMoney() << endl;
	cout << p.getName().compare(s.getOwner()) << endl << p.getName() << s.getOwner() << endl;
	Functions::setOwnerShip(p, s);
	cout << p.getName().compare(s.getOwner()) << endl << p.getName() << s.getOwner() << endl;
	system("pause");
	Functions::payRent(p, s, 1);
	cout << p.showMoney() << endl;
	cout << "If somethin shows up under this then good times" << endl;
	cout << s.getOwner() << endl;
	system("pause");
	Functions::buyProperty(p, pro);
	Functions::buyProperty(p, pro);
	Functions::buyProperty(b, prop);
	Functions::buyProperty(b, prop);
	Functions::buyProperty(b, prop);
	Functions::trade(p, b);
	Functions::trade(p, b);
	system("pause");
};