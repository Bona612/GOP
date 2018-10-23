#include <cstring>
#include "Card.h"

Card::Card()
{
}

Card::Card(char* text)
{
    strcpy(this->text, text) ;
}

void Card::setText(char* text)
{
    strcpy(this->text, text) ;
}

char* Card::getText()
{
    return this->text ;
}

//metodo che servirà per applicare l'effetto della carta
void Card::effetto(Game* game)
{
}

Card::~Card()
{
}
