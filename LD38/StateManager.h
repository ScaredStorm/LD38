#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <memory>
#include <stack>
#include "IState.h"

namespace sf
{
	class Event;
	class RenderWindow;
}

namespace State
{
	template<class O>
	class StateManager
	{
	public:
		void pop()
		{
			if (m_states.size() > 0)
				m_states.pop();
		}

		template<typename T, typename... Args> void push(O* game, Args&&... args)
		{
			m_states.push(std::make_unique<T>(game, std::forward<Args>(args)...));
		}

		void handleEvents(sf::Event& event)
		{
			m_states.top()->handleEvents(event);
		}

		void update(float delta)
		{
			m_states.top()->update(delta);
		}

		void render(sf::RenderWindow& window)
		{
			m_states.top()->render(window);
		}
	private:
		std::stack<std::unique_ptr<IState>> m_states;
	};
}

#endif /* STATEMANAGER_H */