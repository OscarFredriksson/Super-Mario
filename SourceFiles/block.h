#ifndef BLOCK_H
#define BLOCK_H

#include <SFML/Graphics.hpp>
#include <string>
#include "sprite.h"
#include "game.h"

class Block: public Sprite, public Game
{
public:
    enum Type
    {
        //Byt INTE plats på dessa, ordningen motsvarar dess plats i texturfilen
        Brick,
        Stone,
        Empty,
        Question,
        Grass_Top,
        Grass_Left_Corner,
        Grass_Left,
        Dirt,
        Grass_Right,
        Grass_Right_Corner

        
    };
    
    Block(Type type, const int x, const int y); //, const int xPosInFile, const int yPosInFile);

    sf::Sprite getSprite() const;

private:
    static constexpr float scale = 1;

    sf::Texture texture;
    Sprite block;

    const std::string filename = "Textures/Blocks.png";
};

#endif