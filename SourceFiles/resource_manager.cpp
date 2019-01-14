#include "resource_manager.h"
#include "sprite.h"
#include <iostream>


void Resource_Manager::loadTexture(const std::string& path, const std::string& key, const sf::IntRect& area)
{
    sf::Texture temp;
    temp.loadFromFile(path, area);

    textures[key] = temp;
}

sf::Texture& Resource_Manager::getTexture(const std::string& key)
{
    return textures[key];
}