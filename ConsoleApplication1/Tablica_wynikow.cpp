#include "Tablica_wynikow.h"
#include "wynik.h"

Tablica_wynikow::Tablica_wynikow()
{
	LiczbaProb = 0;
	Poczatek = nullptr;
}


Tablica_wynikow::~Tablica_wynikow()
{
	wynik* pomoc = Poczatek;
	wynik* pomoc2;

	for (int i = 0; i < LiczbaProb - 1; i++)
	{
		pomoc2 = pomoc->m_pNastepny;
		delete pomoc;
		pomoc = pomoc2;
	}
}


void Tablica_wynikow::Dodaj(const wynik& p)
{
	wynik* pracownik = new wynik(p);
	wynik* pomoc = Poczatek;

	if (LiczbaProb == 0)
	{
		Poczatek = pracownik;
		pracownik->m_pNastepny = nullptr;
		LiczbaProb++;
	}
	else if (p.Porownaj(*pomoc) < 0)
	{
		pracownik->m_pNastepny = Poczatek;
		Poczatek = pracownik;
		LiczbaProb++;
	}
	else if (p.Porownaj(*pomoc) > 0)
	{
		while (1)
		{
			if (p.Porownaj(*pomoc) == 0)
			{
				delete pracownik;
				break;
			}

			if (pomoc->m_pNastepny == nullptr)
			{
				pomoc->m_pNastepny = pracownik;
				pracownik->m_pNastepny = nullptr;
				LiczbaProb++;
				break;
			}

			if (p.Porownaj(*(pomoc->m_pNastepny)) < 0)
			{
				pracownik->m_pNastepny = pomoc->m_pNastepny;
				pomoc->m_pNastepny = pracownik;
				LiczbaProb++;
				break;

			}

			pomoc = pomoc->m_pNastepny;
		}
	}
}

void Tablica_wynikow::WypiszWyniki(void) const
{
	wynik* Lista = Poczatek;
	if (LiczbaProb == 0)
	{
		std::cout << "Lista jest pusta!" << std::endl;
	}
	else
	{
		for (int i = 1; i <= LiczbaProb; i++)
		{
			std::cout  << i << ") ";
			Lista->Wypisz();
			Lista = Lista->m_pNastepny;
		}
	}
}

void Tablica_wynikow::najwyzszy_wynik()
{
	wynik* Lista;
	Lista = Poczatek;

	WczytajZPliku();
	Max = Poczatek->licznik;

	if (wczytana > Max)
	{
		Max = wczytana;
	}
	wczytana = Max;
	ZapiszDoPliku();
	//std::cout << Max << "Max \n";
	//std::cout << wczytana << "wczytana \n";
}


