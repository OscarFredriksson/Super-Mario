#ifndef WORLD_H
#define WORLD_H

#include <SFML/graphics.hpp>
#include <vector>
#include <string>
#include "block.h"

class World
{
public:
    World();

    float getGravity() const;

    float getWidth();

    float getHeight();

    float draw(const sf::Window& window);

private:
    const float gravity = .5f;

    const int width = 2000;
    const int height = 1000;

    Block* world[200][100];
};

#endif