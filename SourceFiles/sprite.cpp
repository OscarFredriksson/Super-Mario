#include "sprite.h"
#include <iostream>

Sprite::Sprite(sf::Texture& texture)
{
    //texture.setRepeated(true);
    texture.setSmooth(true);
    setTexture(texture);
    setTextureRect(sf::IntRect(0, 0, textureSize, textureSize));
}