#ifndef CHARACTER_H
#define CHARACTER_H

#include "world.h"
#include "animated_sprite.h"
#include "sound.h"
#include <string>


class Character
{
public:
    Character(const int width, const int height, const std::shared_ptr<World>& world);  //Konstruera en karaktär, med given höjd och bredd, samt skicka in vilken värd karaktären är i

    void setJumpSpeed(const float value);   //Sätter hur högt karaktären hoppar. (default är 0, alltså att han inte kan hoppa alls)

    void setMoveSpeed(const float value);   //Sätter hur fort karaktären rör sig, denna kan även ses som karaktärens acceleration

    void setMaxSpeed(const float value);    //Sätter karaktärens maxfart, karaktären kan inte gå snabbare än denna

    void setStopSpeed(const float value);   //Sätter hur snabbt karaktären stannar när han inte längre ges en hastighet i horisontell riktning

    void setVerticalVelocity(const float value);    //Ger karaktären en vertikal hastighet med givet värde
    
    void setHorisontalVelocity(const float value);  //Ger karaktären en horisontell hastighet med givet värde

    void setVelocity(const sf::Vector2f _velocity); //Ger karaktären en hastighet med given 2d-vektor

    sf::Vector2f getVelocity() const;   //Hämta karaktärens hastighet

    sf::Vector2f getPosition() const;   //Hämta karaktärens position

    void setPosition(const sf::Vector2f _position); //Sätt karaktärens position

    virtual sf::Sprite getSprite() const = 0;   //Hämta sprite från barnklass

    virtual void draw(sf::RenderWindow& window) = 0;    //Rita ut sprite från barnklass

    
    enum Direction  //Vilket håll karaktären går åt
    {
        Left = -1,
        Right = 1
    };

    virtual void move(Direction dir);   //Flytta karaktären åt givet håll

    virtual void jump();    //Sätter vertikal hastighet till hopphastigheten

    virtual void updatePosition();  //Uppdatera karaktärens position (justerar karaktärens position utifrån dess hastighet)

    Direction getDirection() const;
    
    virtual void setDirection(Direction dir);

    bool onGround() const;

    bool isAlive() const;

    float leftBoundary() const;

    float rightBoundary() const;

    float topBoundary() const;

    float bottomBoundary() const;

    void kill();

private:

    void checkForGround();

    void checkForRoof();

    void checkForWall();

    int bufferedRoundoff(float i) const;

    int left() const;

    int right() const;

    int top() const;

    int bottom() const;


    //-----Variabler och konstanter------------
    
    const std::shared_ptr<World> world;

    const int height;
    const int width;

    bool _onGround = false;

    float jumpSpeed = 0;
    float moveSpeed = 0;
    float maxSpeed = 0;
    float stopSpeed = 0;

    sf::Vector2f velocity = {0, 0};
    sf::Vector2f position = {10.f, 2.f};

    Direction dir = Right;

    bool _isAlive = true;

};

#endif