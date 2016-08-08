#ifndef WEIRDALIEN_H
#define WEIRDALIEN_H

#include "alien.h"

class WeirdAlien : public Alien
{
    public:
        sf::Texture& loadAlien();
        WeirdAlien();
    private:
};

#endif // WEIRDALIEN_H
