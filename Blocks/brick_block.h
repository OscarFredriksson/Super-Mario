#ifndef BRICK_BLOCK_H
#define BRICK_BLOCK_H

#include "block.h"

class Brick_Block: public Block
{
public:
    Brick_Block() = delete;

    Brick_Block(const int x, const int y);

private:
    static const int xPosInFile = 0;
    static const int yPosInFile = 0;
};

#endif