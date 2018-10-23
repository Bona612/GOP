#include "Deck.h"
#include "../Card/Card.h"
#include "../Card/SwitchCard.h"
#include "../Card/AgainCard.h"
#include "../Card/QuestionCard.h"
#include "../Card/VoidCard.h"

Deck::Deck()
{
}

//estrae una carta in base a delle percentuali prestabilite
Card* Deck::drawCard()
{
    int num_card = (rand() % 100) ;

    if (num_card < 10)
    {
    	return new VoidCard();	//VoidCard con percentuale del 10%
    }
    else if (num_card < 30)
    {
        return new SwitchCard();	//SwitchCard con percentuale del 20%
    }
    else if (num_card < 50)
    {
        return new AgainCard();		//AgainCard con percentuale del 20%
    }
    else
    {
    	return new QuestionCard();		//QuestionCard con percentuale del 50%
    }
}

Deck::~Deck()
{
}
