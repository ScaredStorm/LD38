#include "ResourceManager.h"

namespace Core
{
	ResourceManager::ResourceManager()
		: textures("Assets/Textures/", ".png")
		, fonts("Assets/Fonts/", ".ttf")
	{
	}
}