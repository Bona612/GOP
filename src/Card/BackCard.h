#ifndef CARD_BACKCARD_H_
#define CARD_BACKCARD_H_

#include "Card.h"
#include "../Utils/Utils.h"

class BackCard : public Card
{
    private:
        int value ;

    public:
        BackCard() ;
        void setValue(int value) ;
        int getValue() ;
        void effetto(Game* game);
        ~BackCard();
} ;

#endif /* CARD_BACKCARD_H_ */
