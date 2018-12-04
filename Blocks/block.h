#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>
#include <string>

class Block 
{
public:
    Block() = default;


    virtual sf::Sprite getSprite() const = 0;

protected:
    float getBlockScale() const;

    float getTextureSize() const;

    std::string getFilename() const;

private:
    const float scale = .5f;

    const int textureSize = 64;

    const std::string filename = "Textures/Blocks.png";
};

#endif