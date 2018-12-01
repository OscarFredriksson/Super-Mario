#include "player.h"

Player::Player():
    body(sf::Vector2f(width, height)),
    atGroundPos(getGroundPosition() - getHeight())
{
    positionY = atGroundPos;

    body.setPosition(sf::Vector2f(positionX, positionY));
    body.setFillColor(sf::Color::Red);
    body.setOutlineColor(sf::Color::Black);
    body.setOutlineThickness(outlinethickness);
}

sf::RectangleShape Player::getSprite() const
{
    return body;
}

void Player::jump()
{    
    if(positionY == atGroundPos)   velocityY = -10.f;
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
    //Hoppa
    positionY += velocityY;
    velocityY += getGravity();

    if(positionY > atGroundPos)    
    {
        positionY = atGroundPos;
        velocityY = 0;
    }
    
    //Flytta i sidled
    positionX  += velocityX; 
    velocityX *= stopSpeed;  //Sänk hastigheten för att tillslut stanna

    if(positionX < outlinethickness)   
        positionX = outlinethickness;
    
    if(positionX > World::getWidth() - getWidth()- outlinethickness)  
        positionX = World::getWidth() - getWidth() - outlinethickness;
    

    body.setPosition(positionX, positionY);  
}

float Player::getHeight() const
{
    return height + outlinethickness;
}

float Player::getWidth() const
{
    return width;
}