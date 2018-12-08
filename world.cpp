#include "world.h"
#include "Blocks/ground_block.h"
#include "Blocks/brick_block.h"
#include "Blocks/ground_block.h"
#include "fstream"
#include "iostream"
#include "string"

World::World()
{
    fillMap();

    std::ifstream file;
    file.open("map.txt");
    if(!file.is_open())
    {
        std::cerr << "Kunde inte öppna filen..." << std::endl;
        return;
    }
    for(int i = 0; !file.eof(); i++)
    {   
        std::string str;
        file >> str;

        std::cout << str << std::endl;

        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] == '1')   map[j][i] = new Brick_Block(j, i);
            //if(str[j] == '2')   map[j][i] = new Question_Block(j, i);
            if(str[j] == '4') map[j][i] = new Ground_Block(j, i);
        }   
    }
    file.close();


    //map[1][11] = new Brick_Block(1, 11);
    //map[2][12] = new Ground_Block(2, 12);
    //map[3][12] = new Ground_Block(3, 12);

    

}

float World::getWidth()
{
    //return width;
}

float World::getHeight()
{
    //return height;
}

float World::draw(sf::RenderWindow& window)
{
    for(int i = 0; i < width; i++)
        for(int j = 0; j < height; j++)
            if(map[i][j] != nullptr)
                window.draw(map[i][j]->getSprite());
}