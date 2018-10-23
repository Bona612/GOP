#include <cstring>
#include <cstdlib>
#include "MoveBox.h"
#include "../Utils/Utils.h"

//al momento della creazione viene anche costruito il messaggio da mandare in output
MoveBox::MoveBox(int movement)
{
    char text[50] ;
    char number[5] ;
    iToStr(abs(movement), number) ;
    setMovement(movement) ;
    strcpy(text, (char *)("Vai "));
    strcat(text, movement > 0 ? (char *)("avanti") : (char *)("indietro")) ;
    strcat(text, (char *)(" di "));
    strcat(text, number) ;
    strcat(text, abs(movement) > 1 ? (char *)(" posizioni") : (char *)(" posizione")) ;
    setText(text) ;
    this->color = (movement > 0) ? Color::cyan : Color::yellow ;
    this->setType(Move) ;
}

void MoveBox::effect(Game* game)
{
    game->movePlayer(movement);
}

void MoveBox::setMovement(int movement)
{
    this->movement = movement ;
}

int MoveBox::getMovement()
{
    return this->movement ;
}

MoveBox::~MoveBox()
{
}
