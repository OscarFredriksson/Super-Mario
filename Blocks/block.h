#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>
#include <string>

class Block 
{
public:
    Block(const int xPosInFile, const int yPosInFile, const int width, const int height);

    sf::Sprite getSprite() const;

private:
    const float scale = .5f;

    const int textureSize = 64;

    sf::Texture texture;
    sf::Sprite block;

    const std::string filename = "Textures/Blocks.png";
};

#endif