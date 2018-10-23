#include "StartBox.h"

StartBox::StartBox()
{
    setText((char *)("Partenza")) ;
    this->color = Color::green ;
    this->setType(Start) ;
}

StartBox::~StartBox()
{
}
