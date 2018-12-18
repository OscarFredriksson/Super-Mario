#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "sprite.h"
#include <chrono>

class AnimatedSprite: public Sprite
{
public:
    AnimatedSprite() = default;

    void update() const;

    void setTexture(const sf::Texture& texture);



private:
    sf::Texture texture;


    using clock = std::chrono::high_resolution_clock;
    clock::time_point start = clock::now();
    static constexpr double speed = 1.0;

    static const int startTexture = 0;
    static const int endTexture = 2; 

};

#endif