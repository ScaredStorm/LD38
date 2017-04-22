#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "Entity.h"
#include "Game.h"

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

	private:
		Core::Game* game; // only for the resource manager and the statemanager
		std::vector<std::unique_ptr<Entity>> m_entities;
	};
}

#endif /* LEVEL_H */
