#include "sound.h"
#include <iostream>

Sound::Sound(std::string path)
{
    if(!buffer.loadFromFile(path))
        std::cout << "Failed to load sound \"" << path << "\"..." << std::endl;

    setBuffer(buffer);
}