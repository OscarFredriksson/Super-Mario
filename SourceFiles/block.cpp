#include "block.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Block::Block(Type type, const int x, const int y)
{
    sf::Texture texture;
    if(!texture.loadFromFile(filename, sf::IntRect(getTextureSize() * type, 0, getTextureSize(), getTextureSize())))
        std::cerr << "Failed to load \"" << filename << "\"\n";

    block.setTexture(texture);

    block.setPosition(x, y);
}

sf::Sprite Block::getSprite() const
{
    return block;
}