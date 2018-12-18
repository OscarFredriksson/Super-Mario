#include "animated_sprite.h"


void AnimatedSprite::update() const
{
    auto now = clock::now();

    std::chrono::duration<double> duration = now - start;
    if(duration.count() > speed)
    {
        int x = getTextureRect().left;

        //getTexture().setTextureRect(sf::IntRect(0, 0, 16, 32));


    }
}    


void AnimatedSprite::setTexture(const sf::Texture& in_texture)
{
    texture = in_texture;
    setTexture(texture);
}