#include <ctime>
#include <cstdlib>
#include "Dice.h"

Dice::Dice()
{
	srand((unsigned)time(NULL));
}

//metodo che simula il lancio di un dado (ritorna un valore compreso tra 1 e 6)
int Dice::throwDice()
{
	return (rand() % 6 + 1);
}

Dice::~Dice()
{
}
