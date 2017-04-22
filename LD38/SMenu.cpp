#include "SMenu.h"
#include <iostream>

namespace State {

	SMenu::SMenu(Core::Game* game)
	{
		this->game = game;
	}

	SMenu::~SMenu()
	{
	}

	void SMenu::handleEvents(sf::Event & event)
	{
	}

	void SMenu::update(float delta)
	{
	}

	void SMenu::render(sf::RenderWindow & window)
	{
	}
}