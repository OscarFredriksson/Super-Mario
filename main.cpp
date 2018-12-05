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

    sf::Texture background_text;
    background_text.loadFromFile("Textures/Background.png", sf::IntRect(1000,0, world.getWidth(), world.getHeight()));
    
    sf::Sprite background;
    background.setTexture(background_text);

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
        window.draw(background);

        std::vector<sf::Sprite> ground = world.getObjects();

        for(auto obj: ground)   window.draw(obj);

        player.updatePosition();

        window.draw(player.getSprite());

        window.display();
    }

    return 0;
}