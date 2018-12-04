#ifndef EMPTY_BLOCK_H
#define EMPTY_BLOCK_H

#include "block.h"

class Empty_Block: public Block
{
public:
    Empty_Block() = delete;

    Empty_Block(const int x, const int y, const int width, const int height);

    sf::Sprite getSprite() const override;

private:
    sf::Texture texture;
    sf::Sprite block;

    const int positionInFile = 2;

    float convertInput(float const input) const;
};

#endif