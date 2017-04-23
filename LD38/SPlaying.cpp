#include "SPlaying.h"

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
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Space)
		{
			if (m_level.isGameOver())
			{
				game->stateManager().change<SPlaying>(game);
			}
		}
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