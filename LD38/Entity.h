#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity
{
public:
	virtual void handleEvents(sf::Event& event) = 0;
	virtual void update(float delta) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual const sf::Vector2f& getPosition() = 0;
	virtual void setPosition(const sf::Vector2f& position) = 0;

protected:
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
};

#endif /* ENTITY_H */
