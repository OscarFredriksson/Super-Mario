#include <SFML/Graphics.hpp>
#include "player.h"
#include "world.h"
#include <iostream>

int main()
{
    World world;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(640, 480), "Super Mario", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    sf::View view;

    const double viewScale = 2;

    view.setSize(640 * viewScale, 480 * viewScale);

    view.setCenter(640, 480);

    window.setView(view);

    Player player;
    
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

        window.clear(sf::Color::Cyan);

        player.updatePosition();

        player.draw(window);
        world.draw(window);

        window.display();
    }

    return 0;
}