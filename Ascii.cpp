#include "Ascii.h"

void Ascii::printAscii(int x, int y, unsigned char ch, SDL_Surface *dst)
{
	SDL_Rect dest = { x, y, TILESIZE, TILESIZE };
	SDL_Rect target = { ch % 16 * 8, ch / 16 * 8, TILESIZE, TILESIZE };

	SDL_BlitSurface(asciiTable, &target, dst, &dest);

}

Ascii::Ascii()
{
	asciiTable = IMG_Load("terminal8x8.png");
	asciiTable == NULL ? printf("Could not load ascii! IMG_Error: %s\n", IMG_GetError()) : printf("Loaded ascii!\n");
}


Ascii::~Ascii()
{
	SDL_FreeSurface(asciiTable);
}
