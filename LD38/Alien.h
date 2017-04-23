#ifndef ALIEN_H
#define ALIEN_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "IDamageable.h"

namespace Level
{
	class Level;
}

class Alien : public Entity, public IDamageable<int>
{
public:
	Alien(Level::Level* level, const sf::Texture& texture);
	~Alien();

	void handleEvents(sf::Event& event) override;
	void update(float delta) override;
	void render(sf::RenderWindow& window) override;

private:
	void handleGravity(float delta);
	void updateAI(float delta);
	void rotate();

private:
	float m_movementSpeed;
	float m_gravitySpeed;
	bool m_grounded;
	float height;
	float velocity;
};

#endif /* ALIEN_H */
