#include "Entity.h"

Entity::Entity(const sf::Texture& texture)
{
	this->m_sprite.setTexture(texture);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states)
{
	target.draw(m_sprite, states);
}