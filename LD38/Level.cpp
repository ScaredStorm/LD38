#include "Level.h"
#include <iterator>

namespace Level
{
	Level::Level(Core::Game* game)
	{
		this->game = game;
	}

	void Level::handleEvents(sf::Event& event)
	{

	}

	void Level::update(float delta)
	{
		for (auto it = std::begin(m_entities); it != std::end(m_entities); ++it)
		{
			(*it)->update(delta);
		}
	}

	void Level::render(sf::RenderWindow& window)
	{
		for (const auto& e : m_entities)
		{
			window.draw(*e);
		}
	}
}
