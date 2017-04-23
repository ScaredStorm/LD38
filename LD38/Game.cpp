#include "Game.h"
#include "SMenu.h"

namespace Core
{
	Game::Game(std::string&& title, unsigned int width, unsigned int height)
		: m_width(width)
		, m_height(height)
		, m_window(sf::VideoMode(width, height), title, sf::Style::Default)
	{
		m_window.setFramerateLimit(60);
		m_stateManager.push<State::SMenu>(this);

		sf::Image icon;
		if (icon.loadFromFile("Assets/Textures/icon.png"))
		{
			m_window.setIcon(32, 32, icon.getPixelsPtr());
		}
	}

	Game::~Game()
	{
	}

	void Game::run()
	{
		sf::Clock clock;
		while (m_window.isOpen())
		{
			sf::Event e;
			while (m_window.pollEvent(e))
			{
				handleEvents(e);
			}

			float delta = clock.restart().asSeconds();
			update(delta);
			render();
		}
	}

	void Game::quit()
	{
		m_window.close();
	}

	void Game::handleEvents(sf::Event& event)
	{
		if (event.type == sf::Event::Closed)
			quit();

		m_stateManager.handleEvents(event);
	}

	void Game::update(float delta)
	{
		m_stateManager.update(delta);
	}

	void Game::render()
	{
		m_window.clear();
		m_stateManager.render(m_window);
		m_window.display();
	}

	State::StateManager<Game>& Game::stateManager()
	{
		return m_stateManager;
	}

	ResourceManager& Game::resourceManager()
	{
		return m_resourceManager;
	}

	sf::RenderWindow& Game::window()
	{
		return m_window;
	}

	unsigned int Game::width() const
	{
		return m_width;
	}

	unsigned int Game::height() const
	{
		return m_height;
	}
}
