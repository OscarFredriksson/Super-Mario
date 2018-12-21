#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>


class Sprite: public sf::Sprite
{
public:
    Sprite() = default;

    int getTextureSize() const;

    void flip();

    void setPosition(float x, float y);


private:
    static const int textureSize = 16;

    float convertCoords(const float c) const
    {
        return c*textureSize;
    }
        
};

#endif