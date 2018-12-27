#ifndef SOUND_H
#define SOUND_H

#include <SFML/Audio.hpp>
#include <string>

class Sound: public sf::Sound
{
public:
    Sound(std::string path);

private:
    sf::SoundBuffer buffer;
};

#endif