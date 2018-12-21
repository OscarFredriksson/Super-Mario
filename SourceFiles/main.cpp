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

        if( event.type == sf::Event::KeyReleased)
        {
            if(event.key.code == sf::Keyboard::Up)  
                player.endJump();
            if(event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
                player.endWalk();
        }
    
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    player.jump();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.endWalk();
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
            player.move(Player::Right);
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  
            player.move(Player::Left);

        window.clear(sf::Color::Cyan);

        player.updatePosition();
        
    
        view.setCenter(sf::Vector2f(player.getSprite().getPosition().x, 175));
        
        if(view.getCenter().x < view.getSize().x/2)
            view.setCenter(sf::Vector2f(view.getSize().x/2, 175));
        
        window.setView(view);

        player.draw(window);
        world.draw(window);

        window.display();
    }

    return 0;
}