#include "Planet.h"

namespace Level
{
	Planet::Planet(const sf::Texture& texture)
		: m_position({0.0f, 0.0f})
	{
		m_sprite.setTexture(texture);
		m_sprite.setOrigin(sf::Vector2f{ 170.0f, 170.0f });
		m_radius = 170.0f;
	}

	void Planet::render(sf::RenderWindow& window)
	{
		window.draw(m_sprite);
	}

	const sf::Vector2f& Planet::getPosition() const
	{
		return m_position;
	}

	void Planet::setPosition(const sf::Vector2f& position)
	{
		m_position = position;
		m_sprite.setPosition(m_position);
	}

	float Planet::getRadius() const
	{
		return m_radius;
	}
}