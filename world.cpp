#include "world.h"
#include "Blocks/ground_block.h"
#include "Blocks/brick_block.h"

World::World()
{
    fillMap();

    map[1][11] = new Brick_Block(1, 11);
    map[2][12] = new Ground_Block(2, 12);
    map[3][12] = new Ground_Block(3, 12);


}

float World::getWidth()
{
    //return width;
}

float World::getHeight()
{
    //return height;
}

float World::draw(sf::RenderWindow& window)
{
    for(int i = 0; i < width; i++)
        for(int j = 0; j < height; j++)
            if(map[i][j] != nullptr)
                window.draw(map[i][j]->getSprite());
}