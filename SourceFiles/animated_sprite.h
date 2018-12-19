#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "sprite.h"
#include <chrono>

class AnimatedSprite: public Sprite
{
public:
    AnimatedSprite();

    void update(const float velocity);

    void stop();

    void start();

    bool isStarted() const
    {
        return !stopped;
    };

private:
    using clock = std::chrono::high_resolution_clock;
    clock::time_point lastframe;
    static constexpr double speed = 0.075;

    static const int startTexture = 0;
    static const int endTexture = 2; 

    bool goingRight = true;

    bool stopped = true;

};

#endif