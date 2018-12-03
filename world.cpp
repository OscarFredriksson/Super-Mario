#include "world.h"
#include "Blocks/brick_block.h"
#include "Blocks/ground_block.h"
#include "Blocks/question_block.h"
#include "Blocks/solid_block.h"

World::World()
{
    //Platform
    blocks.push_back(new Ground_Block(0, 2, 20, 2));
    
    //Tre block i luften
    blocks.push_back(new Brick_Block(8, 5, 1, 1));
    blocks.push_back(new Question_Block(9, 5, 1, 1));
    blocks.push_back(new Brick_Block(10, 5, 1, 1));
    
    //Trappa
    blocks.push_back(new Solid_Block(17, 3, 3, 1));
    blocks.push_back(new Solid_Block(18, 4, 2, 1));
    blocks.push_back(new Solid_Block(19, 5, 1, 1));
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