#include <SFML\Graphics.hpp>
#include <iostream>

int main(int argc, const char* argv[])
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "LD38", sf::Style::Default);
	sf::CircleShape shape(100.0f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition({ static_cast<float>(window.getSize().x / 2.0f) - 100.0f, static_cast<float>(window.getSize().y / 2.0f) - 100.0f });

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}