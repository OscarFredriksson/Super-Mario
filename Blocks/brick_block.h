#ifndef BRICK_BLOCK_H
#define BRICK_BLOCK_H

#include "block.h"

class Brick_Block: public Block
{
public:
    Brick_Block() = delete;

    Brick_Block(const int x, const int y, const int width, const int height);

    sf::Sprite getSprite() const override;

private:
    sf::Texture texture;
    sf::Sprite block;

    const int positionInFile = 0;

    float convertInput(float const input) const;
};

#endif