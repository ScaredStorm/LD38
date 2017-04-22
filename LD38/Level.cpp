#include "Level.h"

namespace Level
{
	Level::Level()
	{
	}

	void Level::handleEvents(sf::Event& event)
	{
	}

	void Level::update(float delta)
	{
	}

	void Level::render(sf::RenderWindow& window)
	{
		for (const auto& entity : m_entities)
		{
			//window.draw(entity);
		}
	}
}
