#include "audio_controller.h"

void Audio_Controller::toggleMute()
{
    static float prevVolume;

    if(!muted)           
    {
        prevVolume = getGlobalVolume();
        setGlobalVolume(.01); //Funkar ej att sätta direkt till 0 av nån anledning, sätt jättelågt så är det tyst ändå
    }
    else setGlobalVolume(prevVolume);
    muted = !muted;
}

void Audio_Controller::increaseVolume(const float amount)
{
    setGlobalVolume(getGlobalVolume() + amount);
}

void Audio_Controller::decreaseVolume(const float amount)
{
    setGlobalVolume(getGlobalVolume() - amount);
}