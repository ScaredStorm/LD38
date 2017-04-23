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

		m_entities.push_back(std::make_unique<Alien>(this, game->resourceManager().textures["alien"]));

		/* wave stuff */
		m_currentWave = 0;
		m_waveStarted = false;
		m_waveFinished = false;
		m_didFinishSpawning = false;
		m_waveTimer = 0.0f;
	}

	void Level::handleEvents(sf::Event& event)
	{
		for (auto it = std::begin(m_entities); it != std::end(m_entities); ++it)
		{
			(*it)->handleEvents(event);
		}
		if (m_player != nullptr) m_player.get()->handleEvents(event);
	}

	void Level::update(float delta)
	{
		// update bullets
		for (auto it = std::begin(m_bullets); it != std::end(m_bullets); ++it)
		{
			(*it)->update(delta);
		}

		// update entities
		for (auto it = std::begin(m_entities); it != std::end(m_entities); ++it)
		{
			(*it)->update(delta);
		}
		if (m_player != nullptr) m_player.get()->update(delta);

		handleCollision();

		// update ui
		m_ui.update(delta);

		removeDeadObjects();
	}

	void Level::render(sf::RenderWindow& window)
	{
		m_planet.render(window);
		if (m_house != nullptr) m_house->render(window);

		// render bullets
		for (const auto& e : m_bullets)
		{
			e.get()->render(window);
		}

		// render entities
		for (const auto& e : m_entities)
		{
			e.get()->render(window);
		}

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
		m_currentWave++;
	}

	void Level::createBullet(const int& direction, const float& theta)
	{
		std::unique_ptr<Bullet> b = std::make_unique<Bullet>(this, game->resourceManager().textures["bullet"], direction);
		b->setTheta(theta);
		m_bullets.push_back(std::move(b));
	}

	void Level::removeDeadObjects()
	{
		m_bullets.erase(std::remove_if(std::begin(m_bullets), std::end(m_bullets), [](const std::unique_ptr<Bullet>& o) {
			return !o.get()->isAlive();
		}), std::end(m_bullets));

		m_entities.erase(std::remove_if(std::begin(m_entities), std::end(m_entities), [](const std::unique_ptr<Entity>& o) {
			return !o.get()->isAlive();
		}), std::end(m_entities));
	}

	void Level::handleCollision()
	{
		for (auto it = std::begin(m_bullets); it != std::end(m_bullets); ++it)
		{
			for (auto et = std::begin(m_entities); et != std::end(m_entities); ++et)
			{
				if ((*it)->getBbox().intersects((*et)->getBbox()))
				{
					(*it)->handleCollision((*et).get());
					(*et)->handleCollision((*it).get());
				}
			}
		}
	}
}
