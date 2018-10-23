#include "SwitchCard.h"

//al momento della creazione viene anche costruito il messaggio da mandare in output
SwitchCard::SwitchCard() : Card()
{
	char text[MAX_LENGHT];
	setPlayer(((rand()%2) == 0) ? 1 : -1);
    strcpy(text, "Cambia posizione con il giocatore ") ;
    strcat(text, (getPlayer() == 1 ? "successivo" : "precedente"));
    setText(text);
}

void SwitchCard::setPlayer(int p)
{
	this->switch_player = p;
}

int SwitchCard::getPlayer()
{
	return this->switch_player;
}

void SwitchCard::effetto(Game* game)
{
    game->switchPosition(getPlayer());
}

SwitchCard::~SwitchCard()
{
}
