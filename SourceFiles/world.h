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

    int rightBoundary() const;

    bool isSolidBlock(const int x, const int y) const;  

    float getGravity() const;  

private:
    std::vector<std::vector<Block*>> map;

    const float gravity = 0.0075f;

};

#endif