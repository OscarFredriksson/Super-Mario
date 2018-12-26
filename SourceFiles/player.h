#ifndef PLAYER_H
#define PLAYER_H

#include "world.h"
#include <iostream>
#include "animated_sprite.h"
#include "sound.h"
#include <string>


class Player
{
public:
    Player(World& world);

    void jump();

    void endJump();

    enum Direction
    {
        Left = -1,
        Right = 1
    };

    void move(Direction dir);

    void endWalk();

    void updatePosition();
    
    void setPosition(float x, float y);

    void draw(sf::RenderWindow& window);

    sf::Sprite getSprite() const;
     
private:
    int bufferedRoundoff(float i) const;

    int left() const;

    int right() const;

    int top() const;

    int bottom() const;

    void checkForGround();

    void checkForRoof();

    void checkForWall();

    void setDirection(Direction dir);

    
    //-----Variabler och konstanter------------
    
    World& world;

    sf::Texture texture;
    AnimatedSprite sprite;
    int height = 2;
    int width = 1;

    std::string jumpSound_path = "Sounds/jump.wav";
    Sound jumpSound;

    Direction dir = Right;

    const float jumpSpeed = -.25f;
    const float moveSpeed = .01f;
    const float maxSpeed = .15f;
    const float stopSpeed = 0.95f;  //I procent

    float positionX = 10.f;
    float positionY = 2.f;
    float velocityY = 0;
    float velocityX = 0;


    bool atGround = false;
    
    bool animateJump = false;

    bool horisontalButtonHeld = false;

    bool jumpKeyReleased = true;
};

#endif