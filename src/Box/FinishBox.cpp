#include "FinishBox.h"

FinishBox::FinishBox()
{
    setText((char *)("Arrivo")) ;
    this->color = Color::green ;
    this->setType(Finish) ;
}

void FinishBox::effect(Game* game)
{
    game->finish();
}

FinishBox::~FinishBox()
{
}
