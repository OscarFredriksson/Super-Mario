#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/graphics.hpp>
#include "game.h"
#include "world.h"
#include <iostream>

class Player: public Game, public World
{
public:
    Player();

    sf::Sprite getSprite() const
    {
        return body;
    }

    void jump();

    void moveLeft();

    void moveRight();

        void updatePosition();

    
    void setPosition(float x, float y);

    

    float draw(sf::RenderWindow& window)
    {
        window.draw(body);
    }
     
private:

    float positionX = 3.f;
    float positionY = 2.f;
    float nextX, nextY;

    int height = 2;
    int width = 1;

    bool atGround = false;

    const float jumpSpeed = .05f;
    const float moveSpeed = .1f;
    const float stopSpeed = 0.8f;  //I procent

    float velocityY = 0;
    float velocityX = 0;


    sf::Texture texture;
    sf::Sprite body;

    void checkForGround();

    void checkForWall();

    void setVelocity();

    int left() const
    {
        std::cout << positionX << std::endl;
        return positionX;
    }
    int right() const
    {
        return positionX + width;
    }
    int top() const
    {
        return positionY;
    }
    int bottom() const
    {
        float toTest = positionY + height;

        if(toTest == (int)toTest)   return toTest - 1;
        else                        return toTest;
    }
};

#endif