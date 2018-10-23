#include "../src/Game/Game.h"

//creazione del gioco e richiamo del metodo che lo fa partire
int main()
{
    Game *game = new Game();
    game->startGame();
    return 0;
}
