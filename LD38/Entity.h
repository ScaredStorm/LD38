#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Maths.h"

namespace Level
{
	class Level;
}

class Entity
{
public:
	Entity(Level::Level* level, const sf::Texture& texture, const std::string& name);

	virtual void handleEvents(sf::Event& event) = 0;
	virtual void update(float delta) = 0;
	virtual void render(sf::RenderWindow& window) = 0;

	virtual void setTheta(const float& t);
	virtual float& getTheta();
	virtual const sf::Vector2f& getPosition();
	virtual void setPosition(const sf::Vector2f& position);
	virtual bool isAlive() const;

	virtual void handleCollision(Entity* e);
	virtual std::string& getName();

protected:
	virtual float getDirectionToPlanet();
	virtual float getDistanceToPlanet();

protected:
	std::string m_name;

	Level::Level* m_level;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	float theta;
	bool alive;
};

#endif /* ENTITY_H */
