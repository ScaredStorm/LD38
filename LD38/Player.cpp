#include "Player.h"
#include "Level.h"
#include <cmath>

Player::Player(Level::Level* level, const sf::Texture& texture)
	: Entity(level, texture)
{
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
	float newX = m_level->getPlanet()->getPosition().x + cosf(to_radians(theta)) * (m_level->getPlanet()->getRadius() + height);
	float newY = m_level->getPlanet()->getPosition().y + sinf(to_radians(theta)) * (m_level->getPlanet()->getRadius() + height);
	setPosition({ newX, newY });
	rotate();
}

void Player::render(sf::RenderWindow& window)
{
	window.draw(m_sprite);
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

float Player::getHeightFromPlanet()
{
	float distance = getDistanceToPlanet();
	return distance - m_level->getPlanet()->getRadius();
}

void Player::rotate()
{
	float angle = getDirectionToPlanet();
	m_sprite.setRotation(to_degrees(angle) + 90.0f);
}