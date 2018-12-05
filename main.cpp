#include <SFML/Graphics.hpp>
#include "player.h"
#include "world.h"
#include <iostream>

int main()
{
    World world;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(world.getWidth(), world.getHeight()), "Super Mario", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    sf::View view;

    const double viewScale = 0.75;

    view.setSize(world.getWidth() * viewScale, world.getHeight() * viewScale);

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

        std::vector<sf::Sprite> ground = world.getObjects();

        for(auto obj: ground)   window.draw(obj);

        player.updatePosition();

        window.draw(player.getSprite());

        view.setCenter(player.getSprite().getPosition());
        window.setView(view);

        window.display();
    }

    return 0;
}