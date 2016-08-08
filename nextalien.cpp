#include "nextalien.h"


sf::Texture& NextAlien::loadAlien()
{
    if ( !_alien.loadFromFile("Assets//nextalien.png") )
        std::cout << "Error: Could not load the file\n";
    return _alien;
}
NextAlien::NextAlien()
{
    _foralien.setTexture(loadAlien());
}
