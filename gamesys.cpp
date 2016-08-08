#include "bullet.h"
#include "gamesys.h"
#include <cstdlib>
#include <ctime>
bool collision(Bullet& bullet,std::vector<Alien*>& alien,int& ak)
{
    std::vector<Alien*>::iterator iter;
    for ( iter = alien.begin(); iter != alien.end(); ++iter )
    {
        if ( (*iter)->setSprite().getGlobalBounds().intersects(bullet.setSprite().getGlobalBounds()))
        {
            ak = iter - alien.begin();
            return true;
        }
    }
    return false;
}
GameSys::GameSys()
    :game_window(sf::VideoMode(522,522),"Space Invaders", sf::Style::Default), player(game_window),alien_killer(0), spaceship(game_window.getSize().x)
{
    game_window.setFramerateLimit(60);
    alien.push_back(new WeirdAlien);
    alien.push_back(new WeirdAlien);
    alien.push_back(new WeirdAlien);
    alien.push_back(new WeirdAlien);
    alien.push_back(new WeirdAlien);
    alien.push_back(new WeirdAlien);
    alien.push_back(new WeirdAlien);
    alien.push_back(new WeirdAlien);
    alien.push_back(new WeirdAlien);
    alien.push_back(new WeirdAlien);
    alien.push_back(new WeirdAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new NextAlien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien);
    alien.push_back(new Shitalien); ///could have done with loop

    _image.create(1,1,sf::Color::Green);
    assert(_texture.loadFromImage(_image));
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(sf::IntRect(0,0,game_window.getSize().x,1));
    _sprite.setPosition(sf::Vector2f(0,game_window.getSize().y-10));

    _background.loadFromFile("background.png");
    _forbackground.setTexture(_background);
}

void GameSys::event_handler()
{
    sf::Event event;
    while ( game_window.pollEvent(event) )
    {
        if ( event.type == sf::Event::Closed )
            game_window.close();
       if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
            player.setSprite().move(-3,0);
       else if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
            player.setSprite().move(3,0);

       if ( player.setBullet().size() == 0 )
        {
            if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up ) )
            {
                player.fire();
            }
        }
    }
}

void GameSys::update(sf::Time& spTime)
{
    if ( spaceship.isAppearNow(spTime) )
    {
        spaceship.movement();
        if ( spaceship.isDisappearNow() )
        {
            spaceship.resetPosition(game_window.getSize().x);
            spClock.restart();
        }
        if ( player.setBullet().size() != 0 )
        {
            if ( spaceship.isCollide(player.setBullet()[0]) )
            {
                spaceship.resetPosition(game_window.getSize().x);
                player.setBullet().erase(player.setBullet().begin());
                spClock.restart();
            }
        }
    }
    if ( player.setBullet().size() != 0 )
    {
        player.setBullet()[0].movement();
        if ( collision(player.setBullet()[0],alien,alien_killer) )
        {
            alien.erase(alien.begin()+alien_killer);
            player.setBullet().erase(player.setBullet().begin());
        }
        else if ( player.setBullet()[0].setSprite().getPosition().y < 0 )
            player.setBullet().erase(player.setBullet().begin());
    }
///////////move alien
        static bool check = false;
        static int n = 2;

        if ( !check )
            Alien::movement(alien,n%2,check,game_window.getSize().x);
        else
            Alien::goDown(alien,n,check);


    return;
}

void GameSys::renderer()
{
    game_window.clear(sf::Color::Blue);
    spaceship.draw(game_window);
   // game_window.draw(_forbackground);
    game_window.draw(player.setSprite());
    if ( player.setBullet().size() != 0 ) {
        player.setBullet()[0].drawBullet(game_window);
    }
    for ( int a = 0; a < alien.size(); a++ )
            game_window.draw(alien[a]->setSprite());
  //  game_window.draw(_sprite);
    game_window.display();
    return;
}

void GameSys::start()
{

    while ( game_window.isOpen() ) {
        event_handler();
        sf::Time spTime = spClock.getElapsedTime();
        update(spTime);
        renderer();
    }
    return;
}






























































