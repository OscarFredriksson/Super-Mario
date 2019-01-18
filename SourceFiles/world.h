#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "block.h"
#include <memory>

//! Skapar en värld med given gravitation. Världen håller alla block i omgivningen
/*!
    
*/
class World
{
public:

    //!Konstruera en värld med given gravitation
    World(const float gravity);

    //!Laddar in en bana från en given fil, se Level-1.txt för format
    void loadMap(std::string filename); 

    //!Ritar ut världen på ett givet fönster
    void draw(sf::RenderWindow& window);    

    //!Världens vänstra gräns
    int leftBoundary() const;   

    //!Världens högra gräns
    int rightBoundary() const;  

    //!Världens övre gräns
    int topBoundary() const;    

    //!Världens nedre gräns
    int bottomBoundary() const; 
    
    //!Kollar om ett block på en given koordinat går att gå igenom eller inte
    bool isSolidBlock(const int x, const int y) const;  

    //!Kollar om Mario har nått målet, skicka in hans x värde
    bool reachedFinish(const int x) const;  

    //!Hämtar världens gravitation
    float getGravity() const;  

private:
    std::vector<std::vector<std::unique_ptr<Block>>> map;

    const float gravity;

    int finishLine;

};

#endif