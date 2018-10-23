#ifndef GAME_GAME_H_
#define GAME_GAME_H_

#include "..\Player\Player.h"
#include "..\Box\Box.h"
#include "..\Deck\Deck.h"
#include "..\Dice\Dice.h"

class Box;

class Game
{
    Player *players[10];
    Box *boxes[100];
    Deck *deck;
    Dice *dice;
    bool isFinish = false;

    int numPlayers = 0;
    int currPlayer = 0;
    int numBoxes = 0;

    void startOutput();

    void createPlayers();
    void createBillboard();
    void checkSquares();

    void playerTurn();
    void throwDice();
    void executeBox();

    int nextPlayer();
    int prevPlayer();

    void endGame();

public:

    Game();
    void startGame();
    void movePlayer(int movement);
    void drawCard();
    void executeCard(Card* card);
    void missTurn(int turns);
    void backStart();
    void throwAgain();
    void switchPosition(int p);
    void finish();
    void show_players_position(char* c, const int pos);
    void showBillboard();
    ~Game();
};

#endif /* GAME_GAME_H_ */
