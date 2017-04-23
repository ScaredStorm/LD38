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

		bool m_messageVisible;
		float m_messageDuration;
	};
}

#endif /* USERINTERFACE_H */
