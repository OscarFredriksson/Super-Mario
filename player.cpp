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
    auto now = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = now - landed_time;

    if(atGround && duration.count() > 0.1)   
    {
        velocityY = -12.5f;
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

float Player::getHeight() const
{
    return height;
}

float Player::getWidth() const
{
    return width;
}

void Player::updatePosition()
{
    setVelocity();

    handleJump();

    handleHorisontalMove();
}
 
void Player::setVelocity()
{
    if(!atGround)    
    {
        positionY += velocityY;
        velocityY += getGravity();  
    }

    positionX  += velocityX; 
    velocityX *= stopSpeed;  //Sänk hastigheten för att tillslut stanna

    body.setPosition(positionX, positionY);
}

void Player::handleJump()
{
    std::vector<sf::Sprite> ground = getObjects();

    bool foundGround = false;

    for(auto obj: ground)
    {
        if(body.getGlobalBounds().intersects(obj.getGlobalBounds()))
        {
            if( positionY < (obj.getPosition().y + obj.getGlobalBounds().height) 
                && positionY > obj.getPosition().y)
            {
                positionY = obj.getPosition().y + obj.getGlobalBounds().height + 1.f;
                velocityY = -velocityY;
            }   
            if((positionY + height) <= obj.getPosition().y + 20.f && velocityY >= 0)
            {
                foundGround = true;

                positionY = obj.getPosition().y - height + 1.f;

                if(!atGround)
                {
                    std::cout << "Landed!" << std::endl;
                    landed_time = std::chrono::high_resolution_clock::now();
                    atGround = true;
                }

            } 
        }
    } 
    body.setPosition(positionX, positionY);


    if(!foundGround) atGround = false;
}

void Player::handleHorisontalMove()
{
    if(positionX < 0)     
        positionX = 0;
    if(positionX > (World::getWidth() - width))
        positionX = World::getWidth() - width;
    
    std::vector<sf::Sprite> ground = getObjects();

    for(auto obj: ground)
    {
        if( body.getGlobalBounds().intersects(obj.getGlobalBounds()) 
            && obj.getPosition().y < (positionY + height - 1.f))
        {
            if((positionX + width) > (obj.getPosition().x + obj.getGlobalBounds().width))
            {  
                positionX = obj.getPosition().x + obj.getGlobalBounds().width + 5.f;
                velocityX = 0;
                
            }
            else if(positionX < obj.getPosition().x)
            {
                positionX = obj.getPosition().x - width - .1f;
                velocityX = 0;
            }
        }
    }
    body.setPosition(positionX, positionY);
}