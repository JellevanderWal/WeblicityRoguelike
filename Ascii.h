#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Color.h"
#define TILESIZE 8

class Ascii
{
public:
	Ascii();
	~Ascii();

	SDL_Surface* asciiTable;
	void printAscii(int x, int y, unsigned char ch, SDL_Surface *dst);
	void setPrintColor(Color color);
private:
	Color printColor;
};

