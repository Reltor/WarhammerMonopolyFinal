#include "Card.h"
#include "time.h"
#include <random>
#include "Enums.h"
#include "Player.h"
using namespace std;
Card::Card()
{
	this->engine.seed(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> randomInt{ 0,3 };

	uniform_int_distribution<int> moneyInt{ -200,200 };
	uniform_int_distribution<int> moveInt{ -10,10 };
	effect = static_cast<CardEffects>(randomInt(this->engine));
	if (effect == CardEffects::CHANGE_MONEY)
	{
		effectMagnitude = moneyInt(this->engine);
	}
	else if (effect == CardEffects::MOVE || effect == CardEffects::MOVE_NO_GO)
	{
		effectMagnitude = moveInt(this->engine);
	}
	else
	{
		effectMagnitude = 0;
	}
}

void Card::applyEffect(Player* p)
{
	
}

CardEffects Card::getEffect()
{
	return this->effect;
}

int Card::getMagnitude()
{
	return this->effectMagnitude;
}
