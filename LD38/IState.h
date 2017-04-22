#ifndef ISTATE_H
#define ISTATE_H

namespace sf
{
	class Event;
	class RenderWindow;
}
namespace Core
{
	class Game;
}

namespace State
{
	class IState
	{
	public:
		virtual void handleEvents(sf::Event& event) = 0;
		virtual void update(float delta) = 0;
		virtual void render(sf::RenderWindow& window) = 0;

	protected:
		Core::Game* game;
	};
}

#endif /* ISTATE_H */