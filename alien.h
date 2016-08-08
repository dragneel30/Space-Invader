#ifndef ALIEN_H
#define ALIEN_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


class Alien
{
    public:
        Alien();
        virtual ~Alien();
        virtual sf::Texture& loadAlien() = 0;
        sf::Sprite& setSprite();
        sf::Texture& setTexture();

        static void goDown(std::vector<Alien*>&,int &,bool&);
        static void movement(std::vector<Alien*>&,bool,bool&,float);

    protected:
        sf::Texture _alien;
        sf::Sprite _foralien;

        static unsigned int alien_position_x;
        static unsigned int alien_position_y;
        static void alien_killer(int,std::vector<Alien*>);

};

#endif // ALIEN_H
