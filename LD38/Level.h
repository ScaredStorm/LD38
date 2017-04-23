#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "Entity.h"
#include "Player.h"
#include "Alien.h"
#include "Game.h"
#include "Planet.h"
#include "House.h"
#include "Bullet.h"
#include "UserInterface.h"

namespace Level
{

	class Level
	{
	public:
		Level(Core::Game* game);
		Level(const Level& level)					= delete;
		Level(Level&& level)						= delete;
		Level& operator= (const Level& level)		= delete;
		Level& operator= (Level&& level)			= delete;

		void handleEvents(sf::Event& event);
		void update(float delta);
		void render(sf::RenderWindow& window);

		Entity* getEntity(size_t id);
		Player* getPlayer();
		Planet* getPlanet();

		House* getHouse();
		void createHouse(const float& theta);
		void createBullet(const int& direction, const float& theta);

	private:
		void removeDeadObjects();
		void handleCollision();

	private:
		Core::Game* game; // only for the resource manager and the statemanager
		UI::UserInterface m_ui;

		std::vector<std::unique_ptr<Bullet>> m_bullets; // player bullets
		std::vector<std::unique_ptr<Entity>> m_entities; // aliens
		std::unique_ptr<Player> m_player;
		std::unique_ptr<House> m_house;
		Planet m_planet;

		int m_currentWave;
		bool m_waveStarted;
		bool m_waveFinished;
		bool m_didFinishSpawning;
		float m_waveTimer;
	};
}

#endif /* LEVEL_H */
