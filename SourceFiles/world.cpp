#include "world.h"
#include "block.h"
#include <fstream>
#include <iostream>

World::World(const float gravity):
        gravity(gravity)
{}

void World::loadMap(std::string filename)
{
    std::ifstream file;
    file.open(filename);
    if(!file.is_open())
    {
        std::cerr << "Kunde inte öppna filen..." << std::endl;
        return;
    }
    for(int i = 0; !file.eof(); i++)
    {   
        std::string read_row;
        file >> read_row;

        std::vector<std::unique_ptr<Block>> map_row;

        for(int j = 0; j < read_row.length(); j++)
        {
            Block::Type type;
            
            switch(read_row[j])
            {
                case 'F':   finishLine = j;
                case '-':   map_row.push_back(nullptr);
                            continue;       
                case '1':   type = Block::Brick;
                            break;
                case '2':   type = Block::Question;
                            break;
                case '3':   type = Block::Empty;
                            break;
                case '4':   type = Block::Grass_Top;
                            break;
                case '5':   type = Block::Grass_Left_Corner;
                            break;
                case '6':   type = Block::Grass_Left;
                            break;
                case '7':   type = Block::Dirt;
                            break;
                case '8':   type = Block::Grass_Right;
                            break;
                case '9':   type = Block::Grass_Right_Corner;
                            break;
                case 'A':   type = Block::Pipe_Top_Left;
                            break;
                case 'B':   type = Block::Pipe_Top_Right;
                            break;
                case 'C':   type = Block::Pipe_Left;
                            break;
                case 'D':   type = Block::Pipe_Right;
                            break;
                default:    break;
            }

            map_row.emplace_back(std::make_unique<Block>(type, j, i)); 
            
        }
        map.push_back(std::move(map_row));
    }

    file.close();
}

void World::draw(sf::RenderWindow& window)
{
    std::for_each(map.begin(), map.end(), [&window](const std::vector<std::unique_ptr<Block>>& row)
    {
        std::for_each(row.begin(), row.end(), [&window](const std::unique_ptr<Block>& block)
        {
            if(block)    block->draw(window);
        });
    });
}

int World::leftBoundary() const
{
    return 0;
}

int World::rightBoundary() const
{
    return map[0].size();
} 

int World::topBoundary() const
{
    return 0;
}

int World::bottomBoundary() const
{
    return map.size();
}

bool World::isSolidBlock(const int x, const int y) const
{
    return map[x][y] != nullptr;
}

bool World::reachedFinish(const int x) const
{
    return x > finishLine;
}

float World::getGravity() const
{
    return gravity;
}