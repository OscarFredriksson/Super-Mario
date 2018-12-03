#include "ground.h"

Ground::Ground(const float x, const float y, const float width):
    ground(sf::Vector2f(width, World::getHeight() - y))  
{
    ground.setPosition(sf::Vector2f(x, y));
    ground.setFillColor(sf::Color::Green); 
}

sf::RectangleShape Ground::getSprite() const
{
    return ground;
}