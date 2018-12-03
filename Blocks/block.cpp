#include "block.h"
#include "../world.h"

float Block::getBlockScale() const
{
    return scale;
}

float Block::getTextureSize() const
{
    return textureSize;
}

std::string Block::getFilename() const
{
    return filename;
}