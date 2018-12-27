#include "character.h"
#include <iostream>
#include <cmath>

Character::Character(World& world, const int width, const int height):
    world(world),
    width(width),
    height(height)
{}

void Character::move(Direction dir)
{
    setDirection(dir);
    velocityX = velocityX + dir * moveSpeed;
    if(fabsf(velocityX) > maxSpeed) velocityX = dir * maxSpeed;
}

void Character::updatePosition()
{   
    velocityY += world.getGravity();
    positionY += velocityY;

    checkForGround();

    std::cout << velocityY << " " << positionY << std::endl;

    checkForRoof();

    velocityX *= stopSpeed;  //Sänk hastigheten för att tillslut stanna
    positionX += velocityX; 
    checkForWall(); 
}


//---------------Privata funktioner----------------

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
    bool foundGround = false;

    if( world.isSolidBlock(bottom(), left()) ||    //Kolla vänster hörn
        world.isSolidBlock(bottom(), right()))      //Kolla höger hörn
    {
        positionY = top();
        foundGround = true;
        velocityY = 0;

        if(!_onGround)
        {
            std::cout << "Landade" << std::endl;
            _onGround = true;
        }
    }
    if(!foundGround)    _onGround = false;
}

void Character::checkForRoof()
{
    if( world.isSolidBlock( top(), left() ) ||   //Kolla vänster hörn
        world.isSolidBlock( top(), right() ) )   //Kolla höger hörn
    {
        positionY = top() + 1;
        velocityY = -velocityY;
    }
}

void Character::checkForWall()
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

    auto isWall = [&](const float x)
    {
        for(int i = 0; i < height; i++)
            if(world.isSolidBlock(top() + i, x))
                return true;
        
        if(world.isSolidBlock(bottom(), x)) return true;
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

void Character::setDirection(Direction new_dir)
{
    if(dir != new_dir)  dir = new_dir;
}