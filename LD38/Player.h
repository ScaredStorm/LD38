#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "IDamageable.h"

#include "Planet.h"

namespace Level
{
	class Level;
}

class Player : public Entity, public IDamageable<int>
{
public:
	Player(Level::Level* level, Level::Planet* p, const sf::Texture& texture);
	~Player();

	void handleEvents(sf::Event& event) override;
	void update(float delta) override;
	void render(sf::RenderWindow& window) override;

	const sf::Vector2f& getPosition() override;
	void setPosition(const sf::Vector2f& position) override;

private:
	void handleInput(float delta);
	void handleGravity(float delta);
	
	float getDirectionToPlanet();
	float getDistanceToPlanet();
	float getHeightFromPlanet();
	void rotate();

private:
	Level::Planet* m_planet;
	Level::Level* m_level;

	float m_movementSpeed;
	float m_jumpHeight;
	float m_gravitySpeed;
	bool m_grounded;

	float theta; // theta = position around the planet
	float height; // height = distance from the planet surface (excluding the radius of the planet)
	float velocity;
};

#endif /* PLAYER_H */
