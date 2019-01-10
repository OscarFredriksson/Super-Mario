#include "block.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Block::Block(Type type, const int x, const int y)
{
    sf::Texture texture;
    if(!texture.loadFromFile(filename, sf::IntRect(Sprite::getTextureSize() * type, 0, Sprite::getTextureSize(), Sprite::getTextureSize())))
        std::cerr << "Failed to load \"" << filename << "\"\n";

    block.setTexture(texture);

    block.setPosition(x, y);
}

void Block::draw(sf::RenderWindow& window)
{
    window.draw(block);
}