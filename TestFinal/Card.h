#ifndef CARD_H
#define CARD_H
#include <string>
#include "Enums.h"
#include <array>

class Card
{
public:
	Card();
	void applyEffect();

private:
	CardEffects effect;
	static std::array<std::string, 5> effectText;
	static std::default_random_engine engine;
	int effectMagnitude; 

};

#endif