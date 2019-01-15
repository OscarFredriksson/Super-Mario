#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

template<typename Resource, typename Identifier>
class Resource_Holder
{
public:
    void load(Identifier id, const std::string& filename)
    {
        Resource temp;
        temp.loadFromFile(filename);
        resources.emplace(id, temp);
    }
    
    template<typename Param>
    void load(Identifier id, const std::string& filename, const Param& param)
    {
        Resource temp;
        temp.loadFromFile(filename, param);
        resources.emplace(id, temp);
    }

    Resource& get(Identifier id)
    {
        return resources[id];
    }

private:
    std::unordered_map<Identifier, Resource> resources;
};

#endif
