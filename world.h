#ifndef WORLD_H
#define WORLD_H

#include <SFML/graphics.hpp>

class World
{
public:
    World();

    float getGravity() const;

    sf::RectangleShape getGroundSprite() const;

    float getGroundPosition() const;

    float getWidth() const;

private:
    const float gravity = .5f;

    const float groundWidth = 1000.f;
    const float groundHeight = 400.f;
    const float outlineThickess = 20.f;

    const float groundPositionX = 0.f;
    const float groundPositionY = 500.f;

    const float width = 1000.f;

    sf::RectangleShape ground;
};

#endif