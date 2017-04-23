#include "Alien.h"
#include "Level.h"
#include <iostream>

Alien::Alien(Level::Level * level, const sf::Texture & texture)
	: Entity(level, texture)
{
	m_maxHealth = 30;
	m_health = 30;

	m_movementSpeed = 25.0f;
	m_gravitySpeed = 40.0f;
	m_grounded = false;

	theta = -180;
	height = 80;
}

Alien::~Alien()
{
}

void Alien::handleEvents(sf::Event & event)
{
}

void Alien::update(float delta)
{
	handleGravity(delta);
	updateAI(delta);

	/* calculate new positions */
	float newX = m_level->getPlanet()->getPosition().x + cosf(to_radians(theta)) * (m_level->getPlanet()->getRadius() + height);
	float newY = m_level->getPlanet()->getPosition().y + sinf(to_radians(theta)) * (m_level->getPlanet()->getRadius() + height);
	setPosition({ newX, newY });
	rotate();
}

void Alien::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

void Alien::handleGravity(float delta)
{
	velocity = (m_grounded) ? 0.0f : velocity - (m_gravitySpeed * delta);
	height = std::max(height + velocity, 0.0f);
	m_grounded = (height > 0) ? false : true;
}

void Alien::updateAI(float delta)
{
	House* house = m_level->getHouse();
	if (house != nullptr)
	{
		float destination = house->getTheta();
		std::cout << destination << " " << getTheta() << std::endl;
	}
}

void Alien::rotate()
{
	float angle = getDirectionToPlanet();
	m_sprite.setRotation(to_degrees(angle) + 90.0f);
}
