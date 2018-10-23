#ifndef BOX_FINISHBOX_H_
#define BOX_FINISHBOX_H_

#include "Box.h"

class FinishBox : public Box
{
	public:
    	FinishBox() ;
    	void effect(Game* game) override;
    	~FinishBox();
} ;

#endif /* BOX_FINISHBOX_H_ */
