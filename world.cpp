#include "world.h"

World::World()
    :ground(sf::Vector2f(groundWidth, groundHeight))
{
    ground.setPosition(sf::Vector2f(groundPositionX, groundPositionY));
    ground.setOutlineThickness(20.f);
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