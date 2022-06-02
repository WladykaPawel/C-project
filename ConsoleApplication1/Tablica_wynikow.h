#pragma once
#include "wynik.h"
#include <iostream>
class Tablica_wynikow:public wynik
{

private:
	wynik* Poczatek;
	int LiczbaProb;

public:
	Tablica_wynikow();
	~Tablica_wynikow();
	void Dodaj(const wynik& p);
	
	void WypiszWyniki() const;
	void najwyzszy_wynik();
	
};

