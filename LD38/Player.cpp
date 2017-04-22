#include "Player.h"

Player::Player(const sf::Texture& texture)
	: Entity(texture)
{
	m_maxHealth = 100;
	m_health = m_maxHealth;
}

Player::~Player()
{
}

void Player::handleEvents(sf::Event& event)
{

}

void Player::update(float delta)
{

}
