#include "../Box/Box.h"

#include <iostream>
#include <cstring>

using namespace std ;

// Messaggio della casella, colore e tipo di default
Box::Box()
{
    setText((char *)("Messaggio di default")) ;
    this->color = Color::white ;
    setType(Default) ;
}

// Chiamato per eseguire l'azione della casella
void Box::effect(Game *game)
{
}

char* Box::getText()
{
    return this->text ;
}

void Box::setText(char* text)
{
    strcpy(this->text, text) ;
}

Color Box::getColor()
{
    return this->color;
}

void Box::setType(BoxType type)
{
    this->type = type ;
}

BoxType Box::getType()
{
    return this->type ;
}

Box::~Box()
{
}
