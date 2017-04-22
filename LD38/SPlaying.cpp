#include "SPlaying.h"
#include <iostream>

namespace State
{
	SPlaying::SPlaying(Core::Game* game)
		: m_level(game)
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
		m_level.handleEvents(event);
	}
	
	void SPlaying::update(float delta)
	{
		m_level.update(delta);
	}
	
	void SPlaying::render(sf::RenderWindow& window)
	{
		window.draw(background);
		m_level.render(window);
	}
}