#ifndef SPLAYING_H
#define SPLAYING_H

#include <SFML/Graphics.hpp>
#include "IState.h"

namespace Core
{
	class Game;
}

namespace State
{
	class SPlaying : public IState
	{
	public:
		SPlaying(Core::Game* game);
		~SPlaying();

		void handleEvents(sf::Event& event) override;
		void update(float delta) override;
		void render(sf::RenderWindow& window) override;
	};
}

#endif /* SPLAYING_H */