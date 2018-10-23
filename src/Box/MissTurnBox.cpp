#include <cstdlib>
#include <cstring>
#include "MissTurnBox.h"
#include "../Utils/Utils.h"

//al momento della creazione viene anche costruito il messaggio da mandare in output
MissTurnBox::MissTurnBox(int turns)
{
	char text[50] ;
    char number[5] ;
    iToStr(abs(turns), number) ;
    setTurns(turns) ;
    strcpy(text, "Salta ");
    strcat(text, number) ;
    strcat(text, " turno") ;
    setText(text) ;
    this->color = Color::blue ;
    this->setType(MissTurn) ;
}

void MissTurnBox::effect(Game* game)
{
    game->missTurn(turns) ;
}

int MissTurnBox::getTurns()
{
    return this->turns ;
}

void MissTurnBox::setTurns(int turns)
{
	MissTurnBox::turns = turns ;
}

MissTurnBox::~MissTurnBox()
{
}

