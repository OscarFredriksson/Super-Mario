#include "enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Enemy::Enemy(const int x, const int y, const std::shared_ptr<World>& world):
    Character(world, width, height),
    sprite(width, height, 0.1)
{
    setHorisontalVelocity(moveSpeed);
    setStopSpeed(0);

    Character::setPosition(x, y);

    const std::string id = "goomba";
    
    try
    {
        textures.load(id, texture_path);
    }
    catch(std::runtime_error& e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }

    sprite.setTexture(textures.get(id));
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

