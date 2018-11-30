#include <SFML/Graphics.hpp>
#include "player.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "");
 
    sf::RectangleShape ground(sf::Vector2f(1000.f, 600.f));
    ground.setPosition(sf::Vector2f(0.f, 522.f));
    ground.setOutlineThickness(20.f);
    ground.setFillColor(sf::Color::Green);
    ground.setOutlineColor(sf::Color(0, 100, 0));

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

        window.clear(sf::Color::White);

        player.updatePosition();

        window.draw(player.getSprite());
        window.draw(ground);

        window.display();
    }

    return 0;
}