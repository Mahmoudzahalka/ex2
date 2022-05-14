#include "Mtmchkin.h"
#include "Card.h"
#include "Player.h"
#include <string>


const int MAX_LEVEL = 10;

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards) :player(playerName),deckSize(numOfCards),
currentCard(-1),currentGameStatus(GameStatus::MidGame)
{
   deck = new Card[numOfCards];
   for ( int i=0; i<numOfCards; ++i)
   {
      deck[i]=cardsArray[i];
   }
}

//-- importedc from CLion

Mtmchkin::Mtmchkin(const Mtmchkin& copiedMtmchkin) : player(copiedMtmchkin.player.m_name.c_str(), copiedMtmchkin.player.m_maxHp,
 copiedMtmchkin.player.m_force),deckSize(copiedMtmchkin.deckSize),deck(new Card[copiedMtmchkin.deckSize]) 

{
   for ( int i=0; i<(this->deckSize) ; ++i)
   {
      deck[i]= copiedMtmchkin.deck[i];
   }
   player=copiedMtmchkin.player;     //assignment operator for player
   currentGameStatus=copiedMtmchkin.currentGameStatus;
   currentCard=copiedMtmchkin.currentCard; 
}

Mtmchkin::~Mtmchkin()
{
   delete[] deck;
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& a)
{
    if (this==&a)
    {
        return *this;
    }
    delete[] deck;
    deck = new Card[a.deckSize];
    deckSize = a.deckSize;
    for ( int i=0; i<deckSize ; ++i)
    {
        deck[i]=a.deck[i];
    }
    player = a.player;   //check copy c'tor for player
    currentCard=a.currentCard;
    currentGameStatus=a.currentGameStatus;
    return *this;
}



//----- imported from CLion





GameStatus Mtmchkin::getGameStatus() const
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
   deck[currentCard].applyEncounter(this->player);
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

bool Mtmchkin::isOver() const 
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


