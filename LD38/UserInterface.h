#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <SFML/Graphics.hpp>
#include <string>

namespace Core
{
	class Game;
}

class Player;
class House;

namespace UI
{
	class UserInterface
	{
	public:
		UserInterface(Core::Game* game);
		~UserInterface();

		void update(float delta);
		void render(sf::RenderWindow& window);

		void setMessage(const std::string& message, float duration);
		void hideMessage();
		void setScore(const int& score);

		void setGameOver(const int& waves, const int& score);

	public:
		/* BY PUTTING THESE CLASSES AS PUBLIC ACCESSABLE MEANS THAT I'M LAZY */
		Player* player;
		House* house;

	private:
		int calculatePercentage(int amount, int maxAmount);

	private:
		Core::Game* game;
		sf::Font m_mainFont;
		sf::Text m_playerHealth;
		sf::Text m_houseHealth;
		sf::Text m_message;
		sf::Text m_scoreLabel;

		bool m_messageVisible;
		float m_messageDuration;

		sf::Text m_title;
		sf::Text m_gameOverText;
		sf::Text m_start;
		bool m_gameOver;
	};
}

#endif /* USERINTERFACE_H */
