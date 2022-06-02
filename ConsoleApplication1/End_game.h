#pragma once
#include "game.h"
using namespace sf;

class End_game: public game
{

public:

	bool zmienic = true;
	void zakonczenie();
	void zerowanie();
};