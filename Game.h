#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

class Game
{
public:
    Game() = default;

    static const float convertCoords(const float c)
    {
        return c*textureSize;
    }

protected:
    static const int textureSize = 64;

    const float gravity = 0.005f;

private:
    sf::RenderWindow window;
};

#endif