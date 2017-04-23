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

		m_message.setFont(m_mainFont);
		m_message.setCharacterSize(48);
		m_message.setPosition(game->width() / 2.0f, game->height() - 128);
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

		if (house != nullptr)
		{
			window.draw(m_houseHealth);
		}

		if (m_messageVisible)
		{
			window.draw(m_message);
		}
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

	int UserInterface::calculatePercentage(int amount, int maxAmount)
	{
		return 100 * amount / maxAmount;
	}
}
