#include "File.h"

void File::wczytanie_obrazow()
{
    ///////////wczytywanie obrazów//////////////

    t2.loadFromFile("images/platform1.png");
    t3.loadFromFile("images/platform2.png");
    t4.loadFromFile("images/platform3.png"); 
    t6.loadFromFile("images/hop_pla.png");
    t5.loadFromFile("images/black.png");
    t1.loadFromFile("images/Konocha.png");
    end_t.loadFromFile("images/koniec_gry.png");
    red.loadFromFile("images/red.png");
    white.loadFromFile("images/white.png");
}

void File::wczytanie_napisow()
{
    //////za³adownie czcionki//////
    font.loadFromFile("czcionki/ZacharyBinx.ttf");

    start0.setString("Welcome  to  the: \n NARURO  JUMP  game!");
    start0.setFont(font);
    start1.setFillColor(sf::Color::White);
    start0.setCharacterSize(35);
    start0.setPosition(50, 50);
   
    start1.setString("Choose  your  character:");
    start1.setFont(font);
    start1.setCharacterSize(25);
    start1.setFillColor(sf::Color::Yellow);
    start1.setPosition(0, 150);


    start2.setString("1) Naruto  (easy) ");
    start2.setFont(font);
    start2.setCharacterSize(35);
    start2.setFillColor(sf::Color::Black);
    start2.setPosition(20, 200);

    start3.setString("2) Jirayia  (normal)");
    start3.setFont(font);
    start3.setCharacterSize(35);
    start3.setFillColor(sf::Color::Black);
    start3.setPosition(20, 250);

    start4.setString("3) Itachi  (hard)");
    start4.setFont(font);
    start4.setCharacterSize(35);
    start4.setFillColor(sf::Color::Black);
    start4.setPosition(20, 300);

    start5.setString("hold  '0'  to  see  the  description");
    start5.setFont(font); 
    start5.setCharacterSize(20);
    start5.setFillColor(sf::Color::Red);
    start5.setPosition(50, 475);

    stop.setString("Press  esc  to  exit");
    stop.setFont(font);
    stop.setCharacterSize(20);
    stop.setFillColor(sf::Color::Red);
    stop.setPosition(50, 500);

    podpis.setString("Made by Pawel Wladyka");
    podpis.setFont(font);
    podpis.setCharacterSize(10);
    podpis.setFillColor(sf::Color::White);
    podpis.setPosition(300, 520);
    
}

void File::wczytanie_napisow_koncowych()
{
    font.loadFromFile("czcionki/ZacharyBinx.ttf");
    //////////////Zakoñczenie///////////////////

    text.setString("Your score:");
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(50, 300);


    wynik1.setFont(font);
    wynik1.setCharacterSize(50);
    wynik1.setFillColor(sf::Color::White);
    wynik1.setPosition(200, 350);

    text2.setString("Hight score: ");
    text2.setFont(font);
    text2.setCharacterSize(50);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(50, 400);

    wynik2.setFont(font);
    wynik2.setCharacterSize(50);
    wynik2.setFillColor(sf::Color::White);
    wynik2.setPosition(200, 450);

    kontynuacja.setString("press esc to exit \n or any key to play again ");
    kontynuacja.setFont(font);
    kontynuacja.setCharacterSize(20);
    kontynuacja.setFillColor(sf::Color::White);
    kontynuacja.setPosition(50, 0);
}

void File::wczytanie_napisow_opisu()
{

    opis.setString("Description \n of the Game: ");
    opis.setFont(font);
    opis.setFillColor(sf::Color::White);
    opis.setCharacterSize(35);
    opis.setPosition(50, 50);


    opis1.setString("> Use  the  arrows  or  the  a  and  d  keys \n\n > Collect  as  many  points  as  possible !! \n\n > Red  platforms  add  + 20 points \n\n > Wooden  platforms  are  deteriorating  \n\n >Green  platforms  make  more  jump   ");
    opis1.setFont(font);
    opis1.setCharacterSize(18);
    opis1.setFillColor(sf::Color::White);
    opis1.setPosition(20, 200);
}
