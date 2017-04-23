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

		controlGame(delta);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			std::unique_ptr<Alien> a = std::make_unique<Alien>(this, game->resourceManager().textures["alien"]);
			sf::Vector2i mousePos = sf::Mouse::getPosition(game->window());
			
			float dx = mousePos.x - m_planet.getPosition().x;
			float dy = mousePos.y - m_planet.getPosition().y;
			float angle = atan2f(dy, dx);

			a->setTheta(to_degrees(angle));

			m_entities.push_back(std::move(a));
		}

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

	void Level::controlGame(float delta)
	{
		if (m_currentWave > 0)
		{
			if (!m_waveStarted && m_waveFinished)
			{
				m_currentWave++;
				m_waveTimer = 3.0f;
				m_waveStarted = true;
				m_ui.setMessage("wave starts in 3 seconds", 3.0f);
			}
			waveStart(delta);
		}
	}

	void Level::waveStart(float delta)
	{
		if (m_waveStarted)
		{
			if (m_waveFinished)
			{
				if (m_waveTimer > 0.0f)
				{
					m_waveTimer -= delta;
				}
				else
				{
					// actually started right now
					m_waveFinished = false;
					spawnWave();
				}
			}
		}
	}

	void Level::spawnWave()
	{
		int totalEnemies = m_currentWave*m_currentWave;
	}

	void Level::enemyCheck()
	{
		if (m_entities.size() == 0)
		{

		}
	}
}
