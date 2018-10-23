#ifndef PLAYER_PLAYER_H_
#define PLAYER_PLAYER_H_

#include "../Color/Color.h"

class Player
{
	private:
    	char name[50] ;
    	int pos ;
    	int numTurns ;
    	Color color ;

    	void setName(char *name);
    	void add_color(int pos) ;

	public:
    	Player(char *name, int pos) ;
    	char *getName() ;
    	void setPos(int pos) ;
    	int getPos() ;
    	void setNumTurns(int numTurns) ;
    	int getNumTurns() ;
    	bool isBlocked() ;
    	void decNumTurns() ;
    	Color getColorPlayer();
    	~Player();
} ;

#endif /* PLAYER_PLAYER_H_ */
