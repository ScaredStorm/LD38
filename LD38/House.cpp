#include "House.h"
#include "Level.h"
#include <cmath>

House::House(Level::Level* level, const sf::Texture& texture)
	: Entity(level, texture, "house")
{
	m_maxHealth = 100;
	m_health = m_maxHealth;
}

House::~House()
{
}

void House::handleEvents(sf::Event& event)
{
}

void House::update(float delta)
{
}

void House::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void House::calculatePosition()
{
	float x = m_level->getPlanet()->getPosition().x + cosf(to_radians(theta)) * m_level->getPlanet()->getRadius();
	float y = m_level->getPlanet()->getPosition().y + sinf(to_radians(theta)) * m_level->getPlanet()->getRadius();
	setPosition({ x, y });
	m_sprite.setRotation(to_degrees(getDirectionToPlanet()) + 90.0f);
}