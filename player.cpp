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
    auto now = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_on_ground = now - landed_time;

    std::cout << time_on_ground.count() << std::endl;

    if(atGround && time_on_ground.count() > 0.1)
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
    positionY += velocityY;
    velocityY += gravity;
    checkForGround();
    checkForRoof();

    positionX += velocityX; 
    velocityX *= stopSpeed;  //Sänk hastigheten för att tillslut stanna
    checkForWall();

    setPosition(positionX, positionY);
}

void Player::checkForGround()
{
    if( map[left() ][bottom()] != nullptr ||    //Kolla vänster hörn
        map[right()][bottom()] != nullptr)      //Kolla höger hörn
    {
        positionY = top();
        velocityY = 0;
        
        if(!atGround)
        {
            atGround = true;
            landed_time = std::chrono::high_resolution_clock::now();
        }
    }
}

void Player::checkForRoof()
{
    if( map[left() ][top()] != nullptr ||    //Kolla vänster hörn
        map[right()][top()] != nullptr)      //Kolla höger hörn
    {
        positionY = top() + 1;
        velocityY = -velocityY;
    }
}

void Player::checkForWall()
{
    //Kolla vänster
    if( map[left()][top()   ] != nullptr ||    
        map[left()][top()+1 ] != nullptr ||
        map[left()][bottom()] != nullptr )
    {
        positionX = left() + 1;
        velocityX = 0;
    }
    //Kollar höger
    if( map[right()][top()   ] != nullptr ||    
        map[right()][top()+1 ] != nullptr ||
        map[right()][bottom()] != nullptr)
    {
        positionX = right() - 1;
        velocityX = 0;
    }
}

void Player::setPosition(float x, float y)
{
    body.setPosition(convertCoords(positionX), convertCoords(positionY));
}
