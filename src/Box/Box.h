#ifndef BOX_BOX_H_
#define BOX_BOX_H_

class Game ;
#include "../Game/Game.h"
#include "../Color/Color.h"

enum BoxType
{
    Default,
    Void,
    Start,
    Finish,
    Move,
    DrawCard,
    MissTurn,
    BackStart
} ;

class Box
{
	protected:
    	char text[100] ;
    	Color color ;
    	BoxType type ;

	public:
    	Box() ;
    	virtual void effect(Game* game) ;
    	Color getColor();
    	char* getText() ;
    	void setText(char* text) ;
    	BoxType getType() ;
    	void setType(BoxType type);
    	virtual ~Box();
} ;

#endif /* BOX_BOX_H_ */
