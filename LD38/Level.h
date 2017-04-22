#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "Entity.h"

namespace Level
{
	class Level
	{
	public:
		Level();

		void handleEvents(sf::Event& event);
		void update(float delta);
		void render(sf::RenderWindow& window);

	private:
		std::vector<std::unique_ptr<Entity>> m_entities;
	};
}

#endif /* LEVEL_H */
