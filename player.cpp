#include "player.h"
#include <iostream>


Player::Player():
    body()
{
    texture.loadFromFile("Textures/Blocks.png", sf::IntRect(64 * 1, 0, 64, 64));
    texture.setRepeated(true);
    texture.setSmooth(true);
    body.setTexture(texture);

    body.setPosition(sf::Vector2f(positionX, positionY));
    
    body.setTextureRect(sf::IntRect(0, 0, 64 , 128));

}

void Player::jump()
{
    if(atGround)
    {
        velocityY = -.2f;
        atGround = false;
    }
}


void Player::updatePosition()
{
    setVelocity();

    checkFall();
}
 
void Player::setVelocity()
{
    if(!atGround)    
    {
        positionY += velocityY;
        velocityY += gravity;
    }

    positionX += velocityX; 
    velocityX *= stopSpeed;  //Sänk hastigheten för att tillslut stanna

    body.setPosition(convertCoords(positionX), convertCoords(positionY));
}

void Player::checkFall()
{
    int tempX = left();
    int tempY = bottom();

    if(map[tempX][tempY] != nullptr)
    {
        positionY = tempY - height; 
        velocityY = 0;
        atGround = true;
    }
    body.setPosition(convertCoords(positionX), convertCoords(positionY));
}
