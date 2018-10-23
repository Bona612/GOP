#ifndef CARD_FORWARDCARD_H_
#define CARD_FORWARDCARD_H_

#include "Card.h"
#include "../Utils/Utils.h"

class ForwardCard : public Card
{
    private:
        int value ;

    public:
        ForwardCard() ;
        int getValue() ;
        void setValue(int value) ;
        void effetto(Game* game);
        ~ForwardCard();
} ;

#endif /* CARD_FORWARDCARD_H_ */
