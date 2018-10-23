#ifndef CARD_QUESTIONCARD_H_
#define CARD_QUESTIONCARD_H_

#include "Card.h"

class QuestionCard : public Card
{
	public:
        QuestionCard() ;
        void effetto(Game* game) override;
        ~QuestionCard();
} ;

#endif /* CARD_QUESTIONCARD_H_ */
