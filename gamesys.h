#ifndef GAMESYS_H
#define GAMESYS_H

#include <SFML/Graphics.hpp>
#include "weirdalien.h"
#include "nextalien.h"
#include "shitalien.h"
#include <vector>
#include "cannon.h"
#include "spaceship.h"
class GameSys
{
    public:
        GameSys();
        void start();

    private:
        void event_handler();
        void update(sf::Time&);
        void renderer();

        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Image _image;


        sf::Texture _background;
        sf::Sprite _forbackground;

        sf::RenderWindow game_window;
        std::vector<Alien*>alien;
        Cannon player;

        int alien_killer;
        Spaceship spaceship;
        sf::Clock spClock;

};
bool collision(Bullet&,std::vector<Alien*>&,int &);

#endif // GAMESYS_H
