#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#define TILESIZE 8

class Ascii
{
public:
	Ascii();
	~Ascii();
	void printAscii(int x, int y, unsigned char ch, SDL_Surface *dst);
private:
	SDL_Surface* asciiTable;
};

