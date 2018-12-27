#include "enemy.h"
#include <SFML/Graphics.hpp>


Enemy::Enemy(World& world):
    Character(world, width, height)
{
    setHorisontalVelocity(moveSpeed);
    setStopSpeed(1);

    Character::setPosition(30.f, 2.f);

    sf::Texture texture;
    texture.loadFromFile("Textures/Blocks.png", sf::IntRect(0, 0, 16, 16));

    sprite.setTexture(texture);
}

void Enemy::updatePosition()
{
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

