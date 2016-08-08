#include "weirdalien.h"

sf::Texture& WeirdAlien::loadAlien()
{
    if ( !_alien.loadFromFile("Assets//weirdalien.png") )
        std::cout << "Error: Could not load the file\n";
    return _alien;
}

WeirdAlien::WeirdAlien()
{
    _foralien.setTexture(loadAlien());
}

