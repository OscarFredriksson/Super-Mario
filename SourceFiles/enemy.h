#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "animated_sprite.h"

class Enemy: public Character
{
public:

    Enemy(World& world);

    void updatePosition() override;

    void draw(sf::RenderWindow& window) override;


private:
    static const int height = 1;
    static const int width = 1;

    const float moveSpeed = .05f;

    AnimatedSprite sprite;

    void flip();

};

#endif