#include "wood_block.h"
#include <iostream>
#include "world.h"

Wood_Block::Wood_Block(const int x, const int y, const int width, const int height):
    Solid_Block()
{
    if(!texture.loadFromFile(filename));
        std::cerr << "Failed to load \"" << filename << "\", make sure the file exists." << std::endl;

    texture.setRepeated(true);
    block.setTexture(texture);

    block.setScale(sf::Vector2f(getBlockScale(), getBlockScale()));
    
    block.setPosition(sf::Vector2f(convertInput(x), World::getHeight() - convertInput(y)));
    
    block.setTextureRect(sf::IntRect(0, 0, 720 * width, 720 * height));
} 

sf::Sprite Wood_Block::getSprite() const
{
    return block;
}

float Wood_Block::convertInput(const float input) const
{
    return (float)(input * getBlockScale() * texture.getSize().x);
}