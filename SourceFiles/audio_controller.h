#ifndef AUDIO_CONTROLLER_H
#define AUDIO_CONTROLLER_H
#include <SFML/Audio/Listener.hpp>

class Audio_Controller: public sf::Listener
{
public:
    Audio_Controller() = delete;

    static void toggleMute();

    static bool muted();

    static void increaseVolume(const float amount = 10.f);

    static void decreaseVolume(const float amount = 10.f);

private:
    inline static bool _muted = false;
};

#endif