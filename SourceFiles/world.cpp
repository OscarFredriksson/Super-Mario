#include "world.h"
#include "block.h"
#include <fstream>
#include <iostream>

void World::loadMap(std::string filename)
{
    std::ifstream file;
    file.open("Levels/Level-1.txt");
    if(!file.is_open())
    {
        std::cerr << "Kunde inte öppna filen..." << std::endl;
        return;
    }
    for(int i = 0; !file.eof(); i++)
    {   
        std::string str;
        file >> str;

        std::vector<Block*> row;

        for(int j = 0; j < str.length(); j++)
        {
            if(str[j] == 'X')   row.push_back(nullptr);
            else {
                Block::Type type;
                if(str[j] == '1')   type = Block::Brick;
                if(str[j] == '2')   type = Block::Question;
                if(str[j] == '3')   type = Block::Empty;
                if(str[j] == '4')   type = Block::Grass_Top;
                if(str[j] == '5')   type = Block::Grass_Left_Corner;
                if(str[j] == '6')   type = Block::Grass_Left;
                if(str[j] == '7')   type = Block::Dirt;
                if(str[j] == '8')   type = Block::Grass_Right;
                if(str[j] == '9')   type = Block::Grass_Right_Corner;

               row.push_back(new Block(type, j, i)); //map[j][i] = new Block(type, j, i);
            }
        }
        map.push_back(row);
    }

    file.close();
}

void World::draw(sf::RenderWindow& window)
{
    for(int i = 0; i < map.size(); i++)
        for(int j = 0; j < map[i].size(); j++)
            if(map[i][j] != nullptr)
                window.draw(map[i][j]->getSprite());
}