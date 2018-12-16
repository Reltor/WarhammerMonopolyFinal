#ifndef CARD_H
#define CARD_H
#include <string>
#include "Enums.h"
#include <array>
#include <random>
#include "Player.h"

class Card
{
public:
	Card();
	void applyEffect(Player*);
	CardEffects getEffect();
	int getMagnitude();

private:
	CardEffects effect;
	static std::array<std::string, 5> effectText;
	std::default_random_engine engine;
	int effectMagnitude; 

};

#endif