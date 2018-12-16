
#ifndef GAME_H
#define GAME_H

#include <array>
#include "Coord.h"
#include <vector>
#include "Player.h"
#include "Space.h"
#include "Properties.h"
#include <random>


class Game
{
public:
	Game(int);
	void display(int);
	Coord translateLoc(int);
	void move(int, int);
	void move(Player*, int, bool passGo = true);
	Player* getPlayer(int);
	int getNumPlayers();
	~Game();
	void displayMenu();
	void cheatMenu(Player*);
	void displayPlayer(Player*);
	unsigned int rollDie();
	bool doubles(Player*);
	void mortgage(Player*);
	

private:
	std::array<Space*, 40> boardArray;
	std::vector<Player> playerList{};
	int numPlayers;
	void initBoard();
	int numDoubles = 0;
	std::default_random_engine engine;
};
#endif
