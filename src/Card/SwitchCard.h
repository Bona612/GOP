#ifndef CARD_SWITCHCARD_H_
#define CARD_SWITCHCARD_H_

#include "Card.h"

class SwitchCard : public Card
{
	private:
		int switch_player;

    public:
        SwitchCard();
        void setPlayer(int p);
        int getPlayer();
        void effetto(Game* game);
        ~SwitchCard();
} ;

#endif /* CARD_SWITCHCARD_H_ */
