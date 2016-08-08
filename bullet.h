#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet
{
    public:
        Bullet(const sf::Texture&,const sf::Sprite&);
        void movement();
        void drawBullet(sf::RenderWindow&);
        sf::Sprite& setSprite();
    private:
        sf::Texture _bullet;
        sf::Sprite _forbullet;
};

#endif // BULLET_H
