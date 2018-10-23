#include <iostream>
#include <cstring>
#include <iomanip>
#include "Game.h"
#include "../Dice/Dice.h"
#include "../Box/VoidBox.h"
#include "../Box/DrawCardBox.h"
#include "../Box/MoveBox.h"
#include "../Box/MissTurnBox.h"
#include "../Box/BackStartBox.h"
#include "../Box/StartBox.h"
#include "../Box/FinishBox.h"
#include "../Utils/Utils.h"
#include "../Card/Card.h"
#include "../Color/Color.h"

using namespace std;

#define N_COLUMNS 3
#define W_COLUMN 50


Game::Game()
{
    srand(time(NULL));

    startOutput();

    //inizializzazione di tutti i componenti del gioco
    createPlayers();
    createBillboard();
    deck = new Deck();
    dice = new Dice();
}

//metodo che esegue il gioco fino a che non finisce
void Game::startGame()
{
	while (!isFinish)
	{
		playerTurn();
	}
	endGame();
}

void Game::startOutput()
{
    cout << endl << "GOP - Gioco dell'oca - Tema Calcio" << endl;
    cout << "- Premi invio per confermare e proseguire!" << endl << endl;
}

//crea i giocatori
void Game::createPlayers()
{
    char name[50];
    char color[10];

    while (numPlayers < 2 || numPlayers > 6)
    {
        cout << "Numero di giocatori (da 2 a 6): ";
        cin >> numPlayers;
        cout << endl;
        if (numPlayers < 2 || numPlayers > 6)
        {
            cout << "Valore errato! ";
            clearCin();
        }
    }

    for(int i = 0; i < numPlayers; ++i)
    {
        cout << "Nome giocatore " << i+1 << ": ";
        cin >> name;

        color[0] = ' ' ;
        while(getCharColor(color) == -1)
        {
        	cout << "Colore giocatore " << i+1 << ": ";
        	cin >> color;
        	cout << endl;

        	if (getCharColor(color) == -1)
        	{
        		cout << "Colore non presente! ";
        		clearCin();
        	}
        }

        players[i] = new Player(name, getCharColor(color));
    }

    // Reset dello stream di input
    cin.get();
}

//creazione del tabellone
void Game::createBillboard()
{
	this->numBoxes = rand() % 61 + 40;
	boxes[0] = new StartBox();
	boxes[numBoxes - 1] = new FinishBox();
	int randInt = 0;

	for (int i = 1; i < numBoxes - 1; i++)
	{
		randInt = rand() % 100;

	    if (randInt < 15)
	    {
	    	boxes[i] = new VoidBox();
	    }
	    else if(randInt < 40)
	    {
	    	boxes[i] = new DrawCardBox();
	    }
	    else if(randInt < 60)
	    {
	    	boxes[i] = new MoveBox(rand() % 5 + 1);
	    }
	    else if(randInt < 80)
	    {
	    	boxes[i] = new MoveBox(-(rand() % 5 + 1));
	    }
	    else if(randInt < 95)
	    {
	    	boxes[i] = new MissTurnBox(1);
	    }
	    else
	    {
	    	boxes[i] = new BackStartBox();
	    }
	}
}

//turno di uno dei giocatori
void Game::playerTurn()
{
	cout << endl;
    separate();

    showBillboard();

    cout << endl;
    cout << "Turno di " << players[currPlayer]->getName()
         << " - Giocatore " << currPlayer + 1
         << " - Casella corrente: " << players[currPlayer]->getPos() << endl;

    pause();

    if (players[currPlayer]->isBlocked())
    {
        cout << getRed() << "Salta il turno" << getReset() << endl;
        pause();
    }
    else
    {
        throwDice();
    }

    currPlayer = nextPlayer();
}

//metodo che richiama il lancio del dado
void Game::throwDice()
{
    int score = dice->throwDice();

    cout << "Hai fatto " << score << endl;

    movePlayer(score);
}

//metodo che esegue l'operazione della casella su cui è arrivato il giocatore
void Game::executeBox()
{
    boxes[players[currPlayer]->getPos()]->effect(this);
}

//restituisce il giocatore successivo
int Game::nextPlayer()
{
    if (currPlayer == numPlayers - 1)
    {
        return 0;
    }

    return currPlayer + 1;
}

//restituisce il giocatore precedente
int Game::prevPlayer()
{
    if (currPlayer == 0)
    {
        return numPlayers - 1;
    }

    return currPlayer - 1;
}

