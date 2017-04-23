#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"
class Bullet : public Entity
{
public:
	Bullet(Level::Level* level, const sf::Texture& texture, const int& direction);
	~Bullet();

	void handleEvents(sf::Event& event) override;
	void update(float delta) override;
	void render(sf::RenderWindow& window) override;

private:
	void rotate();

private:
	int m_direction;
	float m_damage;
	float m_movementSpeed;
	float height;

	float m_maxLifetime;
	float m_secondsAlive;
};

#endif /* BULLET_H */
