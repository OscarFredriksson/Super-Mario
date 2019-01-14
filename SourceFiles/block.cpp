#include "block.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "resource_manager.h"

Block::Block(Type type, const int x, const int y)
{ 
    const std::string key = "Block_" + std::to_string(static_cast<int>(type));

    Resource_Manager::loadTexture(texturePath, key, sf::IntRect(Sprite::getTextureSize() * type, 0, Sprite::getTextureSize(), Sprite::getTextureSize()));
    
    block.setTexture(Resource_Manager::getTexture(key));

    block.setPosition(x, y);
}

void Block::draw(sf::RenderWindow& window)
{
    window.draw(block);
}