#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <MMSystem.h>
#include "wynik.h"
#include "Tablica_wynikow.h"
#include "Wybor_Postaci.h"
#include "File.h"
#pragma once

class game:public File, public wynik
{
public:
	wynik nowy;
	Tablica_wynikow tab;
	Wybor_Postaci new_character;
	File postac;
	Sprite sPers;


	Time delayTime = sf::seconds(1);
	Clock clock;
	Time elapsed;
	float spadanie;
	int poziom;


	bool czy_pkt = true;
	bool czy_drewniana = true;
	bool czy_drewniana2 = true;
	bool czy_drewniana3 = true;
	bool czy_hop = true;
	int licznik_do_hop = 0;

	struct point
	{
		float x, y;
	};

	point plat[16];

	std::string pom;
	std::string hight;

	void los();
	void gra();
};