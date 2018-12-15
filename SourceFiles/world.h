#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "block.h"

class World
{
public:
    World() = default;

    void loadMap(std::string filename);

    void draw(sf::RenderWindow& window);

    std::vector<std::vector<Block*>> map;

protected:

private:
    const size_t width = 200;
    const size_t height = 100;
};

#endif