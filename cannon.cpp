#include "cannon.h"

Cannon::Cannon(const sf::RenderWindow& window)
    :bullet()
{
    assert(_cannon.loadFromFile("Assets//cannon.png"));
    _forcannon.setTexture(_cannon);
    _forcannon.setPosition(sf::Vector2f(0,window.getSize().y-(_cannon.getSize().y*4)));
}

sf::Sprite& Cannon::setSprite()
{
    return _forcannon;
}


void Cannon::fire()
{
    bullet.push_back(Bullet(_cannon,_forcannon));
}


std::vector<Bullet>& Cannon::setBullet()
{
    return bullet;
}
