#include "world.h"

World::World()
{
    blocks.push_back(new Wood_Block(1, 2, 7, 1));
}

float World::getGravity() const
{
    return gravity;
}

std::vector<sf::Sprite> World::getObjects()
{
    std::vector<sf::Sprite> ground;
    for(auto block: blocks)
        ground.push_back(block->getSprite());

    return ground;
}

float World::getWidth()
{
    return width;
}

float World::getHeight()
{
    return height;
}