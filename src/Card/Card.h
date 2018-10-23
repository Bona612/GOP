#ifndef CARD_CARD_H_
#define CARD_CARD_H_

#include <cstring>
#include <random>
#include "../Game/Game.h"
#include "../Utils/Utils.h"

class Game;

using namespace std ;

#define MAX_LENGHT 100

class Card
{
    private:
        char text[MAX_LENGHT] ;

    public:
        Card() ;
        Card(char* text) ;
        void setText(char* text) ;
        virtual char* getText() ;
        virtual void effetto(Game* game) ;
        virtual ~Card();
} ;

#endif /* CARD_CARD_H_ */
