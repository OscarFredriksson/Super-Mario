#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "sprite.h"
#include <chrono>

class AnimatedSprite: public Sprite
{
public:
    AnimatedSprite();

    void set(const int texture);

    void update(const int startTexture, const int endTexture);

    int getCurrentTexture() const; 

private:
    
    using clock = std::chrono::high_resolution_clock;
    clock::time_point lastframe;
    
    static constexpr double speed = .1;

    int currentTexture = 0;

    void animate(const int targetFrame);
};

#endif