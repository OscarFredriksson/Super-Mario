#include "character.h"
#include <iostream>
#include <cmath>

Character::Character(const std::shared_ptr<World>& world, const int width, const int height):
    world(world),
    width(width),
    height(height)
{}

void Character::setJumpSpeed(const float value)
{
    jumpSpeed = value;
}

void Character::setMoveSpeed(const float value)
{
    moveSpeed = value;
}

void Character::setMaxSpeed(const float value)
{
    maxSpeed = value;
}

void Character::setStopSpeed(const float value)
{
    stopSpeed = value;
}

void Character::setVerticalVelocity(const float value)
{
    velocityY = value;
}

void Character::setHorisontalVelocity(const float value)
{
    velocityX = value;
}

float Character::getVerticalVelocity() const
{
    return velocityY;
}

float Character::getHorisontalVelocity() const
{
    return velocityX;
}

float Character::getPositionX() const
{
    return positionX;
}

float Character::getPositionY() const
{
    return positionY;
}

void Character::setPosition(const float x, const float y)
{
    positionX = x;
    positionY = y;
}

void Character::move(Direction dir)
{
    setDirection(dir);
    velocityX = velocityX + dir * moveSpeed;
    if(fabsf(velocityX) > maxSpeed) velocityX = dir * maxSpeed;
}

void Character::jump()
{
    setVerticalVelocity(jumpSpeed);
}

void Character::updatePosition()
{   

        velocityY += world->getGravity();
        positionY += velocityY;
        checkForGround();
        
        if(!isAlive())  return;

        checkForRoof();

        if(fabsf(velocityX) < stopSpeed)    velocityX = 0;
        else if(velocityX > 0)              velocityX -= stopSpeed;
        else                                velocityX += stopSpeed;
        positionX += velocityX; 
        checkForWall();
    
}

Character::Direction Character::getDirection() const
{
    return dir;
}

void Character::setDirection(Direction new_dir)
{
    if(dir != new_dir)  dir = new_dir;
}

bool Character::onGround() const
{
    return _onGround;
}

bool Character::isAlive() const
{
    return _isAlive;
}

float Character::leftBoundary() const
{
    return positionX;
}

float Character::rightBoundary() const
{
    return positionX + width;
}

float Character::topBoundary() const
{
    return positionY;
}

float Character::bottomBoundary() const
{
    return positionY + height;
}

void Character::kill()
{
    _isAlive = false;
}

//---------Privata funktioner---------------

int Character::bufferedRoundoff(float i) const
{
    //Om det inte finns några decimaler alls, ge samma ruta som vi står på
    if(i == (int)i) return i - 1;   
    else            return i;
}

int Character::left() const
{
    return positionX;
}
int Character::right() const
{
    return bufferedRoundoff(positionX + width);
}
int Character::top() const
{
    return positionY;
}
int Character::bottom() const
{
    return bufferedRoundoff(positionY + height);
}

void Character::checkForGround()
{
    if(positionY > world->bottomBoundary() - height)
    {
        _isAlive = false;
        return;
    }

    if( world->isSolidBlock(bottom(), left()) ||    //Kolla vänster hörn
        world->isSolidBlock(bottom(), right()))      //Kolla höger hörn
    {
        positionY = top();
        velocityY = 0;
        _onGround = true;
    }
    else    _onGround = false;
}

void Character::checkForRoof()
{
    if( world->isSolidBlock( top(), left() ) ||   //Kolla vänster hörn
        world->isSolidBlock( top(), right() ) )   //Kolla höger hörn
    {
        positionY = top() + 1;
        velocityY = -velocityY;
    }
}

void Character::checkForWall()
{

    //Kolla vänster världgräns
    if(positionX < world->leftBoundary())
    {
        positionX = world->leftBoundary();
        velocityX = 0;
    }

    //Kolla höger världsgräns
    if(positionX > world->rightBoundary() - width)
    {
        positionX = world->rightBoundary() - width;
        velocityX = 0;
    }

    auto isWall = [&](const float x)
    {
        for(int i = 0; i < height; i++)
            if(world->isSolidBlock(top() + i, x))
                return true;
        
        if(world->isSolidBlock(bottom(), x)) return true;
        return false;
    };

    //Kolla vänster
    if(isWall(left()))
    {
        positionX = left() + 1;
        velocityX = 0;
    }

    //Kollar höger
    if(isWall(right()))
    {
        positionX = right() - 1;
        velocityX = 0;
    }
}

