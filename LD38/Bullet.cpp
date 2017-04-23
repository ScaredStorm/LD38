#include "Bullet.h"
#include "Level.h"
#include "Maths.h"

Bullet::Bullet(Level::Level* level, const sf::Texture& texture, const int& direction)
	: Entity(level, texture, "bullet")
{
	m_direction = direction;
	m_damage = 20.0f;
	m_movementSpeed = 35.0f;
	height = 10.0f;

	m_sprite.setScale(m_direction, 1);
	m_maxLifetime = 2.0f;
	m_secondsAlive = 0.0f;
}

Bullet::~Bullet()
{
}

void Bullet::handleEvents(sf::Event& event)
{
}

void Bullet::update(float delta)
{
	if (m_secondsAlive < m_maxLifetime)
	{
		m_secondsAlive += delta;
	}
	else
	{
		alive = false;
	}

	theta += m_movementSpeed * delta * m_direction;

	float newX = m_level->getPlanet()->getPosition().x + cosf(to_radians(theta)) * (m_level->getPlanet()->getRadius() + height);
	float newY = m_level->getPlanet()->getPosition().y + sinf(to_radians(theta)) * (m_level->getPlanet()->getRadius() + height);
	setPosition({ newX, newY });
	rotate();
}

void Bullet::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Bullet::handleCollision(Entity * o)
{
	alive = false;
}

int Bullet::getDamageAmount()
{
	return m_damage;
}

void Bullet::rotate()
{
	float angle = getDirectionToPlanet();
	m_sprite.setRotation(to_degrees(angle) + 90.0f);
}
