#include <cstring>
#include "Player.h"
#include "../Card/Card.h"

//creazione del giocatore e inizializzazione dei vari campi
Player::Player(char *name, int pos)
{
    strcpy(this->name, name) ;
    setPos(0) ;
    setNumTurns(0) ;
    add_color(pos) ;
    setName(name);
}

//vengono agiunti al nome anche le sequenze di escape
void Player::setName(char *name)
{
	strcpy(this->name, getColor(this->color)) ;
	strcat(this->name, name) ;
	strcat(this->name, getReset()) ;
}

char *Player::getName()
{
    return this->name ;
}

int Player::getPos()
{
    return pos ;
}

void Player::setPos(int pos)
{
    this->pos = pos ;
}

void Player::setNumTurns(int numTurns)
{
    this->numTurns = numTurns ;
}

int Player::getNumTurns()
{
    return this->numTurns ;
}

bool Player::isBlocked()
{
    bool blocked =  this->numTurns != 0 ;
    if(blocked)
    {
        decNumTurns() ;
    }
    return blocked ;
}

void Player::decNumTurns()
{
    this->numTurns-- ;
}

void Player::add_color(int pos)
{
    this->color = static_cast<Color>(pos) ;
}

Color Player::getColorPlayer()
{
    return this->color ;
}

Player::~Player()
{
}

