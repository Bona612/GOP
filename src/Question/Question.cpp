#include <cstdlib>
#include <iostream>
#include "Question.h"
#include "../Utils/Utils.h"

#define NUM_ANSWERS 4

using namespace std;

//struttura che serve per contenere le domande e le risposte
struct Question
{
    char text[100];
    char answers[NUM_ANSWERS][50];
    int correct;
};

Question questions[] = {
        {"Quanti scudetti ha vinto la Juventus?", {
            "36",
            "24",
            "34",
            "33"
            }, 2 },
        {"Quante Champions League ha vinto il Milan?", {
            "5",
            "7",
            "3",
            "2"
            }, 1},
        {"Dove gioca Cristiano Ronaldo dalla stagione 2018/2019?", {
            "Milan",
            "Juve Stabia",
            "Real Madrid",
            "Juventus"
            }, 3},
        {"Quanti mondiali ha vinto la nazionale Italiana?", {
            "4",
            "3",
            "5",
            "2"
            }, 0},
        {"Quale nazionale ha vinto piu' mondiali di calcio?", {
            "Brasile",
            "Germania",
            "Italia",
            "Argentina"
        	}, 0},
        {"Quale nazionale di calcio ha vinto il mondiale 2018?", {
            "Croazia",
            "Francia",
            "Brasile",
            "Belgio"
        	}, 1},
        {"Quale club di calcio ha vinto la UEFA Champions League nel 2018?", {
            "PSG",
            "Bayern Monaco",
            "Real Madrid",
            "Barcellona"
        	}, 2},
        {"Quale club di calcio ha vinto piu' UEFA Champions League?",{
            "Milan",
            "Liverpool",
            "Barcellona",
            "Real Madrid"
        	}, 3},
        {"Quale club di calcio ha vinto la UEFA Europa League nel 2018?",{
            "Manchester United",
            "Marsiglia",
            "Siviglia",
            "Atletico Madrid"
        	}, 3},
        {"Come si chiama l'attuale stadio di proprieta' della Juventus?",{
            "Alianz Stadium",
            "Olimpico di Torino",
            "Stadio Grande Torino",
            "Alianz Arena"
        	}, 0},
        {"Tra quali squadre viene giocata la partita detta 'Il Classico'?", {
            "Manchester United e Manchester City",
            "Juventus e Inter",
            "Barcellona e Real Madrid",
            "Napoli e Roma"
            }, 2},
        {"Quando si ricevono due cartellini gialli nella stessa partita si subisce un/una..", {
            "Ammonizione",
            "Espulsione",
            "Multa",
            "Cambio"
            }, 1},
        {"Quale nazionale di calcio ha vinto l'Europeo del 2016?", {
            "Francia",
            "Italia",
            "Germania",
            "Portogallo"
            }, 3},
        {"Quale di questi club di calcio gioca nel campionato brasiliano?", {
            "Palmeiras",
            "Boca Juniors",
            "Cruzeiro",
            "Racing Avellaneda"
            }, 0},
        {"La partita di calcio denominata 'Derby della Lanterna' si gioca tra quali squadre?", {
            "Sampdoria e Genoa",
            "Chievo Verona e Hellas Verona",
            "Pesaro e Fano",
            "Roma e Lazio"
            }, 0},
        {"Quale nazionale di calcio e' riuscita vincere il mondiale per due edizioni consecutive?", {
            "Italia",
            "Brasile",
            "Argentina",
            "Germania"
            }, 1},
        {"Quale club di calcio e' riuscito a vincere la UEFA Champions League per tre edizioni consecutive?", {
            "Milan",
            "Juventus",
            "Barcellona",
            "Real Madrid"
            }, 3},
        {"In quale club di calcio gioca il giocatore argentino Lionel Messi?", {
            "Manchester City",
            "PSG",
            "Real Madrid",
            "Barcellona"
            }, 3},
        {"E' passato alla storia per la famosa 'Mano de Dios'..", {
            "Maradona",
            "Messi",
            "Pele'",
            "Muller"
            }, 0},
        {"E' considerato come il rivoluzionario del modo di giocare che aveva proposto nel calcio italiano?", {
            "Carlo Ancelotti",
            "Arrigo Sacchi",
            "Jose' Mourinho",
            "Massimiliano Allegri"
            }, 1},
        {"E' stato l'allenatore che ha creato il Tiki-Taka..", {
        	"Maurizio Sarri",
			"Carlo Ancelotti",
			"Pep Guardiola",
			"Ernesto Valverde"
        }, 2},
        {"Quale nazionale di calcio ha vinto il mondiale nel 2006?", {
        	"Italia",
			"Francia",
			"Inghilterra",
			"Germania"
        }, 0}
};

int numQuestions = sizeof(questions) / sizeof(*questions);

//ritorna una domanda a caso tra quelle presenti
Question pickQuestion()
{
    return questions[rand() % numQuestions];
}

//ritorna il risultato della domanda, ovvero se è corretta o meno la risposta
bool getQuestionResult()
{
    Question question = pickQuestion();

    cout << question.text << endl << endl;
    for (int i = 0; i < NUM_ANSWERS; ++i)
    {
        cout << ((char)(i + 65)) << ". " << question.answers[i] << endl;
    }

    cout << endl;

    char answer = ' ';
    while (answer < 65 || answer >= 65 + NUM_ANSWERS)
    {

        cout << "Risposta: ";
        cin >> answer;

        if (cin.get() != '\n' && (answer < 65 || answer >= 65 + NUM_ANSWERS))
        {
        	clearCin();
        }
    }

    bool correct = answer-65 == question.correct;

    cout << "Risposta " << (correct ? getGreen() : getRed()) << (correct ? "esatta" : "sbagliata") << getReset() << "!" << endl;

    return correct;
}


