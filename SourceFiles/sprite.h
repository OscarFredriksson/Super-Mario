#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>


class Sprite: public sf::Sprite
{
public:
    Sprite() = default;

    void flip();

    void setPosition(float x, float y);

    void setTexture(sf::Texture _texture);

    static int getTextureSize();

protected:
    sf::Texture texture;    //Behöver nås av grundklassen sf::Sprite

private:
    sf::Sprite sprite;

    static constexpr int textureSize = 16;

    static float convertCoords(const float c);
};

#endif