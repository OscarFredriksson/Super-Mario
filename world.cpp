#include "world.h"

World::World():
    ground(sf::Vector2f(groundWidth, groundHeight))
{
    ground.setPosition(sf::Vector2f(groundPositionX, groundPositionY));
    ground.setFillColor(sf::Color::Green);
}

float World::getGravity() const
{
    return gravity;
}

std::vector<sf::RectangleShape> World::getObjects()
{
    std::vector<sf::RectangleShape> ret;
    ret.push_back(ground);

    sf::RectangleShape ground2(sf::Vector2f(groundWidth, groundHeight));
    ground2.setPosition(sf::Vector2f(400.f, 450.f));
    ground2.setFillColor(sf::Color::Green);

    ret.push_back(ground2);

    return ret;
}

float World::getGroundPosition() const
{
    return groundPositionY; // - outlineThickess;
}

float World::getWidth() const
{
    return width;
}