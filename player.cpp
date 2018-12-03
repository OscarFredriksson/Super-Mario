#include "player.h"
#include <iostream>

Player::Player():
    body(sf::Vector2f(width, height))
{
    body.setPosition(sf::Vector2f(positionX, positionY));
    body.setFillColor(sf::Color::Red);
}

sf::RectangleShape Player::getSprite() const
{
    return body;
}

void Player::jump()
{    
    if(atGround)   
    {
        velocityY = -10.f;
        atGround = false;
    }
}

void Player::moveLeft()
{
    velocityX = -moveSpeed;
}

void Player::moveRight()
{
    velocityX = moveSpeed;
}

void Player::updatePosition()
{
    if(!atGround)    
    {
        positionY += velocityY;
        velocityY += getGravity();  
    }

    float prevX = positionX;

    positionX  += velocityX; 
    velocityX *= stopSpeed;  //Sänk hastigheten för att tillslut stanna

    body.setPosition(positionX, positionY); //Sätt positionen för att kunna använta intersect-funktionen

    validHorisontalMove();

    handleJump();

    body.setPosition(positionX, positionY); //Sätt positionen igen utifrån de potientalt modifierade x- och y-värdena
}

float Player::getHeight() const
{
    return height;
}

float Player::getWidth() const
{
    return width;
}

void Player::handleJump()
{
    std::vector<sf::RectangleShape> ground = getObjects();

    bool foundGround = false;

    for(auto obj: ground)
    {
        if(body.getGlobalBounds().intersects(obj.getGlobalBounds())
            && obj.getPosition().y >= (positionY + height - 40.f))
        {
            positionY = obj.getPosition().y - getHeight() + 1.f;

            velocityY = 0;
            atGround = true;
            foundGround = true;
        }    
    } 

    if(!foundGround) atGround = false;
}

void Player::validHorisontalMove()
{
    if(positionX < 0)     
        positionX = 0;
    if(positionX > (World::getWidth() - width))
        positionX = World::getWidth() - width;
    
    std::vector<sf::RectangleShape> ground = getObjects();

    for(auto obj: ground)
    {
        if( body.getGlobalBounds().intersects(obj.getGlobalBounds()) 
            && obj.getPosition().y < (positionY + height - 1.f))
        {
            if((positionX + width) > (obj.getPosition().x + obj.getSize().x))
            {  
                positionX = obj.getPosition().x + obj.getSize().x;
            }
            if(positionX < obj.getPosition().x)
            {
                positionX = obj.getPosition().x - width;
            }
        }
    }
}