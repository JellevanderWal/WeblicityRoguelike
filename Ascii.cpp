#include "Ascii.h"


void Ascii::printAscii(int x, int y, unsigned char ch, SDL_Surface *dst)
{
	SDL_Rect dest = { x, y, TILESIZE, TILESIZE };
	SDL_Rect target = { ch % 16 * 8, ch / 16 * 8, TILESIZE, TILESIZE };

	SDL_LockSurface(asciiTable);
	Uint8 pixels = *(Uint8*)asciiTable->pixels;
	SDL_UnlockSurface(asciiTable);
	SDL_Color *color = &asciiTable->format->palette->colors[pixels];
	color->r = printColor.r;
	color->g = printColor.g;
	color->b = printColor.b;
	SDL_SetPaletteColors(asciiTable->format->palette, color, 1, 255);
	SDL_SetPaletteColors(asciiTable->format->palette, new SDL_Color{0, 0, 0, 255} , 0, 1);

	SDL_BlitSurface(asciiTable, &target, dst, &dest);
}

void Ascii::setPrintColor(Color color) 
{
	printColor = color;
}

Ascii::Ascii()
{
	asciiTable = IMG_Load("terminal8x8.png");
	asciiTable == NULL ? printf("Could not load ascii! IMG_Error: %s\n", IMG_GetError()) : printf("Loaded ascii!\n");
	printColor = WHITE;
}


Ascii::~Ascii()
{

}
