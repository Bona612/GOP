#ifndef CARD_AGAINCARD_H_
#define CARD_AGAINCARD_H_

#include "Card.h"

class AgainCard : public Card
{
    public:
		AgainCard();
        void effetto(Game* game);
        ~AgainCard();
} ;

#endif /* CARD_AGAINCARD_H_ */
