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

    void initializeView();

    void startMusic();

    void displayGameOver();

    void pause();

    void pollWindowEvents(sf::Event& event);

    void handleInputs();

    void handleButtonEvents(sf::Event& event);

    void updateObjects();

    void drawObjects();

    void checkForEnemyCollision();

    bool playerStompsEnemy(const std::unique_ptr<Enemy>& e);

    bool gameOver = false;

    sf::RenderWindow window;
    sf::View view;
    
    World world;
    Player player;
    std::vector<std::unique_ptr<Enemy>> enemies;

    const std::string font_path = "Fonts/SuperMario.ttf";

    sf::Music music;
    const std::string music_path = "Sounds/main_theme.wav";

    const std::string pauseSound_path = "Sounds/pause.wav";

};

#endif