#include "player.h"
#include <iostream>
#include <cmath>

Player::Player(World& world):
    world(world),
    jumpSound(jumpSound_path)
{
    texture.loadFromFile("Textures/Mario.png", sf::IntRect(0, 0, 80, 32));

    sprite.setTexture(texture);

    //sprite.setPosition(positionX, positionY);
}

void Player::jump()
{


    if(!jumpKeyReleased)    return;
    jumpKeyReleased = false;

    if(atGround)
    {
        jumpSound.play();
        velocityY = jumpSpeed;
        atGround = false;
    }
}

void Player::endJump()
{    
    if(velocityY < jumpSpeed/2) velocityY = jumpSpeed/2;
    jumpKeyReleased = true;
}

void Player::move(Direction dir)
{
    setDirection(dir);
    velocityX = velocityX + dir * moveSpeed;
    if(fabsf(velocityX) > maxSpeed) velocityX = dir * maxSpeed;
}

void Player::endWalk()
{
    horisontalButtonHeld = false;
}

void Player::updatePosition()
{
    if(!atGround)                   sprite.set(4);
    else if(horisontalButtonHeld)   sprite.update(0, 2);
    else                            sprite.update(0, 0);
    
    velocityY += world.getGravity();
    positionY += velocityY;
    checkForGround();
    checkForRoof();

    velocityX *= stopSpeed;  //Sänk hastigheten för att tillslut stanna
    positionX += velocityX; 
    checkForWall(); 

    setPosition(positionX, positionY);
}

void Player::setPosition(float x, float y)
{
    sprite.setPosition(positionX, positionY);
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

sf::Sprite Player::getSprite() const
{
    return sprite;
}


//---------------Privata funktioner----------------

int Player::bufferedRoundoff(float i) const
{
    //Om det inte finns några decimaler alls, ge samma ruta som vi står på
    if(i == (int)i) return i - 1;   
    else            return i;
}

int Player::left() const
{
    return positionX;
}
int Player::right() const
{
    return bufferedRoundoff(positionX + width);
}
int Player::top() const
{
    return positionY;
}
int Player::bottom() const
{
    return bufferedRoundoff(positionY + height);
}

void Player::checkForGround()
{
    bool foundGround = false;

    if( world.isSolidBlock(bottom(), left()) ||    //Kolla vänster hörn
        world.isSolidBlock(bottom(), right()))      //Kolla höger hörn
    {
        positionY = top();
        foundGround = true;
        velocityY = 0;

        if(!atGround)
        {
            sprite.set(0);
            atGround = true;
        }
    }
    if(!foundGround)    atGround = false;
}

void Player::checkForRoof()
{
    if( world.isSolidBlock( top(), left() ) ||   //Kolla vänster hörn
        world.isSolidBlock( top(), right() ) )   //Kolla höger hörn
    {
        positionY = top() + 1;
        velocityY = -velocityY;
    }
}

void Player::checkForWall()
{

    //Kolla vänster världgräns
    if(positionX < 0)
    {
        positionX = 0;
        velocityX = 0;
    }

    //Kolla höger världsgräns
    if(positionX > world.rightBoundary() - width)
    {
        positionX = world.rightBoundary() - width;
        velocityX = 0;
    }

    //Kolla vänster
    if( world.isSolidBlock( top(),    left() ) ||    
        world.isSolidBlock( top()+1,  left() ) ||
        world.isSolidBlock( bottom(), left() ) )
    {
        positionX = left() + 1;
        velocityX = 0;
    }

    //Kollar höger
    if( world.isSolidBlock( top(),    right() ) ||    
        world.isSolidBlock( top()+1,  right() ) ||
        world.isSolidBlock( bottom(), right() ) )
    {
        positionX = right() - 1;
        velocityX = 0;
    }
}

void Player::setDirection(Direction new_dir)
{
    horisontalButtonHeld = true;
    if(dir != new_dir)
    {
        dir = new_dir;
        sprite.flip();
    }
}