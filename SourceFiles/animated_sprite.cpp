#include "animated_sprite.h"
#include <iostream>

AnimatedSprite::AnimatedSprite()
{
    setTextureRect(sf::IntRect(0, 0, 16, 32));
}

void AnimatedSprite::update(const float velocity)
{
    if(stopped) return;

    auto now = clock::now();

    std::chrono::duration<double> duration = now - lastframe;
    if(duration.count() > speed)
    {
         int x = getTextureRect().left + getTextureSize();

        if(x ==  (3 * getTextureSize()) || x == getTextureSize())
            goingRight = !goingRight;

        if(x == (3 * getTextureSize()))   x = getTextureSize();
        if(x == (2 * getTextureSize()) && !goingRight)
            x = 0;

        setTextureRect(sf::IntRect(x, 0, 16, 32));
        
        lastframe = clock::now();
    }
}   

void AnimatedSprite::stop()
{
    stopped = true;
    setTextureRect(sf::IntRect(0, 0, 16, 32));
}

void AnimatedSprite::start()
{
    stopped = false;
    lastframe = clock::now();
}