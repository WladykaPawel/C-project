#include <SFML/Audio.hpp>
#include "game.h"
#include "End_game.h"



using namespace sf;
using namespace std;


//void music()
//{ 
//    Music music1;
//     Open it from an audio file
//    if (!music1->openFromFile("music/sound.ogg"))
//    {
//        cout << "nie wyszlo";
//    }
//    music1->openFromFile("sound.ogg");
//    music1->play();
//}


int main()
{
    srand(time(0)); 

    int i=0;
    End_game finished;

    ////////wczytanie danych z plikow////////

    finished.postac.wczytanie_obrazow();
    finished.postac.wczytanie_napisow();
    

    ///////////wybieranie postaci///////////
    while(i == 0)
    {
        if (finished.zmienic == true)
        {
            finished.new_character.wybor_postaci();

            if (finished.new_character.znak == 1) {
                finished.postac.character.loadFromFile("images/Naruto.png");
                finished.spadanie = 0.2;
                finished.poziom = 10;
            }
            else if (finished.new_character.znak == 2){
                finished.postac.character.loadFromFile("images/Jirayia.png");
                finished.spadanie = 0.3;
                finished.poziom = 12;
            }   
            else if (finished.new_character.znak == 3){
                finished.postac.character.loadFromFile("images/itachi.png");
                finished.spadanie = 0.4;
                finished.poziom = 15;
            }
            else if (finished.new_character.znak == 5) {
                finished.postac.character.loadFromFile("images/madara.png");
                finished.spadanie = 0.4;
                finished.poziom = 30;
            }
            else if (finished.new_character.znak == 4)
            {
                return 0;
            }

            finished.sPers.setTexture(finished.postac.character);

        }
         
            finished.los();
            finished.gra();
            finished.zakonczenie();
            finished.zerowanie();
        
        
    }
   
    return 0;
}
