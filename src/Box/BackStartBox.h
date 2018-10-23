#ifndef BOX_BACKSTARTBOX_H_
#define BOX_BACKSTARTBOX_H_

#include "Box.h"

class BackStartBox : public Box
{
	public:
    	BackStartBox() ;
    	void effect(Game* game) override;
    	~BackStartBox();
} ;

#endif /* BOX_BACKSTARTBOX_H_ */
