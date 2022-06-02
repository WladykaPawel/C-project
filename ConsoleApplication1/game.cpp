#include "game.h"

void game::los()
{
    /////////losowanie platform///////////////
    

    for (int i = 0; i < 8; i++)
    {
        plat[i].x = rand() % 400;
        plat[i].y = rand() % 533;
    }
}

void game::gra()
{
    
    float x = 200, y = 100, h = 200;
    float dx = 0, dy = 0;

    


    Sprite sBackground(postac.t1);
    Sprite sPlat(postac.t2);
    Sprite sPlat2(postac.t3);
    Sprite sPlat3(postac.t4);
    Sprite sPlat4(postac.t4);
    Sprite sPlat5(postac.t4);
    Sprite sPlat6(postac.t6);
    Sprite sBlack(postac.t5);

    RenderWindow app(VideoMode(444, 533), "Naruto Game!");

    //ograniczenie liczby klatek na sekundê
    app.setFramerateLimit(80);

    /// pocz¹tek aplikaji

    clock.restart();

    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
            {
                app.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Escape))
            {
                app.close();

            }
        }

     
        
        //////// sterowanie ///////////
        if (Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)) || (sf::Mouse::isButtonPressed(sf::Mouse::Right))) {
            x = x + 5;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)) || (sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
            x = x - 5;
        }

        ///////////kolizja////////////

            //////kolizja lewa////
        if (x < 0)
        {
            x = 0;
        }

        /////kolizja prawa////

        if (x > 444 - 69)
        {
            x = 444 - 69;
        }
        
        ////////////////spadanie/////////////////////
        dy = dy + spadanie;
        y = y + dy;

        if (y > 500)
        {
            dy = -poziom;
        }
        ////////////////platformy/////////////////////
        if (y < h)
            for (int i = 0; i < 8; i++)
            {
                y = h;
                plat[i].y = plat[i].y - dy;

                if (plat[i].y > 533)
                {
                    plat[i].y = 0;
                    plat[i].x = rand() % 400;

                 // ustawianie platformy zielonej co 30 w grze
                    licznik_do_hop++;
                    if (licznik_do_hop == 30)
                    {
                        czy_hop = true;
                    }
                   
                  ///usawienie od nowej drewnianej 
                  
                    if (i == 5)
                    {
                        czy_drewniana = true;
                    }
                    if (i == 3)
                    {
                        czy_drewniana2 = true;
                    }
                    if (i == 1)
                    {
                        czy_drewniana3 = true;
                    }
                    if (i == 7)
                    {
                        czy_pkt = true;
                    }
                }
                
            }


        //////rysowanie t³a i postaci///////////
        sPers.setPosition(x, y);
        app.draw(sBackground);
        app.draw(sPers);


        //////rysowanie platform   ///////////
        for (int i = 0; i < 8; i++)
        {
            ///platforma do skakania
            if (i == 0 && czy_hop == true)
            {
                sPlat6.setPosition(plat[i].x, plat[i].y-6);
            }
            ///platforma czerona
            if (i == 7)
            {
                sPlat2.setPosition(plat[i].x, plat[i].y);
            }
            ///platforma drewniana
            if (i == 5)
            {
                sPlat3.setPosition(plat[i].x, plat[i].y);
            }
            else if (i == 3)
            {
                sPlat4.setPosition(plat[i].x, plat[i].y);
            }
            else if (i == 1)
            {
                sPlat5.setPosition(plat[i].x, plat[i].y);
            }
            else
            {
                sPlat.setPosition(plat[i].x, plat[i].y);
            }

            
            if (czy_drewniana == true)
            {
                app.draw(sPlat3);
            }
            if (czy_drewniana2 == true)
            {
                app.draw(sPlat4);
            }
            if  (czy_drewniana3 == true)
            {
                app.draw(sPlat5);
            }

           
             app.draw(sPlat);
             app.draw(sPlat2);
             if(czy_hop == true)
             { 
                 app.draw(sPlat6);
             }
                
        }




     ////// odbijanie siê   ///////////
        for (int i = 0; i < 8; i++)
        {
            if ((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68) && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))
            {   
                if (czy_drewniana == false && i == 5)   continue;
                if (czy_drewniana2 == false && i == 3)   continue;
                if (czy_drewniana3 == false && i == 1)   continue;
                if (i == 0 && czy_hop == true)
                {
                    dy = -2*poziom;
                    licznik_do_hop = 0;
                    czy_hop = false;

                }
                else
                {
                    dy = -poziom;

                }

                if (i == 7 && czy_pkt == true)
                {
                    nowy.licznik = nowy.licznik + 200;
                    czy_pkt = false;
                }
                if (i == 5)
                {
                    czy_drewniana = false;
                }
                if (i == 3)
                {
                    czy_drewniana2 = false;
                }
                if (i == 1)
                {
                    czy_drewniana3 = false;
                }
                
            }
            

        }

        /////// licznik punktów //////


        if (y == h && dy < (-1.62))
        {
            nowy.licznik += 5;
        }
        Text wynik(pom, postac.font, 50);
        wynik.setPosition(0, 0);
        app.draw(wynik);
        pom = std::to_string(nowy.licznik / 10);


        /////odliczanie pocz¹tkowe///////

        elapsed = clock.getElapsedTime();

        if (elapsed.asSeconds() < 1 && elapsed.asSeconds() > 0)
        {
            Text o_3("3", postac.font, 150);
            o_3.setPosition(175, 200);
            app.draw(o_3);
            dy = -spadanie;
        }
        if (elapsed.asSeconds() < 2 && elapsed.asSeconds() > 1)
        {
            Text o_2("2", postac.font, 150);
            o_2.setPosition(175, 200);
            app.draw(o_2);
            dy = -spadanie;
        }
        if (elapsed.asSeconds() < 3 && elapsed.asSeconds() > 2)
        {
            Text o_1("1", postac.font, 150);
            o_1.setPosition(175, 200);
            app.draw(o_1);
            dy = -spadanie;
        }
        if (elapsed.asSeconds() < 4 && elapsed.asSeconds() > 3)
        {
            Text o_go("GO!!", postac.font, 150);
            o_go.setPosition(100, 200);
            app.draw(o_go);
            dy = -spadanie;
        }
        

        ////////// ZAKOÑCZENIE /////////////

        if (y > 500)
        {
            app.close();
        }
        app.display();
    }
}