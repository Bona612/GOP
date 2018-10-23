#include "AgainCard.h"

AgainCard::AgainCard() : Card()
{
    setText((char *)("Tira ancora")) ;
}

void AgainCard::effetto(Game* game)
{
    game->throwAgain();
}

AgainCard::~AgainCard()
{
}
