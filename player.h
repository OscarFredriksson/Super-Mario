#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/graphics.hpp>
#include "world.h"
#include <chrono>

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

    float positionX = 100.f;
    float positionY = 400.f;

    const float height = 50.f;
    const float width = 25.f;

    bool atGround = false;

    const float moveSpeed = 7.f;
    const float stopSpeed = 0.8f;  //I procent

    float velocityY = 0;
    float velocityX = 0;
    
    std::chrono::high_resolution_clock::time_point landed_time;

    sf::RectangleShape body;

    void setVelocity();

    void handleJump();

    void handleHorisontalMove();
};

#endif