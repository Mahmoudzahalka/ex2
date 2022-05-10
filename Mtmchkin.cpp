#include "Mtmchkin.h"
#include "Card.h"
#include "Player.h"


const int MAX_LEVEL = 10;

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :
currentGameStatus(MidGame), player(playerName), deckSize(numOfCards), currentCard(-1)
{
   for ( int i=0; i<numOfCards; ++i)    
   {
      deck[i]=cardsArray[i]; //check again what constructor is called for deck and who does operator = work 
   }
}


GameStatus Mtmchkin::getGameStatus()
{
   return currentGameStatus;
}


void Mtmchkin::playNextCard()
{
   if(currentCard<deckSize-1)
   {
      currentCard++;
   }
   else if (currentCard==deckSize-1)
   {
      currentCard=0;
   }
   deck[currentCard].printInfo();
   deck[currentCard].applyEncounter();
   if (player.getLevel()==MAX_LEVEL)    
   {
      currentGameStatus = GameStatus::Win;
   }
   if (player.isKnockedOut())
   {
      currentGameStatus = GameStatus::Loss;
   }
   player.printInfo();

}

bool Mtmchkin::isOver() 
{
   if ((*this).getGameStatus()==GameStatus::Win)
   {
      return true;
   }
   else
   {
      return false;
   }
}


