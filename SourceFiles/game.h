#ifndef GAME_H
#define GAME_H

#include "world.h"
#include "player.h"
#include "enemy.h"
#include <vector>
#include <string>
#include <memory>


class Game
{
public:
    Game();

    void run();

private:
    void handleInputs();

    void updateObjects(sf::RenderWindow& window, sf::View& view);

    void drawObjects(sf::RenderWindow& window);


    const std::string title = "Super Mario";
    World world;
    Player player;
    std::vector<std::unique_ptr<Enemy>> enemies;

};

#endif