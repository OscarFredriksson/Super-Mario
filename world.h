#ifndef WORLD_H
#define WORLD_H

#include <SFML/graphics.hpp>
#include <vector>
#include "ground.h"

class World
{
public:
    World();

    float getGravity() const;

    std::vector<sf::RectangleShape> getObjects();

    //float getGroundPosition() const;

    static float getWidth();

    static float getHeight();

private:
    std::vector<sf::RectangleShape> ground;

    const float gravity = .5f;

   // const float groundWidth = 1000.f;
    //const float groundHeight = 400.f;

    //const float groundPositionX = 0.f;
    //const float groundPositionY = 500.f;

    static constexpr float width = 1000.f;
    static constexpr float height = 600.f;

    //sf::RectangleShape ground;
};

#endif