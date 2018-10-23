#ifndef BOX_MOVEBOX_H_
#define BOX_MOVEBOX_H_

#include "Box.h"

class MoveBox: public Box
{
	protected:
		int movement ;

	public:
		MoveBox(int movement) ;
		void effect(Game* game) override;
		void setMovement(int movement) ;
		int getMovement() ;
		~MoveBox();
} ;

#endif /* BOX_MOVEBOX_H_ */
