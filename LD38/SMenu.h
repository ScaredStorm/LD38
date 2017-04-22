#ifndef SMENU_H
#define SMENU_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "IState.h"

namespace State
{
	class SMenu : public IState
	{
	public:
		SMenu(Core::Game* game);
		~SMenu();

		void initialize() override;
		void handleEvents(sf::Event& event) override;
		void update(float delta) override;
		void render(sf::RenderWindow& window) override;

	private:
		sf::Sprite m_background;
		sf::Sprite m_planet;

		sf::Text m_title;
		sf::Text m_copyright;
		sf::Text m_start;

		float m_timer = 0.0f;
		float m_moveAmount = 10.0f;
	};
}

#endif /* SMENU_H */