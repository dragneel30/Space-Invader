#include "alien.h"

sf::Sprite& Alien::setSprite()
{
    return _foralien;
}

Alien::~Alien()
{

}

Alien::Alien()
{
    _foralien.setPosition(alien_position_x*30,alien_position_y*30);
    _foralien.setOrigin(_alien.getSize().x/2,_alien.getSize().y/2);
    ++alien_position_x;
    if ( alien_position_x % 17 == 0 ) {
        alien_position_x = 6;
        ++alien_position_y;
    }
}

unsigned int Alien::alien_position_x = 6;
unsigned int Alien::alien_position_y = 2;



void Alien::alien_killer(int index, std::vector<Alien*> alien)
{
    alien.erase(alien.begin()+index);
}


void Alien::goDown(std::vector<Alien*>& alien,int& c,bool& check)
{
    static int ctr = alien.size() - 1;
    alien[ctr]->setSprite().move(0,1);
    --ctr;
    if ( ctr == -1 ) {
        ctr = alien.size() - 1;
        ++c;
        check = false;
        return;
    }
}


void Alien::movement(std::vector<Alien*>& alien, bool isLeft,bool& check,float window_sizeX)
{
    static int ctr = alien.size() - 1;


    std::vector<Alien*>::iterator iter;
    for ( iter = alien.begin(); iter != alien.end(); iter++ )
        if ( (*iter)->setSprite().getPosition().x == window_sizeX - 24 || (*iter) -> setSprite().getPosition().x == 0 )
        {
            if ( ctr == -1 ) {
                check = true;
            }
        }

    if ( ctr == -1 ) {
        ctr = alien.size() - 1;
        return;
    }
    if ( isLeft )
        alien[ctr]->setSprite().move(-6,0);
    else
        alien[ctr]->setSprite().move(6,0);
    --ctr;
}


sf::Texture& Alien::setTexture()
{
    return _alien;
}


