#include "enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>


Enemy::Enemy(const sf::Vector2f position, const std::shared_ptr<World>& world):
    Character(width, height, world),
    sprite(width, height, 0.1)
{
    setHorisontalVelocity(moveSpeed);
    setStopSpeed(0);

    Character::setPosition(position);

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

    if(getVelocity().x == 0)
    {
        flip();
        setHorisontalVelocity(moveSpeed * getDirection());
    }

    Character::updatePosition();

    sprite.setPosition(getPosition().x, getPosition().y);
}

sf::Sprite Enemy::getSprite() const
{
    return sprite;
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

