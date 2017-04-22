#include "SPlaying.h"
#include <iostream>

namespace State
{
	SPlaying::SPlaying(Core::Game* game)
	{
		this->game = game;
	}

	SPlaying::~SPlaying()
	{
	}

	void SPlaying::handleEvents(sf::Event & event)
	{
	}
	
	void SPlaying::update(float delta)
	{
	}
	
	void SPlaying::render(sf::RenderWindow & window)
	{
	}
}