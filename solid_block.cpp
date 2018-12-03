#include "solid_block.h"

Solid_Block::Solid_Block(const int x, const int y, const int width, const int height):
    block(sf::Vector2f(float(width * blockSize), float(height * blockSize)))  
{

    block.setPosition(sf::Vector2f((float)(x * blockSize), (float)(y * blockSize)));
    
    block.setOutlineColor(sf::Color::Black);
    block.setOutlineThickness(1.f);
    block.setFillColor(sf::Color::Green); 
}

sf::RectangleShape Solid_Block::getSprite() const
{
    return block;
}