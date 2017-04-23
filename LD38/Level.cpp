#include "Level.h"
#include <iterator>

namespace Level
{
	Level::Level(Core::Game* game)
		: m_planet(game->resourceManager().textures["planet"])
		, m_ui(game)
	{
		this->game = game;
		m_player = std::make_unique<Player>(this, game->resourceManager().textures["player"]);

		m_planet.setPosition({ game->width() / 2.0f, game->height() / 2.0f });

		m_ui.player = m_player.get();
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
		if (m_player != nullptr) m_player.get()->update(delta);

		// update ui
		m_ui.update(delta);
	}

	void Level::render(sf::RenderWindow& window)
	{
		m_planet.render(window);
		for (const auto& e : m_entities)
		{
			e.get()->render(window);
		}

		// render default objects
		if (m_house != nullptr) m_house->render(window);
		if (m_player != nullptr) m_player.get()->render(window);

		// render ui
		m_ui.render(window);
	}

	Entity* Level::getEntity(size_t id)
	{
		if (id >= m_entities.size())
			return nullptr;
		return m_entities[id].get();
	}

	Player* Level::getPlayer()
	{
		return m_player.get();
	}

	Planet* Level::getPlanet()
	{
		return &m_planet;
	}

	House* Level::getHouse()
	{
		return m_house.get();
	}

	void Level::createHouse(const float& theta)
	{
		m_house = std::make_unique<House>(this, game->resourceManager().textures["house"]);
		m_house->setTheta(theta);
		m_house->calculatePosition();

		// pass the house to the ui
		m_ui.house = m_house.get();
	}
}
