#include "block.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Block::Block(Type type, const int x, const int y)
{ 
    textures.load(type, texture_path, sf::IntRect(Sprite::getTextureSize() * type, 0, Sprite::getTextureSize(), Sprite::getTextureSize()));

    sprite.setTexture(textures.get(type));

    sprite.setPosition(x, y);
}

void Block::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}