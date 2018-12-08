#include "block.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Block::Block(Type type, const int x, const int y)
 :block(texture)
{
    texture.loadFromFile(filename, sf::IntRect(getTextureSize() * type, 0, getTextureSize(), getTextureSize()));

    block.setPosition(convertCoords(x), convertCoords(y));
}

sf::Sprite Block::getSprite() const
{
    return block;
}