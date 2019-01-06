#ifndef GAME_H
#define GAME_H

#include "world.h"
#include <vector>
#include <string>
#include "player.h"
#include "enemy.h"



class Game
{
public:
    Game(const int width, const int height, const std::string title);

    void run();

private:
    void displayGameOver(sf::RenderWindow& window);

    void handleInputs(sf::RenderWindow& window);

    void updateObjects(sf::RenderWindow& window, sf::View& view);

    void drawObjects(sf::RenderWindow& window);

    void checkForEnemyCollision();

    std::vector<std::unique_ptr<Enemy>> findNearbyEnemies() const;

    bool gameOver = false;

    sf::RenderWindow window;
    World world;
    Player player;

    std::vector<std::unique_ptr<Enemy>> enemies;

    sf::Music music;
    const std::string music_path = "Sounds/main_theme.wav";

};

#endif