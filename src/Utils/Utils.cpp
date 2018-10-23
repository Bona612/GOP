#include <cstdio>
#include <iostream>
#include <cstring>
#include "Utils.h"
#include "../Color/Color.h"

using namespace std ;

//metodo che converte un intero in una stringa
char *iToStr(int n, char *str)
{
    if(str == nullptr)
    {
        return nullptr ;
    }
    sprintf(str, "%d", n) ;
    return str ;
}


//separa i turni dei giocatori
void separate()
{
    for (int i = 0; i < 150; ++i)
    {
        cout << "-" ;
    }
    cout << endl ;
}

void clearCin()
{
    cin.clear() ;
    cin.ignore(numeric_limits<streamsize>::max(), '\n') ;
}

//premere invio per continuare
void pause()
{
    clearCin() ;
    cin.putback('\n') ;
    cin.get() ;
}

//restituisce il numero successivo
int next(int i)
{
    i = ((i == 6) ? 1 : i++);
    return i;
}

//metodo che restituisce l'intero a cui si riferisce il colore dato in input
int getCharColor(char *c)
{
	if(strcmp(c, "red") == 0)
	{
		return 0;
	}
	else if(strcmp(c, "green") == 0)
	{
		return 1;
	}
	else if(strcmp(c, "blue") == 0)
	{
		return 2;
	}
	else if(strcmp(c, "yellow") == 0)
	{
		return 3;
	}
	else if(strcmp(c, "magenta") == 0)
	{
		return 4;
	}
	else if(strcmp(c, "cyan") == 0)
	{
		return 5;
	}
	else if(strcmp(c, "white") == 0)
	{
		return 6;
	}
	else
	{
		return -1;
	}
}
