#include "BackStartBox.h"

BackStartBox::BackStartBox()
{
    setText((char *)("Torna all'inizio")) ;
    this->color = Color::red ;
    this->setType(BackStart) ;
}

void BackStartBox::effect(Game* game)
{
    game->backStart();
}

BackStartBox::~BackStartBox()
{
}
