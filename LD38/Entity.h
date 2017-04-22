#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable
{
public:
	Entity();
	~Entity();

	virtual void update(float delta) = 0;
	virtual void handleEvents(sf::Event& event) = 0;

private:
	sf::Sprite m_sprite;

};

#endif /* ENTITY_H */
