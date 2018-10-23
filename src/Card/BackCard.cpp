#include <cstring>
#include "BackCard.h"

//al momento della creazione viene anche costruito il messaggio da mandare in output
BackCard::BackCard() : Card()
{
	char v[2] ;
	char text[MAX_LENGHT] ;
	setValue(((rand() % 5) + 1) * (-1)) ;
	strcpy(text, "Vai indietro di ") ;
	iToStr((this->value) * (-1), v) ;
	strcat(text, v);
	strcat(text, (char *)(" casell"));
	v[0] = (((this->value) * (-1) == 1) ? 'a' : 'e');
	strcat(text, v);
	setText(text) ;
}

int BackCard::getValue()
{
    return this->value ;
}

void BackCard::setValue(int value)
{
    this->value = value ;
}

void BackCard::effetto(Game* game)
{
    game->movePlayer(this->value) ;
}

BackCard::~BackCard()
{
}
