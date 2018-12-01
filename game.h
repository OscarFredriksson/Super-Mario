#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();

    float getGravity() const;

private:
    float gravity = .5f;
};

#endif