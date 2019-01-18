#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <cassert>


//! Typparametriserad resurshållare
/*!
    Håller resurser av en specifik typ. Ser till att dessa endast läses in i minnet en gång för att inte 
    spara överflödiga resurser. 
*/
template<typename Resource, typename Identifier>
class Resource_Holder
{
public:
    //! Laddar in en resurs till resurshållaren
    /*!
        @param id       Vilket ID den nya resursen ska få, används sedan för att hämta resursen
        @param path     Filvägen till resursen som ska läsas in

        Om resurshanteraren misslyckas läsa in från filen (t.ex för att filvägen inte finns) kastar funktionen
        ett undantag. Load-funktionen bör alltså alltid omges av en try-catch. 

        @code
        try { resource_manager.load(id, path); } 
        catch(const std::runtime_error e) { //Hantera felet }
        @endcode
    */
    void load(Identifier id, const std::string& path)
    {
        std::unique_ptr<Resource> resource(std::make_unique<Resource>());   //Skapa en ny resurs
        
        if(!resource->loadFromFile(path))   //Läs in resursen från filvägen
            throw std::runtime_error("Failed to load " + path); //Om den misslyckas, kasta exception

        resources.emplace(id, std::move(resource)); //Flytta in resursen i behållaren
    }
    
    //! Laddar in en resurs till resurshållaren med en parameter för t.ex sf::IntRect om det laddas en textur.
    /*!
        @param id       Vilket ID den nya resursen ska få, används sedan för att hämta resursen
        @param path     Filvägen till resursen som ska läsas in
        @param param    En Tredje parameter till inläsningen, t.ex sf::IntRect om en textur läses in  

        Om resurshanteraren misslyckas läsa in från filen (t.ex för att filvägen inte finns) kastar funktionen
        ett undantag. Load-funktionen bör alltså alltid omges av en try-catch. 

        @code
        try { resource_manager.load(id, path, param); } 
        catch(const std::runtime_error e) { //Hantera felet }
        @endcode
    */
    template<typename Param>
    void load(Identifier id, const std::string& path, const Param& param = Param())
    {
        std::unique_ptr<Resource> resource(std::make_unique<Resource>());   //Skapa en ny resurs

        if(!resource->loadFromFile(path, param))    //Läs in resursen från filvägen
            throw std::runtime_error("Failed to load " + path); //Om den misslyckas, kasta exception
        
        resources.emplace(id, std::move(resource)); //Flytta in resursen i behållaren
    }


    //! Hämta en resurs från resurshållaren  
    /*!
        @param[in] id   Id't för den resurs som ska hämtas
        @param[out] Resource&   Returnerar en referens till den sökta resursen
        Om ett felaktigt ID ges kommer en tom resurs returneras
    */
    Resource& get(Identifier id)
    {
        return *resources[id];  //Hitta elementet och avreferera det
    }

private:
    std::unordered_map<Identifier, std::unique_ptr<Resource>> resources;
};

#endif
