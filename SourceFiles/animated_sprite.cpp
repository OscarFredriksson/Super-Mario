#include "animated_sprite.h"
#include <iostream>

AnimatedSprite::AnimatedSprite()
{
    setTextureRect(sf::IntRect(0, 0, 16, 32));
}

void AnimatedSprite::set(const int texture)
{
    currentTexture = texture;
    setTextureRect(sf::IntRect(texture * getTextureSize(), 0, 16, 32));
}

void AnimatedSprite::update(const int startTexture, const int endTexture)
{   
    static bool goingRight = true;

    if(currentTexture == endTexture || currentTexture == 0)
        goingRight = !goingRight;

    if(currentTexture <= endTexture && goingRight)
        animate(endTexture);
    else                               
        animate(startTexture);  
}   

int AnimatedSprite::getCurrentTexture() const
{
    return currentTexture;
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