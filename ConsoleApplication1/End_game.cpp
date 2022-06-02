#include "End_game.h"

void End_game::zakonczenie()
{
    wczytanie_obrazow();
    wczytanie_napisow_koncowych();

    Sprite sBlack(t);
    Sprite sRed(red);
    Sprite sWhite(white);
    Sprite sGame_Over(postac.end_t);


    RenderWindow koniec(VideoMode(444, 533), "Koniec gry");
    koniec.setFramerateLimit(55);

    while (koniec.isOpen())
    {
        Event eve;
        while (koniec.pollEvent(eve))
        {
            if (eve.type == Event::Closed)
            {
                koniec.close();
            }
            
            koniec.draw(sBlack);
            koniec.draw(sGame_Over);
            sWhite.setPosition(20, 10);
            koniec.draw(sWhite);
            sWhite.setPosition(20, 30);
            koniec.draw(sWhite);

            ////////// Liczenie wyników ///////////

            nowy.Wpisanie();
            //nowy.Wypisz();
            tab.Dodaj(nowy);
            tab.WypiszWyniki();
            tab.najwyzszy_wynik();

            pom = std::to_string(nowy.licznik / 10);
            hight = std::to_string(tab.Max / 10);

            wynik1.setString(pom);
            wynik2.setString(hight);

            wczytanie_napisow_koncowych();


            Text kontynuacja("press esc to change a character \n or any space to play again", postac.font, 20);
            kontynuacja.setPosition(50, 5);

            koniec.draw(text);
            koniec.draw(text2);
            koniec.draw(wynik1);
            koniec.draw(wynik2);
            koniec.draw(kontynuacja);
     

       
            /////////// koniec gry lub kontynuacja ///////////
            if ((Mouse::getPosition(koniec).y < 25) && (Mouse::getPosition(koniec).y > 0))
            {
                sRed.setPosition(20, 10);
                koniec.draw(sRed);
                if (Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    zmienic = true;
                    koniec.close();
                }
            }
            if ((Mouse::getPosition(koniec).y < 50) && (Mouse::getPosition(koniec).y > 25))
            {
                sRed.setPosition(20, 30);
                koniec.draw(sRed);
                if (Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    zmienic = false;
                    koniec.close();
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                zmienic = true;
                koniec.close();
            }
            else if (Keyboard::isKeyPressed(Keyboard::Space))
            {
                zmienic = false;
                koniec.close();
            }
            else
            {
                koniec.waitEvent(eve);
            }
            koniec.display();
        }
      
    }
  

}

void End_game::zerowanie()
{
    nowy.licznik = 0;
}