
#ifndef GAME_H
#define GAME_H

#include <array>
#include "Coord.h"
#include <vector>
#include "Player.h"


class Game
{
public:
	void display();
	Coord translateLoc(int loc);
	void move(Player* p, int numSpaces);
	Player* getPlayer(int playerNum);

private:
	std::array<std::string, 40> boardArray{};
	std::vector<Player> playerList{ Player(),Player(),Player(),Player() };
};
#endif
