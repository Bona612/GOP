#include "QuestionCard.h"
#include "../Question/Question.h"
#include "ForwardCard.h"
#include "BackCard.h"

QuestionCard::QuestionCard() : Card()
{
    setText((char *)("Domanda: "));
}

//in base al risulato della domanda la carta si 'trasforma' (ne viene creata una nuova) in una positiva o negativa
void QuestionCard::effetto(Game *game)
{
    getQuestionResult() ? game->executeCard(new ForwardCard()) : game->executeCard(new BackCard()) ;
}

QuestionCard::~QuestionCard()
{
}
