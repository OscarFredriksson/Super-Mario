#include "character.h"
#include <iostream>
#include <cmath>

Character::Character( const int width, const int height, const std::shared_ptr<World>& world):
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
    velocity.y = value;
}

void Character::setHorisontalVelocity(const float value)
{
    velocity.x = value;
}

void Character::setVelocity(const sf::Vector2f _velocity)
{
    velocity = _velocity;
}

sf::Vector2f Character::getVelocity() const
{
    return velocity;
}

sf::Vector2f Character::getPosition() const
{
    return position;
}

void Character::setPosition(const sf::Vector2f _position)
{
    position = _position;
}

void Character::move(Direction dir)
{
    setDirection(dir);
    velocity.x = velocity.x + dir * moveSpeed;
    
    if(fabsf(velocity.x) > maxSpeed) velocity.x = dir * maxSpeed;
}

void Character::jump()
{
    setVerticalVelocity(jumpSpeed);
}

void Character::updatePosition()
{   

        velocity.y += world->getGravity();
        position.y += velocity.y;
        checkForGround();
        
        if(!isAlive())  return;

        checkForRoof();

        if(fabsf(velocity.x) < stopSpeed)    velocity.x = 0;
        else if(velocity.x > 0)              velocity.x -= stopSpeed;
        else                                velocity.x += stopSpeed;
        position.x += velocity.x;
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
    return position.x;  //positionX;
}

float Character::rightBoundary() const
{
    return position.x + width;  //positionX + width;
}

float Character::topBoundary() const
{
    return position.y;  //positionY;
}

float Character::bottomBoundary() const
{
    return position.y + height; //positionY + height;
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
    return position.x;  //positionX;
}
int Character::right() const
{
    return bufferedRoundoff(position.x + width);    //positionX + width);
}
int Character::top() const
{
    return position.y;   //positionY;
}
int Character::bottom() const
{
    return bufferedRoundoff(position.y + height);    //positionY + height);
}

void Character::checkForGround()
{
    //if(positionY > world->bottomBoundary() - height)
    if(position.y > world->bottomBoundary() - height)
    {
        _isAlive = false;
        return;
    }

    if( world->isSolidBlock(bottom(), left()) ||    //Kolla vänster hörn
        world->isSolidBlock(bottom(), right()))      //Kolla höger hörn
    {
        position.y = top();
        velocity.y = 0;
        _onGround = true;
    }
    else    _onGround = false;
}

void Character::checkForRoof()
{
    if( world->isSolidBlock( top(), left() ) ||   //Kolla vänster hörn
        world->isSolidBlock( top(), right() ) )   //Kolla höger hörn
    {
        position.y = top() + 1;
        velocity.y = -velocity.y;
    }
}

void Character::checkForWall()
{

    //Kolla vänster världgräns
    if(position.x < world->leftBoundary())
    {
        position.x = world->leftBoundary();
        velocity.x = 0;
    }

    //Kolla höger världsgräns
    if(position.x > world->rightBoundary() - width)
    {
        position.x = world->rightBoundary() - width;
        velocity.x = 0;
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
        position.x = left() + 1;
        velocity.x = 0;
    }

    //Kollar höger
    if(isWall(right()))
    {
        position.x = right() - 1;
        velocity.x = 0;
    }
}

