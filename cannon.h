#ifndef CANNON_H
#define CANNON_H


#include <SFML/Graphics.hpp>
#include <cassert>
#include "bullet.h"
#include <vector>
class Cannon
{
    public:
        Cannon(const sf::RenderWindow&);
        sf::Sprite& setSprite();
        void fire();
        std::vector<Bullet>& setBullet();
    private:
        sf::Texture _cannon;
        sf::Sprite _forcannon;
        std::vector<Bullet> bullet;

};

#endif // CANNON_H
