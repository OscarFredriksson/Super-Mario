#include "block.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Block::Block(Type type, const int x, const int y)
{
    sf::Texture texture;
    texture.loadFromFile(filename, sf::IntRect(getTextureSize() * type, 0, getTextureSize(), getTextureSize()));

    block.setTexture(texture);

    block.setPosition(x, y);
}

sf::Sprite Block::getSprite() const
{
    return block;
}