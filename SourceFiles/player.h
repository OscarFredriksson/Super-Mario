#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"
#include "world.h"
#include <iostream>
#include <chrono>
#include "sprite.h"

class Player: public Game
{
public:
    //Player();

    Player(World& world);

    sf::Sprite getSprite() const
    {
        return body;
    }
    void jump();

    void endJump();

    void moveLeft();

    void moveRight();

    void updatePosition();
    
    void setPosition(float x, float y);

    void draw(sf::RenderWindow& window)
    {
        window.draw(body);
    }
     
private:
    World& world;

    const float jumpSpeed = -.21f;
    const float moveSpeed = .01f;   //.15f;
    const float maxSpeed = .15f;
    const float stopSpeed = 0.95f;  //I procent

    float positionX = 3.f;
    float positionY = 2.f;

    int height = 2;
    int width = 1;

    enum Direction
    {
        Left,
        Right
    };

    Direction dir = Right;

    bool atGround = false;

    float velocityY = 0;
    float velocityX = 0;

    sf::Texture texture;
    Sprite body;

    std::chrono::high_resolution_clock::time_point landed_time;

    void checkForGround();

    void checkForRoof();

    void checkForWall();

    void setDirection(Direction dir);

    int left() const
    {
        return positionX;
    }
    int right() const
    {
        return bufferedRoundoff(positionX + width);
    }
    int top() const
    {
        return positionY;
    }
    int bottom() const
    {
        return bufferedRoundoff(positionY + height);
    }

    int bufferedRoundoff(float i) const
    {
        //Om det inte finns några decimaler alls, ge samma ruta som vi står på
        if(i == (int)i) return i - 1;   
        else            return i;
    }
};

#endif