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

    void stomp()
    {
        setVerticalVelocity(jumpSpeed/2);
        stompSound.play();
    }
     
private:
    void setDirection(Direction dir);

    
    //-----Variabler och konstanter------------

    AnimatedSprite sprite;

    std::string jumpSound_path = "Sounds/jump.wav";
    Sound jumpSound;

    std::string stompSound_path = "Sounds/stomp.wav";
    Sound stompSound;

    static const int height = 2;
    static const int width = 1;

    const float jumpSpeed = -.25f;
    const float moveSpeed = .01f;
    const float maxSpeed = .15f;
    
    bool animateJump = false;

    bool horisontalButtonHeld = false;

    bool jumpKeyReleased = true;
};

#endif