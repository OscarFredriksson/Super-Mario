#include "game.h"
#include <SFML/Graphics.hpp>

Game::Game():
    player(world)
{
    enemies.emplace_back(std::make_unique<Enemy>(world));

    world.loadMap("map.txt");
}

void Game::run()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(640, 480), title, sf::Style::Default, settings);
    window.setFramerateLimit(60);

    sf::View view;

    const double viewScale = 0.5;

    view.setSize(640 * viewScale, 480 * viewScale);

    view.setCenter(640, 480);

    window.setView(view);

    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if( event.type == sf::Event::KeyReleased)
        {
            if(event.key.code == sf::Keyboard::Up)  
                player.endJump();
            if(event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
                player.endWalk();
        }
    
        handleInputs();

        updateObjects(window, view);
        
        drawObjects(window);
    }

}

void Game::handleInputs()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    player.jump();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player.endWalk();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
        player.move(Player::Right);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  
        player.move(Player::Left);
}

void Game::updateObjects(sf::RenderWindow& window, sf::View& view)
{
    player.updatePosition();
        
    std::for_each(enemies.begin(), enemies.end(), [](std::unique_ptr<Enemy>& e)
    {
        e->updatePosition();
    });
    
    view.setCenter(sf::Vector2f(player.getSprite().getPosition().x, 175));
    
    if(view.getCenter().x < view.getSize().x/2)
        view.setCenter(sf::Vector2f(view.getSize().x/2, 175));
    
    window.setView(view);
}

void Game::drawObjects(sf::RenderWindow& window)
{
    window.clear(sf::Color::Cyan);

    world.draw(window);
    player.draw(window);

    std::for_each(enemies.begin(), enemies.end(), [&](std::unique_ptr<Enemy>& e)
    {
        e->draw(window);
    });

    window.display();
}