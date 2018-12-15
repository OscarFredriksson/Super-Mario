#include <SFML/Graphics.hpp>
#include "player.h"
#include "world.h"
#include <iostream>

int main()
{
    World world;
    world.loadMap("map.txt");

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(640, 480), "Super Mario", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    sf::View view;

    const double viewScale = 0.5;

    view.setSize(640 * viewScale, 480 * viewScale);

    view.setCenter(640, 480);

    window.setView(view);

    Player player(world);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    player.jump();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) player.moveRight();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  player.moveLeft();

        if( event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)  
            player.endJump();

        window.clear(sf::Color::Cyan);

        player.updatePosition();
        
        view.setCenter(sf::Vector2f(player.getSprite().getPosition().x, 175));
        window.setView(view);

        player.draw(window);
        world.draw(window);

        window.display();
    }

    return 0;
}