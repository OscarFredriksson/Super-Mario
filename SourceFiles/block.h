#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include "sprite.h"

class Block
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
        Grass_Right_Corner,
        Pipe_Top_Left,
        Pipe_Top_Right,
        Pipe_Left,
        Pipe_Right
    };
    
    Block(Type type, const int x, const int y);

    void draw(sf::RenderWindow& window);

private:
    const std::string texturePath = "Textures/Blocks.png";

    Sprite block;
};

#endif