#include "game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

Game::Game(const int width, const int height, const std::string title):
    window(sf::VideoMode(width, height), title),
    player(world)
{
    window.setFramerateLimit(60);

    enemies.emplace_back(std::make_unique<Enemy>(world));

    world.loadMap("map.txt");
}

void Game::run()
{
    sf::View view;
    const double viewZoom = 0.5;
    view.setSize(window.getSize().x * viewZoom, window.getSize().y * viewZoom);
    window.setView(view);

    if(!music.openFromFile(music_path))
        std::cerr << "Failed to open \"" << music_path << "\"\n";
    
    music.setLoop(true);
    music.play();

    while (window.isOpen())
    {
        handleInputs(window);

        updateObjects(window, view);

        if(gameOver)    
        {
            displayGameOver(window);
            return;
        }

        drawObjects(window);
    }

}

void Game::displayGameOver(sf::RenderWindow& window)
{
    sf::Font font;
    const std::string font_path = "Fonts/SuperMario.ttf";
    if(!font.loadFromFile(font_path))
        std::cerr << "Failed to load \"" << font_path << "\"\n";
    
    sf::Text text("GAME OVER", font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);

    window.setView(window.getDefaultView());

    text.setPosition(window.getSize().x/2, window.getSize().y/2.5);



    sf::Music gameOver_music;
    const std::string music_path = "Sounds/game_over.wav";
    if(!gameOver_music.openFromFile(music_path))
        std::cerr << "Failed to open \"" << music_path << "\"\n";
    
    music.stop();
    gameOver_music.play();

    sf::sleep(sf::seconds(1));

    window.clear(sf::Color::Black);
    window.draw(text);
    window.display();

    sf::sleep(sf::seconds(2));
}

void Game::handleInputs(sf::RenderWindow& window)
{
    //-------Handle window events-------
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    //--------Handle keypress------
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    player.jump();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player.endWalk();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
        player.move(Player::Right);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  
        player.move(Player::Left);

    //----------Handle keyrelease---------
    if( event.type == sf::Event::KeyReleased)
    {
        if(event.key.code == sf::Keyboard::Up)  
            player.endJump();
        if(event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
            player.endWalk();
    }
}

void Game::updateObjects(sf::RenderWindow& window, sf::View& view)
{
    player.updatePosition();

    if(!player.isAlive())   gameOver = true;
        
    std::for_each(enemies.begin(), enemies.end(), [](std::unique_ptr<Enemy>& e)
    {
        e->updatePosition();
    });

    checkForEnemyCollision();

    const int viewHeight = 175;
    
    view.setCenter(sf::Vector2f(player.getSprite().getPosition().x, viewHeight));
    
    if(view.getCenter().x < view.getSize().x/2)
        view.setCenter(sf::Vector2f(view.getSize().x/2, viewHeight));
    
    window.setView(view);
}

void Game::drawObjects(sf::RenderWindow& window)
{
    window.clear(sf::Color::Cyan);

    world.draw(window);
    player.draw(window);

    std::for_each(enemies.begin(), enemies.end(), [&window](std::unique_ptr<Enemy>& e)
    {
        e->draw(window);
    });

    window.display();
}

void Game::checkForEnemyCollision()
{

    if(player.getSprite().getGlobalBounds().intersects(enemies[0]->getSprite().getGlobalBounds()))
    {
        enemies.pop_back();
    }

    /*std::for_each(enemies.begin(), enemies.end(), [&](std::unique_ptr<Enemy>& e)
    {
        if(player.getSprite().getGlobalBounds().intersects(e->getSprite().getGlobalBounds()))
        {
            e.reset();
        }

        
    });*/
}

std::vector<std::unique_ptr<Enemy>> Game::findNearbyEnemies() const
{

}