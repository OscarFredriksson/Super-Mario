#ifndef CHARACTER_H
#define CHARACTER_H

#include "world.h"
#include "animated_sprite.h"
#include "sound.h"
#include <string>


class Character
{
public:
    Character(World& world, const int width, const int height);

    enum Direction
    {
        Left = -1,
        Right = 1
    };

    virtual void move(Direction dir);

    virtual void updatePosition();
    
    //void setPosition(float x, float y);

    void checkForGround();

    void checkForRoof();

    void checkForWall();

    void setDirection(Direction dir);

    virtual void draw(sf::RenderWindow& window) = 0;

    void setJumpSpeed(const float value)
    {
        jumpSpeed = value;
    }

    void setMoveSpeed(const float value)
    {
        moveSpeed = value;
    }

    void setMaxSpeed(const float value)
    {
        maxSpeed = value;
    }

    void setStopSpeed(const float value)
    {
        stopSpeed = value;
    }

    void setVerticalVelocity(const float value)
    {
        velocityY = value;
    }

    void setHorisontalVelocity(const float value)
    {
        velocityX = value;
    }

    float getVerticalVelocity() const
    {
        return velocityY;
    }

    float getHorisontalVelocity() const
    {
        return velocityX;
    }

    float getPositionX() const
    {
        return positionX;
    }

    float getPositionY() const
    {
        return positionY;
    }

    void setPosition(const float x, const float y)
    {
        positionX = x;
        positionY = y;
    }

    void jump()
    {
        setVerticalVelocity(jumpSpeed);
    }

    bool onGround() const
    {
        return _onGround;
    }

    int bufferedRoundoff(float i) const;

    int left() const;

    int right() const;

    int top() const;

    int bottom() const;

    Direction getDirection() const
    {
        return dir;
    }

private:
    //-----Variabler och konstanter------------
    
    World& world;

    const int height;
    const int width;

    bool _onGround = false;

    float jumpSpeed = 0;
    float moveSpeed = 0;
    float maxSpeed = 0;
    float stopSpeed = 0.95f;  //I procent

    float velocityY = 0;
    float velocityX = 0;
    float positionX = 10.f;
    float positionY = 2.f;

    Direction dir = Right;

};

#endif