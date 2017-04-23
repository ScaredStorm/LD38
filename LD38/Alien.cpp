#include "Alien.h"
#include "Level.h"

Alien::Alien(Level::Level * level, const sf::Texture & texture)
	: Entity(level, texture, "alien")
{
	m_maxHealth = 30;
	m_health = 30;

	m_movementSpeed = 25.0f;
	m_gravitySpeed = 40.0f;
	m_grounded = false;

	m_maxDamage = 10;
	m_damageStepSize = 5.0f; // 5 seconds
	m_damageTimer = 0.0f;

	theta = 180;
	height = 80;
}

Alien::~Alien()
{
}

void Alien::handleEvents(sf::Event & event)
{
}

void Alien::update(float delta)
{
	handleGravity(delta);
	updateAI(delta);

	if (m_health <= 0) alive = false;

	/* calculate new positions */
	float newX = m_level->getPlanet()->getPosition().x + cosf(to_radians(theta)) * (m_level->getPlanet()->getRadius() + height);
	float newY = m_level->getPlanet()->getPosition().y + sinf(to_radians(theta)) * (m_level->getPlanet()->getRadius() + height);
	setPosition({ newX, newY });
	rotate();
}

void Alien::render(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

void Alien::handleCollision(Entity* o)
{
	/*
	Because there's only one object colliding with this class (Bullet) I'm going to cast the entity to a bullet.
	I made everything extremely complex for no such reason...
	*/
	if (o->getName() == "bullet")
	{
		Bullet* b = dynamic_cast<Bullet*>(o);
		takeDamage(b->getDamageAmount());
	}
}

void Alien::handleGravity(float delta)
{
	velocity = (m_grounded) ? 0.0f : velocity - (m_gravitySpeed * delta);
	height = std::max(height + velocity, 0.0f);
	m_grounded = (height > 0) ? false : true;
}

void Alien::updateAI(float delta)
{
	House* house = m_level->getHouse();
	if (house != nullptr)
	{
		float direction = sign(house->getTheta() - theta);
		float distance = abs(house->getTheta() - theta);
		if (distance > 5.0f)
		{
			theta += direction * m_movementSpeed * delta;
		}
		else
		{
			dealDamage(delta);
		}
	}
}

void Alien::dealDamage(float delta)
{
	// This function can only be called when the alien is in range
	// So I don't have to check if the house is null.
	if (m_damageTimer < m_damageStepSize)
	{
		m_damageTimer += delta;
	}
	else
	{
		m_level->getHouse()->takeDamage(m_maxDamage);
		m_damageTimer = 0.0f;
	}
}

void Alien::rotate()
{
	float angle = getDirectionToPlanet();
	m_sprite.setRotation(to_degrees(angle) + 90.0f);
}
