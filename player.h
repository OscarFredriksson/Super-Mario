#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/graphics.hpp>
#include "game.h"
#include "world.h"
#include <iostream>
#include <chrono>

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
    const float jumpSpeed = .25f;
    const float moveSpeed = .15f;
    const float stopSpeed = 0.9f;  //I procent

    float positionX = 3.f;
    float positionY = 2.f;

    int height = 2;
    int width = 1;

    bool atGround = false;

    float velocityY = 0;
    float velocityX = 0;

    sf::Texture texture;
    sf::Sprite body;

    std::chrono::high_resolution_clock::time_point landed_time;

    void checkForGround();

    void checkForRoof();

    void checkForWall();

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