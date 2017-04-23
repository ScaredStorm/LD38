#include "UserInterface.h"
#include "Game.h"
#include "Player.h"
#include "House.h"

namespace UI
{
	UserInterface::UserInterface(Core::Game* game)
	{
		this->game = game;
		m_mainFont = game->resourceManager().fonts["main"];
		m_gameOver = false;
		
		/* SET THE TEXT */
		m_playerHealth.setFont(m_mainFont);
		m_playerHealth.setFillColor(sf::Color::White);
		m_playerHealth.setCharacterSize(30);
		m_playerHealth.setPosition(20, 20);
		m_playerHealth.setString("HP: ");
		
		m_houseHealth.setFont(m_mainFont);
		m_houseHealth.setFillColor(sf::Color::White);
		m_houseHealth.setCharacterSize(30);
		m_houseHealth.setPosition(20, 20); // 20, 60
		m_houseHealth.setString("HOUSE: ");

		m_scoreLabel.setFont(m_mainFont);
		m_scoreLabel.setFillColor(sf::Color::White);
		m_scoreLabel.setCharacterSize(30);
		m_scoreLabel.setPosition(game->width() - 20, 20); // 20, 60
		m_scoreLabel.setString("SCORE: 0");
		m_scoreLabel.setOrigin(m_scoreLabel.getGlobalBounds().width, 0);

		m_message.setFont(m_mainFont);
		m_message.setCharacterSize(48);
		m_message.setPosition(game->width() / 2.0f, game->height() - 128);

		m_title.setFont(m_mainFont);
		m_title.setString("Game Over");
		m_title.setFillColor(sf::Color::White);
		m_title.setCharacterSize(115);
		m_title.setOrigin(sf::Vector2f{ m_title.getGlobalBounds().width / 2, m_title.getGlobalBounds().height / 2 });

		m_gameOverText.setFont(m_mainFont);
		m_gameOverText.setFillColor(sf::Color::White);
		m_gameOverText.setCharacterSize(30);

		m_start.setFont(m_mainFont);
		m_start.setCharacterSize(30);
		m_start.setString("press <space> to restart");
		m_start.setFillColor(sf::Color::White);
		m_start.setOrigin(sf::Vector2f{ m_start.getGlobalBounds().width / 2, m_start.getGlobalBounds().height / 2 });
		m_start.setPosition(sf::Vector2f{ game->width() / 2.0f, game->height() - 150.0f });
	}

	UserInterface::~UserInterface()
	{
	}

	void UserInterface::update(float delta)
	{
		// Sloppy ui updates... not very nice and not very amazing with caching
		if (player != nullptr)
		{
			std::string hp = "HP: " + std::to_string(calculatePercentage(player->getHealth(), player->getMaxHealth())) + "%";
			m_playerHealth.setString(hp);
		}

		if (house != nullptr)
		{
			std::string hhp = "HOUSE: " + std::to_string(calculatePercentage(house->getHealth(), house->getMaxHealth())) + "%";
			m_houseHealth.setString(hhp);
		}
		else
		{
			if (!m_messageVisible)
				setMessage("Press <W> to place your house", 10);
		}

		// update the message visibility
		if (m_messageVisible)
		{
			if (m_messageDuration > 0)
				m_messageDuration -= delta;
			else
				m_messageVisible = false;
		}
	}

	void UserInterface::render(sf::RenderWindow& window)
	{
		/* RE-ADD WHEN MORE TIME */
		/*if (player != nullptr)
		{
			window.draw(m_playerHealth);
		}*/

		if (!m_gameOver)
		{
			if (house != nullptr)
			{
				window.draw(m_houseHealth);
			}

			if (m_messageVisible)
			{
				window.draw(m_message);
			}
		}
		else
		{
			window.draw(m_title);
			window.draw(m_gameOverText);
			window.draw(m_start);
		}
		window.draw(m_scoreLabel);
	}

	void UserInterface::setMessage(const std::string& message, float duration)
	{
		m_messageDuration = duration;
		m_messageVisible = true;
		m_message.setString("- " + message + " -");

		// calculate origin
		m_message.setOrigin(sf::Vector2f{ m_message.getGlobalBounds().width / 2.0f, m_message.getGlobalBounds().height / 2.0f });
	}

	void UserInterface::hideMessage()
	{
		m_messageDuration = 0;
		m_messageVisible = false;
	}

	void UserInterface::setScore(const int& score)
	{
		m_scoreLabel.setString("SCORE: " + std::to_string(score));
		m_scoreLabel.setOrigin(m_scoreLabel.getGlobalBounds().width, 0);
	}

	void UserInterface::setGameOver(const int& waves, const int& score)
	{
		m_gameOver = true;

		m_gameOverText.setString("You survived for " + std::to_string(waves) + " waves with a total score of " + std::to_string(score));
		m_gameOverText.setOrigin(m_gameOverText.getGlobalBounds().width / 2, m_gameOverText.getGlobalBounds().height / 2);
		m_gameOverText.setPosition(sf::Vector2f{ game->width() / 2.0f, (game->height() / 2.0f) + m_gameOverText.getGlobalBounds().height });
		m_title.setPosition(sf::Vector2f{ game->width() / 2.0f, (game->height() / 2.0f) - (m_title.getGlobalBounds().height / 2) - m_gameOverText.getGlobalBounds().height });
	}

	int UserInterface::calculatePercentage(int amount, int maxAmount)
	{
		return 100 * amount / maxAmount;
	}
}
