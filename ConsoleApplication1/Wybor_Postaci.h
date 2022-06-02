#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <MMSystem.h>
#include "File.h"

using namespace sf;

class Wybor_Postaci:public File
{
private:
	
public:
	int znak = 0;

	void wczytanie_tla();
	void wybor_postaci();	
};
