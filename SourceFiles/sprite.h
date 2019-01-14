#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>


class Sprite: public sf::Sprite
{
public:
    Sprite() = default;

    void flip();

    void setPosition(float x, float y);

    void setTexture(sf::Texture& texture);

    static int getTextureSize();

private:
    static constexpr int textureSize = 16;

    static float convertCoords(const float c);
};

#endif