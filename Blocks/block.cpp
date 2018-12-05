#include "block.h"

Block::Block(const int xPosInFile, const int yPosInFile, const int width, const int height)
{
    texture.loadFromFile(filename, sf::IntRect(textureSize * xPosInFile, textureSize * yPosInFile, textureSize, textureSize));
    block.setTextureRect(sf::IntRect(0, 0, textureSize * width, textureSize * height));



    texture.setRepeated(true);
    texture.setSmooth(true);
    block.setTexture(texture);

    block.setScale(sf::Vector2f(scale, scale));
    
    
}

sf::Sprite Block::getSprite() const
{
    return block;
}