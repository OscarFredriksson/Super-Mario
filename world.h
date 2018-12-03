#ifndef WORLD_H
#define WORLD_H

#include <SFML/graphics.hpp>
#include <vector>
#include "Blocks/block.h"

class World
{
public:
    World();

    float getGravity() const;

    std::vector<sf::Sprite> getObjects();

    static float getWidth();

    static float getHeight();

private:
    std::vector<Block*> blocks;

    const float gravity = .5f;

    static constexpr float width = 1000.f;
    static constexpr float height = 600.f;

};

#endif