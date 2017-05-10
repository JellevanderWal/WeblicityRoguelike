#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#define TITLE "Weblicty Roguelike"
#define ROOTWIDTH 512
#define ROOTHEIGHT 256
#ifndef TILESIZE
#include "Ascii.h" 
#include "Player.h"
#endif //TILESIZE


class Engine
{
public:
	Engine();
	~Engine();
	bool gameOver;
	void handleEvents();
	void render();
private:
	SDL_Window *rootWindow;
	SDL_Surface *rootSurface;
	void initSDL();
	SDL_Surface *asciiImage;
	Player* player;
	Ascii *ascii;
};