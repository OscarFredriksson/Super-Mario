#include "world.h"
#include "Blocks/brick_block.h"
#include "Blocks/ground_block.h"
#include "Blocks/question_block.h"
#include "Blocks/empty_block.h"

World::World()
{
    //Platform
    blocks.push_back(new Ground_Block(0, 1, 25, 1));
    
    //Block i luften
    blocks.push_back(new Brick_Block(10, 5, 1, 1));
    blocks.push_back(new Question_Block(11, 5, 1, 1));
    blocks.push_back(new Brick_Block(12, 5, 1, 1));
    blocks.push_back(new Question_Block(13, 5, 1, 1));
    blocks.push_back(new Brick_Block(14, 5, 1, 1));
    blocks.push_back(new Question_Block(12, 8, 1, 1));
    
    //Trappa
    blocks.push_back(new Empty_Block(22, 2, 3, 1));
    blocks.push_back(new Empty_Block(23, 3, 2, 1));
    blocks.push_back(new Empty_Block(24, 4, 1, 1));
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