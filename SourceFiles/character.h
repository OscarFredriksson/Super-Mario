#ifndef CHARACTER_H
#define CHARACTER_H

#include "world.h"
#include "animated_sprite.h"
#include "sound.h"
#include <string>


class Character
{
public:
    Character(const std::shared_ptr<World>& world, const int width, const int height);

    void setJumpSpeed(const float value);

    void setMoveSpeed(const float value);

    void setMaxSpeed(const float value);

    void setStopSpeed(const float value);

    void setVerticalVelocity(const float value);
    
    void setHorisontalVelocity(const float value);
    
    float getVerticalVelocity() const;

    float getHorisontalVelocity() const;

    float getPositionX() const;

    float getPositionY() const;

    void setPosition(const float x, const float y);

    virtual sf::Sprite getSprite() const = 0;

    virtual void draw(sf::RenderWindow& window) = 0;

    enum Direction
    {
        Left = -1,
        Right = 1
    };

    virtual void move(Direction dir);

    virtual void jump();

    virtual void updatePosition();

    Direction getDirection() const;
    
    virtual void setDirection(Direction dir);

    bool onGround() const;

    bool isAlive() const;

    float leftBoundary() const;

    float rightBoundary() const;

    float topBoundary() const;

    float bottomBoundary() const;

    void kill();

private:

    void checkForGround();

    void checkForRoof();

    void checkForWall();

    int bufferedRoundoff(float i) const;

    int left() const;

    int right() const;

    int top() const;

    int bottom() const;


    //-----Variabler och konstanter------------
    
    const std::shared_ptr<World> world;

    const int height;
    const int width;

    bool _onGround = false;

    float jumpSpeed = 0;
    float moveSpeed = 0;
    float maxSpeed = 0;
    float stopSpeed = 0.005f;

    float velocityY = 0;
    float velocityX = 0;
    float positionX = 10.f;
    float positionY = 2.f;

    Direction dir = Right;

    bool _isAlive = true;

};

#endif