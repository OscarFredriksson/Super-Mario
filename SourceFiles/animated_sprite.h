#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "sprite.h"
#include <chrono>

class AnimatedSprite: public Sprite
{
public:
    AnimatedSprite();

    void set(const int texture)
    {
        currentTexture = texture;
        setTextureRect(sf::IntRect(texture * getTextureSize(), 0, 16, 32));
    }

    void update(const int startTexture, const int endTexture);

private:
    using clock = std::chrono::high_resolution_clock;
    clock::time_point lastframe;
    static constexpr double speed = 0.075;

   int currentTexture = 0;


    bool stopped = true;

    void animate(const int targetFrame);

    void stop(const float velocity);

    


};

#endif