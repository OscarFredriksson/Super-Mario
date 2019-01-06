#include "enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Enemy::Enemy(const int x, const int y, World& world):
    Character(world, width, height),
    sprite(width, height, 0.1)
{
    setHorisontalVelocity(moveSpeed);
    setStopSpeed(0);

    Character::setPosition(x, y);

    sf::Texture texture;
    const std::string texture_path = "Textures/Goomba.png";
    if(!texture.loadFromFile(texture_path))
        std::cerr << "Failed to load \"" << texture_path << "\"\n";

    sprite.setTexture(texture);
}

void Enemy::updatePosition()
{
    sprite.update(0, 1);

    if(getHorisontalVelocity() == 0)
    {
        flip();
        setHorisontalVelocity(moveSpeed * getDirection());
    }

    Character::updatePosition();

    sprite.setPosition(getPositionX(), getPositionY());
}

void Enemy::flip()
{
    if(getDirection() == Left)  setDirection(Right);
    else                        setDirection(Left);

    sprite.flip();
}

void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

