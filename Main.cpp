#include "Engine.h"

int main(int argc, char* args[]) 
{
	Engine *engine = new Engine();
	while (!engine->gameOver) 
	{
		engine->handleEvents();
	}
	delete engine;
	return 0;
}

