#ifndef GROUND_BLOCK_H
#define GROUND_BLOCK_H

#include "block.h"

class Ground_Block: public Block
{
public:
    Ground_Block() = delete;

    Ground_Block(const int x, const int y);

private:
    static const int xPosInFile = 3;
    static const int yPosInFile = 0;
};

#endif