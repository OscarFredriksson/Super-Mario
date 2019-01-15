#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "animated_sprite.h"
#include "resource_manager.h"

class Enemy: public Character
{
public:
    Enemy(const int x, const int y, World& world);

    void updatePosition() override;

    void draw(sf::RenderWindow& window) override;

    sf::Sprite getSprite() const override
    {
        return sprite;
    }


private:
    static const int height = 1;
    static const int width = 1;

    const float moveSpeed = .04f;

    const std::string texture_path = "Textures/Goomba.png";
    Resource_Holder<sf::Texture, std::string> textures;
    
    AnimatedSprite sprite;

    void flip();

};

#endif