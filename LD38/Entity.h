#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "Maths.h"

namespace Level
{
	class Level;
}

class Entity
{
public:
	Entity(Level::Level* level, const sf::Texture& texture);

	virtual void handleEvents(sf::Event& event) = 0;
	virtual void update(float delta) = 0;
	virtual void render(sf::RenderWindow& window) = 0;

	virtual const sf::Vector2f& getPosition();
	virtual void setPosition(const sf::Vector2f& position);

protected:
	virtual float getDirectionToPlanet();
	virtual float getDistanceToPlanet();

protected:
	Level::Level* m_level;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;

};

#endif /* ENTITY_H */
