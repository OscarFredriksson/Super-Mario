#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include "sprite.h"
#include "resource_holder.h"

class Block
{
public:
    enum Type   //Olika typer av block, ordningen motsvarar dess plats i texturfilen
    {
        Brick, /**< 1D */
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
    
    Block(Type type, const int x, const int y); //Konstruera ett block med en given typ och på en given koordinat

    void draw(sf::RenderWindow& window);    //Rita ut ett block på givet fönster

private:
    const std::string texture_path = "Textures/Blocks.png";

    Resource_Holder<sf::Texture, Type> textures;

    Sprite sprite;
};

#endif