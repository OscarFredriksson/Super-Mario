#ifndef QUESTION_BLOCK_H
#define QUESTION_BLOCK_H

#include "block.h"

class Question_Block: public Block
{
public:
    Question_Block() = delete;

    Question_Block(const int x, const int y);

private:
    static const int xPosInFile = 1;
    static const int yPosInFile = 0;
};

#endif