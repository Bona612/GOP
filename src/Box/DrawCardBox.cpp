#include "DrawCardBox.h"

DrawCardBox::DrawCardBox()
{
    setText((char *)("Pesca una carta")) ;
    this->color = Color::magenta ;
    this->setType(DrawCard) ;
}

void DrawCardBox::effect(Game *game)
{
    game->drawCard();
}

DrawCardBox::~DrawCardBox()
{
}
