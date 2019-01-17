#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <cassert>

template<typename Resource, typename Identifier>
class Resource_Holder
{
public:
    void load(Identifier id, const std::string& path)
    {
        std::unique_ptr<Resource> resource(new Resource());
        if(!resource->loadFromFile(path))
            throw std::runtime_error("Failed to load " + path);

        resources.emplace(id, std::move(resource));
    }
    
    template<typename Param>
    void load(Identifier id, const std::string& path, const Param& param)
    {
        std::unique_ptr<Resource> resource(new Resource());
        if(!resource->loadFromFile(path, param))
            throw std::runtime_error("Failed to load " + path);
        
        resources.emplace(id, std::move(resource));
    }

    Resource& get(Identifier id)
    {
        return *resources[id];
    }

private:
    std::unordered_map<Identifier, std::unique_ptr<Resource>> resources;
};

#endif
