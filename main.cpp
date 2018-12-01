#include <SFML/Graphics.hpp>
#include "player.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "");
    window.setFramerateLimit(60);
    
    World world;

    Player player;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    
        {
            player.jump();
        }

        window.clear(sf::Color::Cyan);

        player.updatePosition();

        window.draw(world.getGroundSprite());
        window.draw(player.getSprite());

        window.display();
    }

    return 0;
}