#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <cassert>
#include <SFML/Graphics.hpp>
#include "bullet.h"
class Spaceship
{
    public:
        Spaceship(float);
        void drawSpaceShip(sf::RenderWindow&);
        void movement();
        bool isAppearNow(sf::Time&);
        bool isDisappearNow();
        void resetPosition(float);
        void draw(sf::RenderWindow&);
        bool isCollide(Bullet&);
    private:
        sf::Texture _spaceship;
        sf::Sprite _forspaceship;
};

#endif // SPACESHIP_H
