#include "block.h"
#include <iostream>

Block::Block(const int x, const int y, const int xPosInFile, const int yPosInFile, const int width, const int height)
{
    texture.loadFromFile(filename, sf::IntRect(textureSize * xPosInFile, textureSize * yPosInFile, textureSize, textureSize));

    texture.setRepeated(true);
    texture.setSmooth(true);
    block.setTexture(texture);
    block.setTextureRect(sf::IntRect(0, 0, textureSize * width, textureSize * height));

    block.setPosition(convertCoords(x), convertCoords(y));
}

sf::Sprite Block::getSprite() const
{
    return block;
}