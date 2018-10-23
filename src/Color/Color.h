#ifndef COLOR_COLOR_H_
#define COLOR_COLOR_H_

#include <iostream>

using namespace std;

enum Color {red=0, green=1, blue=2, yellow=3, magenta=4, cyan=5, white=6};

const char* getRed();
const char* getGreen();
const char* getBlue();
const char* getYellow();
const char* getMagenta();
const char* getCyan();
const char* getWhite();
const char* getReset();
const char* getColor(Color c);
void add_color(char* dest, char* s, Color c);
void add_const_color(char* dest, const char* s, Color c);

#endif /* COLOR_COLOR_H_ */
