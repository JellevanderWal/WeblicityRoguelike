#pragma once
#include "Color.h"
#include "Coords.h"
#include "Ascii.h"

class Entity
{
public:
	unsigned char ch;
	Color color;
	Coord coord;
	Ascii *ascii;

	void setAscii(Ascii *ascii);
	void Render(SDL_Surface* dst);

	Entity();
	Entity(unsigned char ch, Color color = WHITE, Coord coord = Coord(0,0));
	virtual ~Entity();
};

