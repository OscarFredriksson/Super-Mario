#include "sprite.h"
#include <iostream>

int Sprite::getTextureSize() const
{
    return textureSize;
}

void Sprite::flip()
{
    if(getScale().x > 0)
    {
        setOrigin({getLocalBounds().width, 0});
        setScale(sf::Vector2f(-1, 1));
    }
    else
    {
        setOrigin({0, 0});
        setScale(sf::Vector2f(1, 1));
    }
}

void Sprite::setPosition(float x, float y)
{
    sf::Sprite::setPosition(convertCoords(x), convertCoords(y));
}

void Sprite::setTexture(sf::Texture _texture)
{
    texture = _texture;
    sf::Sprite::setTexture(texture);
};

float Sprite::convertCoords(const float c) const
{
    return c*textureSize;
}
