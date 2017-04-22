#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "StateManager.h"
#include "ResourceManager.h"

namespace Core
{
	class Game
	{
	public:
		Game(std::string&& title, unsigned int width, unsigned int height);
		Game(const Game& g) = delete;
		Game(Game&& g) = delete;
		Game& operator= (const Game& g) = delete;
		Game& operator= (Game&& g) = delete;
		~Game();

		void run();
		void quit();
		void handleEvents(sf::Event& event);
		void update(float delta);
		void render();

		State::StateManager<Game>& stateManager();
		ResourceManager& resourceManager();

	private:
		unsigned int m_width;
		unsigned int m_height;
		std::unique_ptr<sf::RenderWindow> m_window;

		State::StateManager<Game> m_stateManager;
		ResourceManager m_resourceManager;
	};
}

#endif /* GAME_H */