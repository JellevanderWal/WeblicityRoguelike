#include "Engine.h"

void Engine::initSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO) < 0) 
	{
		gameOver = true;
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		rootWindow = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ROOTWIDTH, ROOTHEIGHT, SDL_WINDOW_SHOWN);
		if(rootWindow == NULL)
		{
			gameOver = true;
			printf("SDL could not create the root window! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			rootSurface = SDL_GetWindowSurface(rootWindow);
			printf("SDL was initialized successfully!\n");			
		}
	}
}


//handle input
void Engine::handleEvents() 
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			gameOver = true;

		if (e.key.state == SDL_PRESSED) {
			switch (e.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				gameOver = true;
				break;
			default:
				break;
			}
		}
	}
}

//render to root window
void Engine::render() 
{
	SDL_FillRect(rootSurface, NULL, SDL_MapRGB(rootSurface->format, 0, 0, 0));

	player->Render(rootSurface);

	SDL_UpdateWindowSurface(rootWindow);
}

Engine::Engine() : rootSurface(NULL), rootWindow(NULL), gameOver(false), asciiImage(NULL)
{
	initSDL();

	ascii = new Ascii();

	player = new Player();
	player->setAscii(ascii);
	printf("%c\n", (char)player->ch);
}

Engine::~Engine()
{
	delete player;
	delete ascii;
	SDL_FreeSurface(asciiImage);
	SDL_FreeSurface(rootSurface);
	SDL_DestroyWindow(rootWindow);
	SDL_Quit();
}
