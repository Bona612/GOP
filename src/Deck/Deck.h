#ifndef DECK_DECK_H_
#define DECK_DECK_H_

class Card;

class Deck
{
	public:
		Deck() ;
    	Card* drawCard();
    	~Deck();
} ;

#endif /* DECK_DECK_H_ */
