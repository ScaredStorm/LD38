#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include "ResourceController.h"

namespace Core
{
	class ResourceManager
	{
	public:
		ResourceManager();

		ResourceController<sf::Texture> textures;
		ResourceController<sf::Font> fonts;
	};
}
#endif /* RESOURCEMANAGER_H */
