#ifndef GROUND_H
#define GROUND_H

#include <SFML/Graphics.hpp>
#include "world.h"

class Ground 
{
public:
    Ground(const float x, const float y, const float width);

    sf::RectangleShape getSprite() const;

private:
    sf::RectangleShape ground;
};

#endif