#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <MMSystem.h>

using namespace sf;

class File
{

public:
	Texture t1, t2, t3, t4, t5, character,t6;
	Texture t,end_t,red,white;
	Font font;
	Text start0, start1, start2, start3, start4, start5, stop, podpis;
	Text opis, opis1, opis2;
	Text text, wynik1, text2, wynik2, kontynuacja;

	void wczytanie_obrazow();
	void wczytanie_napisow(); 
	void wczytanie_napisow_koncowych();
	void wczytanie_napisow_opisu();


};