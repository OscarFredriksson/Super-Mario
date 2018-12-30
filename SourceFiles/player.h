#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "animated_sprite.h"


class Player: public Character
{
public:
    Player(World& world);

    void jump();

    void endJump();

    void move(Direction dir) override;

    void endWalk();

    void updatePosition() override;
    
    void draw(sf::RenderWindow& window) override;

    sf::Sprite getSprite() const;

    ~Player() override
    {
    };
     
private:
    void setDirection(Direction dir);

    
    //-----Variabler och konstanter------------

    AnimatedSprite sprite;

    std::string jumpSound_path = "Sounds/jump.wav";
    Sound jumpSound;

    static const int height = 2;
    static const int width = 1;

    const float jumpSpeed = -.25f;
    const float moveSpeed = .01f;
    const float maxSpeed = .15f;
    const float stopSpeed = 0.95f;  //I procent
    
    bool animateJump = false;

    bool horisontalButtonHeld = false;

    bool jumpKeyReleased = true;
};

#endif