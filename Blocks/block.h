#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>
#include <string>

#include "../game.h"

class Block: public Game
{
public:
    Block(const int x, const int y, const int xPosInFile, const int yPosInFile, const int width, const int height);

    sf::Sprite getSprite() const;

private:
    static constexpr float scale = .5f;

    static constexpr int textureSize = 64;

    sf::Texture texture;
    sf::Sprite block;

    const std::string filename = "Textures/Blocks.png";
};

#endif