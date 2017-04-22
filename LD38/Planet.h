#ifndef PLANET_H
#define PLANET_H

#include <SFML/Graphics.hpp>

namespace Level
{
	class Planet
	{
	public:
		Planet(const sf::Texture& texture);

		void render(sf::RenderWindow& window);
		
		const sf::Vector2f& getPosition() const;
		void setPosition(const sf::Vector2f& position);
		float getRadius() const;
	private:
		sf::Sprite m_sprite;
		sf::Vector2f m_position;
		float m_radius;
	};
}

#endif /* PLANET_H */
