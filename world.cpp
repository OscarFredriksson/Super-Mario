#include "world.h"

World::World()
{
    blocks.push_back(new Solid_Block(0, 0, 20, 1));
}

float World::getGravity() const
{
    return gravity;
}

std::vector<sf::RectangleShape> World::getObjects()
{
    std::vector<sf::RectangleShape> ground;
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