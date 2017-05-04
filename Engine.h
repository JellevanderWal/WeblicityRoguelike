#pragma once
#include <SDL.h>
#include <iostream>
#define TITLE "Weblicty Roguelike"
#define ROOTWIDTH 512
#define ROOTHEIGHT 256


class Engine
{
public:
	Engine();
	~Engine();
	bool gameOver;
	void handleEvents();
private:
	SDL_Window *rootWindow;
	SDL_Surface *rootSurface;
	void initSDL();
};