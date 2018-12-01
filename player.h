#include <SFML/graphics.hpp>

class Player
{
public:
    Player();
    
    sf::RectangleShape getSprite() const;

    void jump();

    void updatePosition();

private:
    const float height = 100.f;
    const float width = 50.f;

    float groundHeight = 400.f;

    float positionX = 400.f;
    float positionY = groundHeight;

    float velocityY = 0;

    float gravity = .5f;


    sf::RectangleShape body;
};