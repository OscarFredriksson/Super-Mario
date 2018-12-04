#ifndef QUESTION_BLOCK_H
#define QUESTION_BLOCK_H

#include "block.h"

class Question_Block: public Block
{
public:
    Question_Block() = delete;

    Question_Block(const int x, const int y, const int width, const int height);

    sf::Sprite getSprite() const override;

private:
    sf::Texture texture;
    sf::Sprite block;

    const int positionInFile = 1;

    float convertInput(float const input) const;
};

#endif