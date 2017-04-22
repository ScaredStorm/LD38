#pragma once
#include "IState.h"

namespace Core
{
	class Game;
}

namespace State
{
	class SMenu : public IState
	{
	public:
		SMenu(Core::Game* game);
		~SMenu();

		void handleEvents(sf::Event& event) override;
		void update(float delta) override;
		void render(sf::RenderWindow& window) override;
	};
}
