#include "Entity.h"
#include "Level.h"

Entity::Entity(Level::Level* level)
{
	this->m_level = level;
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