#include "SPlaying.h"
#include <iostream>

namespace State
{
	SPlaying::SPlaying(Core::Game* game)
	{
		this->game = game;
	}

	void SPlaying::initialize()
	{
		background.setTexture(game->resourceManager().textures["background"]);
	}

	SPlaying::~SPlaying()
	{
	}

	void SPlaying::handleEvents(sf::Event& event)
	{
	}
	
	void SPlaying::update(float delta)
	{
		
	}
	
	void SPlaying::render(sf::RenderWindow& window)
	{
		window.draw(background);
	}
}