#ifndef WOOD_BLOCK_H
#define WOOD_BLOCK_H

#include "solid_block.h"
#include <string>

class Wood_Block: public Solid_Block
{
public:
    Wood_Block() = delete;

    Wood_Block(const int x, const int y, const int width, const int height);

    sf::Sprite getSprite() const override;

private:
    const std::string filename = "Textures/WoodBlock.png";

    sf::Texture texture;
    sf::Sprite block;

    float convertInput(float const input) const;
};

#endif