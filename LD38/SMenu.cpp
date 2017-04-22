#include "SMenu.h"
#include <iostream>
#include <cmath>
#include "SPlaying.h"

namespace State {

	SMenu::SMenu(Core::Game* game)
	{
		this->game = game;
	}

	SMenu::~SMenu()
	{
	}

	void SMenu::initialize()
	{
		m_background.setTexture(game->resourceManager().textures["background"]);
		m_planet.setTexture(game->resourceManager().textures["planet"]);
		m_planet.setOrigin(sf::Vector2f{m_planet.getGlobalBounds().width / 2, m_planet.getGlobalBounds().height / 2});
		m_planet.setPosition(sf::Vector2f{ game->width() / 2.0f, game->height() / 2.0f });

		sf::Font& font = game->resourceManager().fonts["main"];
		m_title.setFont(font);
		m_title.setString("Tiny Safe World");
		m_title.setFillColor(sf::Color::White);
		m_title.setCharacterSize(115);
		m_title.setOrigin(sf::Vector2f{ m_title.getGlobalBounds().width / 2, m_title.getGlobalBounds().height / 2 });

		m_copyright.setFont(font);
		m_copyright.setCharacterSize(30);
		m_copyright.setString("A game by Sander Boelhouwers for LD38");
		m_copyright.setFillColor(sf::Color::White);
		m_copyright.setOrigin(sf::Vector2f{ m_copyright.getGlobalBounds().width / 2, m_copyright.getGlobalBounds().height / 2 });
		m_copyright.setPosition(sf::Vector2f{ game->width() / 2.0f, (game->height() / 2.0f) + m_copyright.getGlobalBounds().height });

		// set the position for the title based on the copyright text

		m_title.setPosition(sf::Vector2f{ game->width() / 2.0f, (game->height() / 2.0f) - (m_title.getGlobalBounds().height / 2) - m_copyright.getGlobalBounds().height });

		m_start.setFont(font);
		m_start.setCharacterSize(30);
		m_start.setString("press <space> to start");
		m_start.setFillColor(sf::Color::White);
		m_start.setOrigin(sf::Vector2f{ m_start.getGlobalBounds().width / 2, m_start.getGlobalBounds().height / 2 });
		m_start.setPosition(sf::Vector2f{ game->width() / 2.0f, game->height() - 150.0f });
	}

	void SMenu::handleEvents(sf::Event& event)
	{
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Space)
		{
			game->stateManager().change<SPlaying>(game);
		}
	}

	void SMenu::update(float delta)
	{
		// move the start text up and down
		m_timer += delta;
		float offset = sinf(m_timer) * m_moveAmount;
		m_start.setPosition(sf::Vector2f{ game->width() / 2.0f, (game->height() - 150.0f) + offset });
	}

	void SMenu::render(sf::RenderWindow& window)
	{
		window.draw(m_background);
		window.draw(m_planet);

		window.draw(m_title);
		window.draw(m_copyright);
		window.draw(m_start);
	}
}