#ifndef BOX_DRAWCARDBOX_H_
#define BOX_DRAWCARDBOX_H_

#include "Box.h"

class DrawCardBox : public Box
{
	public:
    	DrawCardBox() ;
    	void effect(Game* game) override;
    	~DrawCardBox();
} ;

#endif /* BOX_DRAWCARDBOX_H_ */
