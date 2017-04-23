#ifndef HOUSE_H
#define HOUSE_H

#include "Entity.h"
#include "IDamageable.h"

namespace Level
{
	class Level;
}

class House : public Entity, public IDamageable<>
{
public:
	House(Level::Level* level, const sf::Texture& texture);
	~House();

	void handleEvents(sf::Event& event) override;
	void update(float delta) override;
	void render(sf::RenderWindow& window) override;
	void calculatePosition();
};

#endif /* HOUSE_H */
