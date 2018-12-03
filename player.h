#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/graphics.hpp>
#include "world.h"

class Player: public World
{
public:
    Player();
    
    sf::RectangleShape getSprite() const;

    void jump();

    void moveLeft();

    void moveRight();

    void updatePosition();

    float getHeight() const;

    float getWidth() const;
     
private:

    float positionX = 200.f;
    float positionY = 0.f;

    const float height = 100.f;
    const float width = 50.f;

    bool atGround = false;

    const float moveSpeed = 7.f;
    const float stopSpeed = 0.8f;  //I procent

    float velocityY = 0;
    float velocityX = 0;
    

    sf::RectangleShape body;

    void handleJump();

    void validHorisontalMove();
};

#endif