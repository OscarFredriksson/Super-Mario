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
        velocityY = -jumpSpeed;
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
    setVelocity();

    checkForGround();

    checkForWall();

    setPosition(positionX, positionY);
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

}

void Player::checkForGround()
{
    if(velocityY < 0)   return; //Om Mario är påväg uppåt fortfarande behöver vi inte kolla

    bool foundGround = false;

    if( map[left() ][bottom()] != nullptr ||    //Kolla vänster hörn
        map[right()][bottom()] != nullptr)      //Kolla höger hörn
    {
        positionY = (int)top(); //casta till int för att avrunda till heltal 
        foundGround = true;

        if(!atGround)
        {
            std::cout << "!" << std::endl;

            velocityY = 0;
            atGround = true;
        }
    }
    
    if(!foundGround) atGround = false;
}

void Player::checkForWall()
{
    //Kolla vänster
    if( map[left()][top()   ] != nullptr ||    
        map[left()][top()+1 ] != nullptr ||
        map[left()][bottom()] != nullptr)
    {
        positionX = left() + 1; //casta till int för att avrunda till heltal 
        velocityX = 0;
    }
}

void Player::setPosition(float x, float y)
{
    body.setPosition(convertCoords(positionX), convertCoords(positionY));
}
