#include "animated_sprite.h"
#include <iostream>

AnimatedSprite::AnimatedSprite()
{
    setTextureRect(sf::IntRect(0, 0, 16, 32));
}

void AnimatedSprite::update(const int startTexture, const int endTexture)
{   
    if(currentTexture < endTexture)    
        animate(endTexture);
    else                                    
        animate(startTexture);  
}   

void AnimatedSprite::animate(const int targetTexture)
{
    if(targetTexture == currentTexture) return;

    auto now = clock::now();

    std::chrono::duration<double> duration = now - lastframe;
    if(duration.count() > speed)
    {
        int x;
        if(currentTexture < targetTexture)  x = getTextureRect().left + getTextureSize();
        else                                x = getTextureRect().left - getTextureSize();
   
        setTextureRect(sf::IntRect(x, 0, 16, 32));
        currentTexture = x/getTextureSize();

        lastframe = clock::now();
    }
}