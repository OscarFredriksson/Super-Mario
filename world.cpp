#include "world.h"

World::World()
{
    ground.push_back(Ground(0, 400, 250).getSprite());
    ground.push_back(Ground(250, 450, 500).getSprite());
    ground.push_back(Ground(750, 400, 250).getSprite());
}

float World::getGravity() const
{
    return gravity;
}

std::vector<sf::RectangleShape> World::getObjects()
{
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