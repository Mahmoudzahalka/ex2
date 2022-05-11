#include "Player.h"
#include "utilities.h" 



const int numberOfVariables = 6;

Card::Card(CardType type, const CardStats& stats):
m_effect(type),
m_stats(stats)     //copy by value 
{
    if(m_stats.force<0)         //need something better than if maybe external function
    {
        m_stats.force=0;
    }
    if(m_stats.hpLossOnDefeat<0)
    {
        m_stats.hpLossOnDefeat=0;
    }
    if(m_stats.cost<0)
    {
        m_stats.cost=0;
    }
    if(m_stats.heal<0)
    {
        m_stats.heal=0;
    }
    if(m_stats.buff<0)
    {
        m_stats.buff=0;
    }
    if(m_stats.loot<0)
    {
        m_stats.loot=0;
    }
}
      


void Card::applyEncounter(Player& player) const
{
    if(m_effect == Battle)
    {                              //using getters because sadot are private 
        if(player.getAttackStrength() >= m_stats.force)          // to use -> or . ?
        {
            player.levelUp();
            player.addCoins(m_stats.loot);
            printBattleResult(true);
        }
        else 
        {
        player.damage(m_stats.hpLossOnDefeat); //check if dead. return may not be neccesary 
        printBattleResult(false);
        }
    }
    if(m_effect == Buff)
    {
        if(player.pay(m_stats.cost))
        {
            player.buff(m_stats.buff);
        }
    }
    if(m_effect == Heal)
    {
        if(player.pay(m_stats.cost))
        {
            player.heal(m_stats.buff);
        }
    }
    if(m_effect == Treasure)
    {
        player.addCoins(m_stats.loot);
    }  
}


void Card::printInfo() const
{
    std::cout << "Card drawn:" << endl;
    std::cout << "Type:" << m_effect << endl;
    if(m_effect == Battle)
    {
        printBattleCardInfo(m_stats);
    }
    /*else
    {
       // std::cout << "Force: 0 " << endl;
    }*/
    if(m_effect == Buff)
    {
        printBuffCardInfo(m_stats);
        //std::cout << "Damage taken (on loss): 0 " << endl;
    }
    if(m_effect == Heal)
    {
        printHealCardInfo(m_stats);
        //std::cout << "Damage taken (on loss): 0 " << endl;
    }
    if(m_effect == Treasure)
    {
        printTreasureCardInfo(m_stats);
        //std::cout << "Damage taken (on loss): 0 " << endl;
    }
}
