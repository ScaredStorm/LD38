#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "IDamageable.h"

class Player : public Entity, public IDamageable<int>
{
public:
	Player(const sf::Texture& texture);
	~Player();

	void handleEvents(sf::Event& event) override;
	void update(float delta) override;
};

#endif /* PLAYER_H */
