#ifndef SOLID_BLOCK_H
#define SOLID_BLOCK_H

#include <SFML/Graphics.hpp>

class Solid_Block 
{
public:
    Solid_Block() = default;

    //Solid_Block(const int x, const int y, const int width, const int height);

    virtual sf::Sprite getSprite() const = 0;

    float getBlockScale() const;

private:
    const float scale = 0.1f;

};

#endif