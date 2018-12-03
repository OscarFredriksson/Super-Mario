#ifndef SOLID_BLOCK_H
#define SOLID_BLOCK_H

#include "block.h"

class Solid_Block: public Block
{
public:
    Solid_Block() = delete;

    Solid_Block(const int x, const int y, const int width, const int height);

    sf::Sprite getSprite() const override;

private:
    sf::Texture texture;
    sf::Sprite block;

    const int positionInFile = 2;

    float convertInput(float const input) const;
};

#endif