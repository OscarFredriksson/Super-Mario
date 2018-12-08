#ifndef EMPTY_BLOCK_H
#define EMPTY_BLOCK_H

#include "block.h"

class Empty_Block: public Block
{
public:
    Empty_Block() = delete;

    Empty_Block(const int x, const int y);

private:
    static const int xPosInFile = 2;
    static const int yPosInFile = 0;
};

#endif