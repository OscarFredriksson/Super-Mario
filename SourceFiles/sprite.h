#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>


//! Klass för en sprite, ärver av sf::Sprite
/*!  
*/
class Sprite: public sf::Sprite
{
public:
    //!Default konstruktor
    Sprite() = default;

    //!Inverterar spriten så dess textur blir spegelvänd
    void flip();

    //!Sätter spritens position
    void setPosition(float x, float y);

    void setTexture(sf::Texture& texture);

    static int getTextureSize();

private:
    static constexpr int textureSize = 16;

    static float convertCoords(const float c);
};

#endif