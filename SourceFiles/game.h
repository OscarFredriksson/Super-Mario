#ifndef GAME_H
#define GAME_H

#include "world.h"
#include <vector>
#include <string>
#include "player.h"
#include "enemy.h"
#include "resource_holder.h"


class Game
{
public:
    Game(const int width, const int height, const std::string title);

    void run();

private:

    void initializeView();

    void startMusic();

    void displayGameOver();

    void displayGameWon();

    void pause();

    void pollWindowEvents(sf::Event& event);

    void handleInputs();

    void handleButtonEvents(sf::Event& event);

    void updateObjects();

    void drawObjects();

    void checkForEnemyCollision();

    void cleanupDeadEnemies();

    bool playerStompsEnemy(const std::unique_ptr<Enemy>& e);

    bool gameOver = false;
    bool gameWon = false;

    sf::RenderWindow window;
    sf::View view;
    
    std::shared_ptr<World> world;
    std::unique_ptr<Player> player;
    std::vector<std::unique_ptr<Enemy>> enemies;

    Resource_Holder<sf::Font, std::string> fonts;

    const std::string font1_path = "Fonts/SuperMario.ttf";
    const std::string font1_id = "font1";

    sf::Music music;
    const std::string music_path = "Sounds/main_theme.wav";

    const std::string pauseSound_path = "Sounds/pause.wav";
};

#endif