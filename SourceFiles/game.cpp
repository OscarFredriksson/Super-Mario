#include "game.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include "audio_controller.h"

Game::Game(const int width, const int height, const std::string title):
    window(sf::VideoMode(width, height), title),
    world(new World()),
    player(new Player(world))
{
    window.setFramerateLimit(60);

    enemies.emplace_back(std::make_unique<Enemy>(40.f, 2.f, world));
    enemies.emplace_back(std::make_unique<Enemy>(20.f, 2.f, world));

    world->loadMap("Levels/Level-1.txt");
}

void Game::initializeView()
{
    view.setSize(window.getSize().x, window.getSize().y);
    view.zoom(0.5f);
    window.setView(view);
}

void Game::startMusic()
{
    music.openFromFile(music_path); 
    music.setLoop(true);
    music.setVolume(25);
    music.play();
}

void Game::run()
{
    initializeView();
    startMusic();

    while (window.isOpen())
    {
        handleInputs();

        updateObjects();

        if(gameOver)    
        {
            displayGameOver();
            return;
        }

        drawObjects();
    }
}

void Game::displayGameOver()
{
    sf::Font font;
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
    
    music.pause();
    gameOver_music.play();

    sf::sleep(sf::seconds(1));

    window.clear(sf::Color::Black);
    window.draw(text);
    window.display();

    sf::sleep(sf::seconds(2));
}

void Game::pause()
{
    music.pause();

    Sound pauseSound(pauseSound_path);
    pauseSound.play();


    sf::Font font;
    font.loadFromFile(font_path);

    sf::Text text("PAUSED", font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);

    text.setPosition(view.getSize().x/1.25, view.getCenter().y);

    //Byter vyn, sätter texten, och byter tillbaka för att texten inte ska bli suddig
    window.setView(window.getDefaultView());
    window.draw(text);
    window.setView(view);

    window.display();

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::P)
            {   
                music.play(); 
                return;
            }
        }
    }
}

void Game::handleInputs()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    
        player->jump();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player->endWalk();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
        player->move(Player::Right);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  
        player->move(Player::Left);

    sf::Event event;
    while (window.pollEvent(event))
    {
        switch(event.type)  
        {  
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyReleased:
                handleButtonEvents(event);
            default:
                break;
        }
    }
}

void Game::handleButtonEvents(sf::Event& event)
{
    switch(event.key.code)
    {
        case sf::Keyboard::Up:  
            player->endJump();
            break;
        case sf::Keyboard::Left:
        case sf::Keyboard::Right:
            player->endWalk();
            break;
        case sf::Keyboard::P:
            pause();
            break;
        case sf::Keyboard::M:
            Audio_Controller::toggleMute();
            break;
        case sf::Keyboard::B:
            Audio_Controller::decreaseVolume();
            break;
        case sf::Keyboard::N:
            Audio_Controller::increaseVolume();
            break;
        default:
            break;
    }
}

void Game::updateObjects()
{
    player->updatePosition();

    if(!player->isAlive())   gameOver = true;
        
    std::for_each(enemies.begin(), enemies.end(), [](std::unique_ptr<Enemy>& e)
    {
        e->updatePosition();
    });

    checkForEnemyCollision();

    const int viewHeight = 175;
    
    view.setCenter(sf::Vector2f(player->getSprite().getPosition().x, viewHeight));
    
    if(view.getCenter().x < view.getSize().x/2)
        view.setCenter(sf::Vector2f(view.getSize().x/2, viewHeight));
    
    window.setView(view);
}

void Game::drawObjects()
{
    window.clear(sf::Color::Cyan);

    world->draw(window);
    player->draw(window);

    std::for_each(enemies.begin(), enemies.end(), [this](std::unique_ptr<Enemy>& e)
    {
        e->draw(window);
    });

    window.display();
}

void Game::checkForEnemyCollision()
{
    std::for_each(enemies.begin(), enemies.end(), [this](std::unique_ptr<Enemy>& e)
    {
        if(player->getSprite().getGlobalBounds().intersects(e->getSprite().getGlobalBounds()))
        {
            if(playerStompsEnemy(e))
            {
                e->kill();
                player->stomp();
            }
            else    gameOver = true;
        }
    });
    
    //Rensa upp efter döda goombas
    enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](const std::unique_ptr<Enemy>& e)
    {
        if(!e->isAlive())   return true;
        else                return false;
    }), enemies.end());
}

bool Game::playerStompsEnemy(const std::unique_ptr<Enemy>& e)
{
    float slope = fabsf((e->getPositionY()-player->getPositionY())/(e->getPositionX()-player->getPositionX()));
    
    return (slope >= 1) && player->bottomBoundary() < e->bottomBoundary() && player->getVerticalVelocity() > 0;
}
