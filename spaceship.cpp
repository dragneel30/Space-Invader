#include "spaceship.h"
#include <iostream>
Spaceship::Spaceship(float window_size)
{
    assert(_spaceship.loadFromFile("Assets//spaceship.png"));
    _forspaceship.setTexture(_spaceship);
    _forspaceship.setPosition(sf::Vector2f(window_size,0));
}
void Spaceship::drawSpaceShip(sf::RenderWindow& w)
{
    w.draw(_forspaceship);
}
void Spaceship::movement()
{
    _forspaceship.move(-1,0);
}
bool Spaceship::isAppearNow(sf::Time& time)
{
    return ( time.asSeconds() >= 25.0f );
}
void Spaceship::resetPosition(float window_size)
{
    _forspaceship.setPosition(sf::Vector2f(window_size,0));
}
bool Spaceship::isDisappearNow()
{
    return ( _forspaceship.getPosition().x == -static_cast<int>(_spaceship.getSize().x) );
}

void Spaceship::draw(sf::RenderWindow& window)
{
    window.draw(_forspaceship);
}

bool Spaceship::isCollide(Bullet& bullet)
{
    return (bullet.setSprite().getGlobalBounds().intersects(_forspaceship.getGlobalBounds()));
}
