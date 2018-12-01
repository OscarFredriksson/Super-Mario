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
    const float height = 100.f;
    const float outlinethickness = 2.f;
    const float width = 50.f;

    const float atGroundPos;

    float positionX = 450.f;
    float positionY = 0.f;

    const float moveSpeed = 10.f;
    const float stopSpeed = 0.9f;  //I procent

    float velocityY = 0;
    float velocityX = 0;
    

    sf::RectangleShape body;
};

#endif