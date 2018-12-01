#ifndef WORLD_H
#define WORLD_H

#include <SFML/graphics.hpp>

class World
{
public:
    World();

    float getGravity() const;

    sf::RectangleShape getGroundSprite() const;

private:
    const float gravity = .5f;

    const float groundWidth = 1000.f;
    const float groundHeight = 600.f;

    const float groundPositionX = 0.f;
    const float groundPositionY = 522.f;

    sf::RectangleShape ground;
};

#endif