#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "sprite.h"
#include <chrono>

class AnimatedSprite: public Sprite
{
public:
    AnimatedSprite(const int width, const int height, const double speed = 0.1);

    void set(const int texture);

    void update(const int startTexture, const int endTexture);

    int getCurrentTexture() const; 

private:
    
    using clock = std::chrono::high_resolution_clock;
    clock::time_point lastframe;

    bool goingRight = true;
    
    const double speed = .1;

    const int width, height;

    int currentTexture = 0;

    void animate(const int targetFrame);
};

#endif