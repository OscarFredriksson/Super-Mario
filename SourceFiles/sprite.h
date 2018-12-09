#ifndef SPRITE_H
#define SPRITE_H

#include "SFML/Graphics.hpp"

class Sprite: public sf::Sprite
{
public:
    Sprite() = default;

    int getTextureSize() const;

    void flip();

private:
    const int textureSize = 16;


};

#endif