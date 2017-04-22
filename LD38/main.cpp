#include "Game.h"
#include "Random.h"
#include <iostream>

int main(int argc, const char* argv[])
{
	Core::Game g("LD38", 1280, 720);
	g.run();

	return 0;
}