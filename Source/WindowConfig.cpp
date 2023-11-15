#include <SFML/Graphics.hpp>
#include "../Header/WindowConfig.h"

void WindowConfig::setDefault(sf::RenderWindow &window)
{
    window.setFramerateLimit(60);

};