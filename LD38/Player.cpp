#include "Player.h"
#include "Level.h"
#include <cmath>
#include <iostream>
#include "Maths.h"

Player::Player(Level::Level* level, Level::Planet* p, const sf::Texture& texture)
{
	m_planet = p;
	m_level = level;

	m_sprite.setTexture(texture);
	m_sprite.setOrigin(sf::Vector2f{ m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height - 6 });
	m_maxHealth = 100;
	m_health = m_maxHealth;
	m_movementSpeed = 25.0f;
	m_jumpHeight = 10.0f;
	m_gravitySpeed = 40.0f;
	m_grounded = true;

	theta = 270.0f;
	height = 0.0f;
	velocity = 0.0f;
}

Player::~Player()
{
}

void Player::handleEvents(sf::Event& event)
{
}

void Player::update(float delta)
{
	handleInput(delta);
	handleGravity(delta);

	/* calculate new positions */
	float newX = m_planet->getPosition().x + cosf(to_radians(theta)) * (m_planet->getRadius() + height);
	float newY = m_planet->getPosition().y + sinf(to_radians(theta)) * (m_planet->getRadius() + height);
	setPosition({ newX, newY });
	rotate();
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

const sf::Vector2f& Player::getPosition()
{
	return m_position;
}

void Player::setPosition(const sf::Vector2f& position)
{
	m_position = position;
	m_sprite.setPosition(position);
}

void Player::handleInput(float delta)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		theta -= m_movementSpeed * delta;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		theta += m_movementSpeed * delta;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && m_grounded)
	{
		velocity = m_jumpHeight;
		m_grounded = false;
	}
}

void Player::handleGravity(float delta)
{
	velocity = (m_grounded) ? 0.0f : velocity - (m_gravitySpeed * delta);
	height = std::max(height + velocity, 0.0f);
	m_grounded = (height > 0) ? false : true;
}

float Player::getDirectionToPlanet()
{
	float dx = m_position.x - m_planet->getPosition().x;
	float dy = m_position.y - m_planet->getPosition().y;
	return atan2f(dy, dx);
}

float Player::getDistanceToPlanet()
{
	float dx = m_position.x - m_planet->getPosition().x;
	float dy = m_position.y - m_planet->getPosition().y;
	return sqrtf(dx*dx + dy*dy);
}

float Player::getHeightFromPlanet()
{
	float distance = getDistanceToPlanet();
	return distance - m_planet->getRadius();
}

void Player::rotate()
{
	float angle = getDirectionToPlanet();
	m_sprite.setRotation(to_degrees(angle) + 90.0f);
}