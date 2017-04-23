#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "Entity.h"
#include "Player.h"
#include "Game.h"
#include "Planet.h"
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

	private:
		Core::Game* game; // only for the resource manager and the statemanager
		UI::UserInterface m_ui;

		std::vector<std::unique_ptr<Entity>> m_entities;
		std::unique_ptr<Player> m_player;
		Planet m_planet;
	};
}

#endif /* LEVEL_H */
