#ifndef AUDIO_CONTROLLER_H
#define AUDIO_CONTROLLER_H
#include <SFML/Audio/Listener.hpp>

class Audio_Controller: public sf::Listener
{
public:
    Audio_Controller() = delete;    

    static void toggleMute();   //Växlar mellan om ljud ska höras eller inte 

    static bool muted();    //Returnerar om ljudet är muteat eller inte

    static void increaseVolume(const float amount = 10.f);  //Höjer volymen med en given mängd

    static void decreaseVolume(const float amount = 10.f);  //Sänker volymen med en given mängd

private:
    inline static bool _muted = false;
};

#endif