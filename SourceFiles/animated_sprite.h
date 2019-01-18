#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "sprite.h"
#include <chrono>

class AnimatedSprite: public Sprite
{
public:
    AnimatedSprite(const int width, const int height, const double speed = 0.1);    //Konstruera en animated sprite med given bredd, höjd och tid per textur

    void update(const int startTexture, const int endTexture);      //Uppdatera animeringen, animera mellan de givna texturerna

    void set(const int texture);    //Sätt en specifik textur direkt utan att animera sig dit

    int getCurrentTexture() const;  //Hämta nuvarande textur

private:
    
    using clock = std::chrono::high_resolution_clock;
    clock::time_point lastframe;

    bool nextTextureRight = true;
    
    const double speed;

    const int width, height;

    int currentTexture = 0;

    void animate(const int targetFrame);
};

#endif