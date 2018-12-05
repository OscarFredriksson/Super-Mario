#ifndef BRICK_BLOCK_H
#define BRICK_BLOCK_H

#include "block.h"

class Brick_Block: public Block
{
public:
    Brick_Block(const int width = 1, const int height = 1);

    //sf::Sprite getSprite() const override;

private:
    const int xPosInFile = 0;
    const int yPosInFile = 0;

};

#endif