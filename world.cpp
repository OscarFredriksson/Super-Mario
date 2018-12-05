#include "world.h"
#include "Blocks/brick_block.h"

World::World()
{
    world[0][0] = new Brick_Block();

}

float World::getGravity() const
{
    return gravity;
}

float World::getWidth()
{
    return width;
}

float World::getHeight()
{
    return height;
}

float World::draw(const sf::Window& window)
{
    
}