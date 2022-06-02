#include "Wybor_Postaci.h"


void Wybor_Postaci::wczytanie_tla()
{
    t.loadFromFile("images/start.png");
}

void Wybor_Postaci::wybor_postaci()
{
   
    RenderWindow poczatek(VideoMode(444, 533), "Wybierz swoja postac!");

    wczytanie_tla();
    wczytanie_napisow();
    wczytanie_napisow_opisu();

    Sprite sBlack(t);

    while (poczatek.isOpen())
    {
        Event ev;

            poczatek.draw(sBlack);
            poczatek.draw(start0);
            poczatek.draw(start1);
            poczatek.draw(start2);
            poczatek.draw(start3);  
            poczatek.draw(start4);
            poczatek.draw(start5);
            poczatek.draw(stop);
            poczatek.draw(podpis);


              poczatek.waitEvent(ev);


              if ((Keyboard::isKeyPressed(Keyboard::Num1) || (Mouse::getPosition(poczatek).y < 230) && (Mouse::getPosition(poczatek).y > 200)))
              {
                  start2.setFillColor(sf::Color::Green);
                  if (Keyboard::isKeyPressed(Keyboard::Num1) ||  Mouse::isButtonPressed(sf::Mouse::Left))
                  {
                      znak = 1;
                      poczatek.close();
                  }
              }

              else if ((Keyboard::isKeyPressed(Keyboard::Num2) || (Mouse::getPosition(poczatek).y < 280) && (Mouse::getPosition(poczatek).y > 250)))
              {
                  start3.setFillColor(sf::Color::Yellow);
                  if (Keyboard::isKeyPressed(Keyboard::Num2) || (Mouse::isButtonPressed(sf::Mouse::Left)))
                  {
                      znak = 2;
                      poczatek.close();
                  }
              }
              else if ((Keyboard::isKeyPressed(Keyboard::Num3) || (Mouse::getPosition(poczatek).y < 330) && (Mouse::getPosition(poczatek).y > 300)))
              {
                  start4.setFillColor(sf::Color::Red);
                  if (Keyboard::isKeyPressed(Keyboard::Num3) ||  Mouse::isButtonPressed(sf::Mouse::Left))
                  {
                      znak = 3;
                      poczatek.close();
                  }
              }
              else
              {
                  start2.setFillColor(sf::Color::Black);
                  start3.setFillColor(sf::Color::Black);
                  start4.setFillColor(sf::Color::Black);
              }
              
              if (Keyboard::isKeyPressed(Keyboard::O))
              {

                  poczatek.draw(sBlack);
                  poczatek.draw(opis);
                  poczatek.draw(opis1);
                  poczatek.draw(opis2);
                  if (Keyboard::isKeyPressed(Keyboard::Num4))
                  {
                      continue;
                  }
              }
              if (Keyboard::isKeyPressed(Keyboard::Escape))
              {
                  znak = 4;
                  poczatek.close();
              }
              if (Keyboard::isKeyPressed(Keyboard::M)&&Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::D))
              {
                  znak = 5;
                  poczatek.close();
              }

            
            poczatek.display();
    }

    poczatek.setFramerateLimit(55);
}

