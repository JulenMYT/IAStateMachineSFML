#include "Game.h"

int main()
{
    Game* game = Game::GetInstance();
    game->Init();
    game->Run();
    return 0;
};