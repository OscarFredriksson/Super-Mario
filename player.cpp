#include "player.h"

Player::Player()
    :body(sf::Vector2f(width, height))
{
    body.setPosition(sf::Vector2f(positionX, positionY));
    body.setFillColor(sf::Color::Red);
    body.setOutlineColor(sf::Color::Black);
    body.setOutlineThickness(2.f);
}

sf::RectangleShape Player::getSprite() const
{
    return body;
}

void Player::jump()
{    
    if(positionY == groundHeight)   velocityY = -10.f;
}

void Player::updatePosition()
{
        positionY += velocityY;
        velocityY += getGravity();
  
        if(positionY > groundHeight)    
        {
            positionY = groundHeight;
            velocityY = 0;
        }

        body.setPosition(positionX, positionY);  
}