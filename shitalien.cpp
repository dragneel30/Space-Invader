#include "shitalien.h"

sf::Texture& Shitalien::loadAlien()
{
    if (!_alien.loadFromFile("Assets//shitalien.png") )
        std::cout << "Error: could not load the file\n";
    return _alien;
}

Shitalien::Shitalien()
{
    _foralien.setTexture(loadAlien());
}
