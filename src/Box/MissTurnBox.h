#ifndef BOX_MISSTURNBOX_H_
#define BOX_MISSTURNBOX_H_

#include "Box.h"

class MissTurnBox : public Box
{
	protected:
		int turns ;

	public:
		MissTurnBox(int turns) ;
		void effect(Game* game) override;
		void setTurns(int turns) ;
    	int getTurns();
    	~MissTurnBox();
} ;

#endif /* BOX_MISSTURNBOX_H_ */
