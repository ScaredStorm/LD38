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
#include "Random.h"

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

		void increaseScore(int amount);
		bool isGameOver() const;
		
	private:
		void removeDeadObjects();
		void handleCollision();

	private:
		void gameController(float delta);

	private:
		Core::Game* game; // only for the resource manager and the statemanager
		UI::UserInterface m_ui;

		std::vector<std::unique_ptr<Bullet>> m_bullets; // player bullets
		std::vector<std::unique_ptr<Entity>> m_entities; // aliens
		std::unique_ptr<Player> m_player;
		std::unique_ptr<House> m_house;
		Planet m_planet;

		int m_currentWave;
		float m_waitAmount;
		float m_waitTimer;
		bool m_pushedMessage;

		bool m_gameOver;
		int m_score;

		Random<std::minstd_rand> r;
	};
}

#endif /* LEVEL_H */
