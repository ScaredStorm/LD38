#include "Entity.h"
#include "Level.h"

Entity::Entity(Level::Level* level, const sf::Texture& texture, const std::string& name)
	: m_name(name)
{
	this->m_level = level;
	m_sprite.setTexture(texture);
	m_sprite.setOrigin(sf::Vector2f{ m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height - 6 });
	alive = true;
}

void Entity::setTheta(const float & t)
{
	theta = (t > 360) ? t - 360 : t;
}

float& Entity::getTheta()
{
	return theta;
}

const sf::Vector2f& Entity::getPosition()
{
	return m_position;
}

void Entity::setPosition(const sf::Vector2f& position)
{
	m_position = position;
	m_sprite.setPosition(position);
}

bool Entity::isAlive() const
{
	return alive;
}

sf::FloatRect& Entity::getBbox()
{
	return m_sprite.getGlobalBounds();
}

void Entity::handleCollision(Entity* o)
{
}

std::string & Entity::getName()
{
	return m_name;
}

float Entity::getDirectionToPlanet()
{
	float dx = m_position.x - m_level->getPlanet()->getPosition().x;
	float dy = m_position.y - m_level->getPlanet()->getPosition().y;
	return atan2f(dy, dx);
}

float Entity::getDistanceToPlanet()
{
	float dx = m_position.x - m_level->getPlanet()->getPosition().x;
	float dy = m_position.y - m_level->getPlanet()->getPosition().y;
	return sqrtf(dx*dx + dy*dy);
}