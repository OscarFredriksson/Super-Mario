#ifndef GAME_H
#define GAME_H

#include "world.h"
#include <vector>
#include <string>
#include "player.h"
#include "enemy.h"
#include "resource_holder.h"

//! Håller spelet och alla dess resurser
/*!
*/
class Game
{
public:
    //! Skapar en instans av spelet 
    /*
        @param width    Bredden av fönstret som spelet körs i
        @param height   Höjden av fönstret som spelet körs i
        @param titel    Spelets titel, visas på fönstrets ram

    */
    Game(const int width, const int height, const std::string title);

    //! Starta spelet
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

    const float gravity = 0.0075f;

    sf::RenderWindow window;
    sf::View view;
    
    std::shared_ptr<World> world;
    std::unique_ptr<Player> player;
    std::vector<std::unique_ptr<Enemy>> enemies;

    Resource_Holder<sf::Font, std::string> fonts;

    const std::string font1_path = "Fonts/SuperMario.ttf";
    const std::string font1_id = "font1";

    sf::Music music;
    const std::string themeMusic_path = "Sounds/main_theme.wav";
    const std::string gameOverMusic_path = "Sounds/game_over.wav";
    const std::string victoryMusic_path = "Sounds/win.wav";

    const std::string pauseSound_path = "Sounds/pause.wav";
};

#endif