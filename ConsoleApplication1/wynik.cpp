#include "wynik.h"



using namespace std;

int wynik::get_licznik()const
{
	return score;
}

void wynik::set_licznik(int score)
{
	this -> score = score;
}

void wynik::Wpisanie()
{
	score = licznik;
}

void wynik::Wypisz() const
{
	cout << score; 
	cout << endl;
}


int wynik::Porownaj(const wynik& wzor) const
{
	if (wzor.score == score){
		return 0;
	}
	else if (wzor.score > score) {
		return 1;
	}
	else return -1;
}

int wynik::WczytajZPliku()
{
	ifstream odczyt("wynik.txt");
	odczyt >> wczytana;
	odczyt.close();

	return 0;
}

int wynik::ZapiszDoPliku()
{
	ofstream zapis("wynik.txt");
	zapis << wczytana;
	zapis.close(); 

	return 0;
}
