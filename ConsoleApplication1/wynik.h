#pragma once
#include<iostream>
#include<fstream>

class wynik
{
private:
	int score = 0;	
public:
	int licznik = 0;
	int Max = 0;
	int wczytana;
	
	wynik* m_pNastepny; 

	int get_licznik() const;
	void set_licznik(int score);
	void Wpisanie();
	void Wypisz() const;

	int Porownaj(const wynik& wzorzec) const;
	int WczytajZPliku();
	int ZapiszDoPliku();

}; 