//esegue lo spostamento del giocatore ed applica l'effeto della nuova casella
void Game::movePlayer(int movement)
{
	char s[50];

    int newPos = players[currPlayer]->getPos() + movement;

    if (newPos >= numBoxes)
    {
        newPos = (numBoxes - 1) - (newPos - (numBoxes - 1));
    }
    if (newPos < 0)
    {
        newPos = 0;
    }

    players[currPlayer]->setPos(newPos);

    add_color(s, boxes[players[currPlayer]->getPos()]->getText(), boxes[players[currPlayer]->getPos()]->getColor());
    cout << endl << "Casella " << players[currPlayer]->getPos() << ": " << s;

    pause();

    executeBox();
}

//pesca una carta dal mazzo
void Game::drawCard()
{
    executeCard(deck->drawCard());
}

//manda a video il testo della carta ed esegue l'operazione della carta
void Game::executeCard(Card* card)
{
    cout << endl << "Carta: " << card->getText();

    pause();

    card->effetto(this);
}

//salta turno/i
void Game::missTurn(int turns)
{
    players[currPlayer]->setNumTurns(turns);
}

//torna alla partenza
void Game::backStart()
{
    players[currPlayer]->setPos(0);
}

//tira ancora
void Game::throwAgain()
{
    throwDice();
}

//cambia la posizione del giocatore attuale con uno tra quello precedente o quello successivo
void Game::switchPosition(int p)
{
	char s[50];

    if (numPlayers < 2)
    {
        return;
    }

    int posPlayer = players[currPlayer]->getPos();
    int posPlayer2 = players[(p == 1 ? nextPlayer() : prevPlayer())]->getPos();
    players[currPlayer]->setPos(posPlayer2);
    players[nextPlayer()]->setPos(posPlayer);

    add_color(s, boxes[players[currPlayer]->getPos()]->getText(), boxes[players[currPlayer]->getPos()]->getColor());
    cout << endl << "Sei finito nella casella " << players[currPlayer]->getPos() << ": " << s << endl;

    executeBox();
}

//casella arrivo
void Game::finish()
{
    isFinish = true;
}

//metodo che mostra dove i giocatori si trovano al momento mandando in output un asterisco colorato
void Game::show_players_position(char* c, const int pos)
{
    for (int i = 0; i < numPlayers; i++)
    {
        if (players[i]->getPos() == pos)
        {
            if (c[0] == '\0')
            {
                add_color(c, (char *)("*"), players[i]->getColorPlayer());
            }
            else
            {
                add_const_color(c, (char *)("*"), players[i]->getColorPlayer());
            }
        }
        else if (c[0] == '\0')
        {
            add_color(c, (char *)(" "), players[i]->getColorPlayer());
        }
        else
        {
            add_const_color(c, (char *)(" "), players[i]->getColorPlayer());
        }

        (i == (numPlayers - 1)) ? strcat(c, (char *)(" ")) : strcat(c, (char *)(""));
    }
}


//metodo che restituisce in output il tabellone da gioco
void Game::showBillboard()
{
    char box[50];
    char c[50];
    c[0] = '\0';

    int r = (numBoxes % N_COLUMNS == 0) ? 0 : 1;
    int n = numBoxes / N_COLUMNS + r;

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < N_COLUMNS; j++)
        {
            int pos = i + j * n;
            if (pos >= numBoxes)
            {
            	continue;
            }

            add_color(box, boxes[pos]->getText(), boxes[pos]->getColor());
            this->show_players_position(c,pos);

            cout << (j > 0 ? "| " : " ");
            cout << right << setfill(' ') << setw(numPlayers) << c;
            cout << right << setw(2) << pos << '.' << left << setfill(' ') << setw(W_COLUMN) << box;

            c[0] = '\0';
        }
        cout << endl;
    }
}

//output finale
void Game::endGame()
{
    currPlayer = prevPlayer();

    separate();
    showBillboard();
    cout << endl;

    for(int i = 0; i < numPlayers; ++i)
    {
        cout << "Giocatore " << i+1 << ". " << players[i]->getName()
             << " - Casella " << players[i]->getPos() << endl;
    }

    cout << endl << "Vince il giocatore " << currPlayer+1 << ". " << players[currPlayer]->getName() ;
}

Game::~Game()
{
}
