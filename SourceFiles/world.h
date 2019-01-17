#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "block.h"
#include <memory>

class World
{
public:
    World() = default;

    void loadMap(std::string filename);

    void draw(sf::RenderWindow& window);

    int leftBoundary() const;

    int rightBoundary() const;

    int topBoundary() const;

    int bottomBoundary() const;

    bool isSolidBlock(const int x, const int y) const;  

    bool reachedFinish(const int x) const;

    float getGravity() const;  

private:
    std::vector<std::vector<std::unique_ptr<Block>>> map;

    const float gravity = 0.0075f;

    int finishLine;

};

#endif