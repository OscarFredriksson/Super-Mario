#include "ground_block.h"
#include <iostream>
#include "../world.h"

Ground_Block::Ground_Block(const int x, const int y, const int width, const int height):
    Block()
{
    texture.loadFromFile(getFilename(), sf::IntRect(getTextureSize() * positionInFile, 0, getTextureSize(), getTextureSize()));
    texture.setRepeated(true);
    block.setTexture(texture);

    block.setScale(sf::Vector2f(getBlockScale(), getBlockScale()));
    
    block.setPosition(sf::Vector2f(convertInput(x), World::getHeight() - convertInput(y)));
    
    block.setTextureRect(sf::IntRect(0, 0, getTextureSize() * width, getTextureSize() * height));
} 

sf::Sprite Ground_Block::getSprite() const
{
    return block;
}

float Ground_Block::convertInput(const float input) const
{
    return (float)(input * getBlockScale() * texture.getSize().x);
}