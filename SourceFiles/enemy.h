#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "animated_sprite.h"
#include "resource_holder.h"

class Enemy: public Character
{
public:
    Enemy(const sf::Vector2f position, const std::shared_ptr<World>& world);

    void updatePosition() override;

    void draw(sf::RenderWindow& window) override;

    sf::Sprite getSprite() const override;

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