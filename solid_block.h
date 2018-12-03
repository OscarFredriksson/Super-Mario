#ifndef SOLID_BLOCK_H
#define SOLID_BLOCK_H

#include <SFML/Graphics.hpp>
#include "world.h"

class Solid_Block 
{
public:
    Solid_Block(const int x, const int y, const int width, const int height);

    sf::RectangleShape getSprite() const;

private:
    const int blockSize = 50;

    sf::RectangleShape block;
};

#endif