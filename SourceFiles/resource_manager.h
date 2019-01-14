#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class Resource_Manager
{
public:
    static void loadTexture(const std::string& path, const std::string& key, const sf::IntRect& area = sf::IntRect());

    static sf::Texture& getTexture(const std::string& key);

private:
    inline static std::map<std::string, sf::Texture> textures; 

};

#endif