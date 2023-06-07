#include <iostream>
#include "Player.h"
#include "Game.h"
int main()
{
    Player player("Stanislav", "test", 19, 2000);

    Game game;

    game.Play(player);
}
