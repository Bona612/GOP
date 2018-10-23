#include <cstring>
#include "Color.h"

//qui sotto ci sono le sequenze di escape che sono state utilizzate per far vedere a video i colori
const char* getReset()
{
    return "\033[0m";
}

const char*getRed()
{
    return "\033[0;31m";
}

const char* getGreen()
{
    return "\033[0;32m";
}

const char* getBlue()
{
    return "\033[0;34m";
}

const char* getYellow()
{
    return "\033[0;33m";
}

const char* getMagenta()
{
    return "\033[0;35m";
}

const char* getCyan()
{
    return "\033[0;36m";
}

const char* getWhite()
{
    return "\033[0;37m";
}

//metodo che ritorna la sequenza di escape del colore che si ha dato in input
const char* getColor(Color c)
{
	switch (c)
	{
		case Color::red:
			return getRed();
		case Color::blue:
			return getBlue();
		case Color::cyan:
			return getCyan();
		case Color::green:
			return getGreen();
		case Color::magenta:
			return getMagenta();
	    case Color::yellow:
	    	return getYellow();
	    case Color::white:
	    	return getWhite();
	    default:
	    	return getReset();
	}
}

//ritorna l'intero a cui si riferisce il colore richiesto
const int getIntColor(Color c)
{
    switch (c)
    {
        case Color::red:
            return 0;
        case Color::green:
            return 1;
        case Color::blue:
            return 2;
        case Color::yellow:
            return 3;
        case Color::magenta:
            return 4;
        case Color::cyan:
            return 5;
        case Color::white:
            return 6;
        default:
            return -1;
    }
}

//aggiunge le sequenze di escape per colorare la stringa su terminale
void add_color(char* dest, char* s, Color c)
{
    strcpy(dest, getColor(c));
    strcat(dest, s);
    strcat(dest, getReset());
}

//come l'add_color, con la differenza di un campo che è const
void add_const_color(char* dest, const char* s, Color c)
{
    strcat(dest, getColor(c));
    strcat(dest, s);
    strcat(dest, getReset());
}
