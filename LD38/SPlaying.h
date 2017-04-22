#ifndef SPLAYING_H
#define SPLAYING_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "IState.h"
#include "Level.h"

namespace State
{
	class SPlaying : public IState
	{
	public:
		SPlaying(Core::Game* game);
		~SPlaying();

		void initialize() override;
		void handleEvents(sf::Event& event) override;
		void update(float delta) override;
		void render(sf::RenderWindow& window) override;

	private:
		sf::Sprite background;
		Level::Level m_level;
	};
}

#endif /* SPLAYING_H */