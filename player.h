#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/graphics.hpp>
#include "game.h"

class Player: public Game
{
public:
    Player();
    
    sf::RectangleShape getSprite() const;

    void jump();

    void updatePosition();

private:
    const float height = 100.f;
    const float width = 50.f;

    float groundHeight = 400.f;

    float positionX = 400.f;
    float positionY = groundHeight;

    float velocityY = 0;

    

    sf::RectangleShape body;
};

#endif