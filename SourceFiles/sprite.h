#ifndef SPRITE_H
#define SPRITE_H

#include "SFML/Graphics.hpp"

class Sprite: public sf::Sprite
{
public:
    Sprite() = default;

    Sprite(sf::Texture& texture);

    int getTextureSize() const
    {
        return textureSize;
    }

private:
        const int textureSize = 64;


};

#endif