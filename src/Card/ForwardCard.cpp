#include "ForwardCard.h"

//al momento della creazione viene anche costruito il messaggio da mandare in output
ForwardCard::ForwardCard() : Card()
{
	char v[2] ;
	char text[MAX_LENGHT] ;
	setValue((rand() % 5) + 1) ;
	strcpy(text, "Vai avanti di ") ;
	iToStr(this->value, v) ;
	strcat(text, v);
	strcat(text, (char *)(" casell"));
	v[0] = (((this->value) * (-1) == 1) ? 'a' : 'e');
	strcat(text, v);
	setText(text) ;
}

void ForwardCard::setValue(int value)
{
    this->value = value ;
}

int ForwardCard::getValue()
{
    return this->value ;
}

void ForwardCard::effetto(Game* game)
{
    game->movePlayer(this->value) ;
}

ForwardCard::~ForwardCard()
{
}
