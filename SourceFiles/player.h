#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "animated_sprite.h"
#include "resource_holder.h"


class Player: public Character
{
public:
    Player(const std::shared_ptr<World>& world);

    void jump() override;

    void endJump();

    void move(Direction dir) override;

    void endWalk();

    void updatePosition() override;
    
    void draw(sf::RenderWindow& window) override;

    sf::Sprite getSprite() const override;

    void stomp();
     
private:
    void setDirection(Direction dir) override;

    
    //-----Variabler och konstanter------------
    const std::string texture_path = "Textures/Mario.png";
    Resource_Holder<sf::Texture, std::string> textures;

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
    const float stopSpeed = 0.005f;
    
    bool animateJump = false;

    bool horisontalButtonHeld = false;

    bool jumpKeyReleased = true;
};

#endif