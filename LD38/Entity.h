#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable
{
public:
	Entity(const sf::Texture& texture);

	virtual void handleEvents(sf::Event& event) = 0;
	virtual void update(float delta) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states);

protected:
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
};

#endif /* ENTITY_H */
