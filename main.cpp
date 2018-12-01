#include <SFML/Graphics.hpp>
#include "player.h"
#include <iostream>

int main()
{
    World world;

    sf::RenderWindow window(sf::VideoMode(world.getWidth(), 600.f), "");
    window.setFramerateLimit(60);
    
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

        window.draw(world.getGroundSprite());
        window.draw(player.getSprite());

        window.display();
    }

    return 0;
}