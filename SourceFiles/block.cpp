#include "block.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Block::Block(Type type, const int x, const int y)
{ 
    try
    {
        textures.load(type, texture_path, sf::IntRect(Sprite::getTextureSize() * type, 0, Sprite::getTextureSize(), Sprite::getTextureSize()));
    }
    catch(std::runtime_error& e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }

    sprite.setTexture(textures.get(type));

    sprite.setPosition(x, y);
}

void Block::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}