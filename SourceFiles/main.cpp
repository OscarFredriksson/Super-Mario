#include "game.h"
#include <string>

int main()
{
    const std::string title = "Super Mario";
    const int width = 640;
    const int height = 480;

    Game game(width, height, title);

    game.run();
    
    return 0;
}