#include "bullet.h"
#include <cassert>
#include <iostream>
Bullet::Bullet(const sf::Texture& cannon,const sf::Sprite& forcannon)
{
    assert(_bullet.loadFromFile("Assets//bullet.png"));
    _forbullet.setTexture(_bullet);
    _forbullet.setPosition(sf::Vector2f(forcannon.getPosition().x+(cannon.getSize().x/2),forcannon.getPosition().y-_bullet.getSize().y));
}

void Bullet::movement()
{
    _forbullet.move(0,-3.0f);
}

void Bullet::drawBullet(sf::RenderWindow& w)
{
    w.draw(_forbullet);
}

sf::Sprite& Bullet::setSprite()
{
    return _forbullet;
}
