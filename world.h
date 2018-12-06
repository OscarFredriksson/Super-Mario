#ifndef WORLD_H
#define WORLD_H

#include <SFML/graphics.hpp>
#include <vector>
#include <string>
#include "Blocks/block.h"

class World
{
public:
    World();

    float getWidth();

    float getHeight();

    float draw(sf::RenderWindow& window);

protected:
    std::vector<std::vector<Block*>> map;

private:
    //const float gravity = .5f;

    const size_t width = 200;
    const size_t height = 100;

    void fillMap()
    {
        for(int i = 0; i < width; i++)
        {
            std::vector<Block*> row;
            for(int j = 0; j < height; j++)
                row.push_back(nullptr);
            map.push_back(row);
        }
    }
};

#endif