#include "world.h"

World::World()
    :ground(sf::Vector2f(groundWidth, groundHeight))
{
    ground.setPosition(sf::Vector2f(groundPositionX, groundPositionY));
    ground.setOutlineThickness(outlineThickess);
    ground.setFillColor(sf::Color::Green);
    ground.setOutlineColor(sf::Color(0, 100, 0));
}

float World::getGravity() const
{
    return gravity;
}

sf::RectangleShape World::getGroundSprite() const
{
    return ground;
}

float World::getGroundPosition() const
{
    return groundPositionY - outlineThickess;
}

float World::getWidth() const
{
    return width;
}