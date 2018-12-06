#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/graphics.hpp>
#include "game.h"
#include "world.h"

class Player: public Game, public World
{
public:
    Player();

    sf::Sprite getSprite() const
    {
        return body;
    }

    void jump();

    void updatePosition();

    void checkFall();

    float left() const
    {
        return positionX;
    }
    float right() const
    {
        return positionX + width;
    }
    float top() const
    {
        return positionY;
    }
    float bottom() const
    {
        return positionY + height;
    }

    float draw(sf::RenderWindow& window)
    {
        window.draw(body);
    }
     
private:

    float positionX = 2.f;
    float positionY = 2.f;

    int height = 2;
    int width = 1;

    bool atGround = false;

    const float moveSpeed = 7.f;
    const float stopSpeed = 0.8f;  //I procent

    float velocityY = 0;
    float velocityX = 0;


    sf::Texture texture;
    sf::Sprite body;

    void setVelocity();
};

#endif