#include "Engine.h"

int main(int argc, char* args[]) 
{
	Engine *engine = new Engine();
	while (!engine->gameOver) 
	{
		engine->render();
		engine->handleEvents();
	}
	delete engine;
	return 0;
}

