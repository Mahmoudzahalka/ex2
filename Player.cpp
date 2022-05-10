#include "Player.h"

const int FIVE = 5;
const int MAX_HEALTH_DEFAULT = 100;

Player::Player(const char* name, int maxHp = MAX_HEALTH_DEFAULT , int force = FIVE ) :  
     m_name(name),
     m_level(1),
     m_coins(0)
{
     if (force>0)
     {
     m_force(force);
     }
     else 
     {
          m_force(FIVE);
     }
     if (maxHp>0)
     {
     m_maxHp(maxHp);
     m_hp(maxHp);
     }
     else 
     {
          m_maxHp(MAX_HEALTH_DEFAULT);
          m_hp(MAX_HEALTH_DEFAULT);
     }
}

Player::Player(const Player& copiedPlayer):
     m_name(copiedPlayer.m_name),       //check again 
     m_level(copiedPlayer.m_level),
     m_force(copiedPlayer.m_force),
     m_maxHp(copiedPlayer.m_maxHp),
     m_hp(copiedPlayer.m_maxHp),
     m_coins(copiedPlayer.m_coins)
{}


void Player::printInfo()
{
     std::cout << "Player Details:" << endl;
     printPlayerInfo(m_name, m_level, m_force, m_hp, m_coins);
}


void Player::levelUp()
{
     if(m_level>=0 && m_level<10)
     {
          m_level++;
     }
}


int Player::getLevel()
{
    if(m_level>=0 && m_level<=10)
    {
         return m_level;
     }
     return -1;
}


void Player::buff(int const extraForce)
{
     if (extraForce>0)
     {
     m_force += extraForce;     
     }                          
}


void Player::heal(int const extraHp)
{
     if (extraHp<=0)
     {
          return;
     }
     if((m_hp+extraHp)>m_maxHp)                            
     {
          m_hp = m_maxHp;
     }
     else
     {
          m_hp += extraHp;
     }
}


void Player::damage(int const hpDamage)
{
     if (hpDamage<=0)            //added if 
     {
          return;
     }
     if(m_hp-hpDamage<0)
     {
          m_hp = 0;
     }
     else
     {
         m_hp -= hpDamage;
     }
}


  bool Player::isKnockedOut()
  {
     if(m_hp)
     {
          return false;
     }
     return true;
  }


void Player::addCoins(int const coins) //bdekat kelet
{
     if (coins>0)
     {
     m_coins += coins;
     }
}


 bool Player::pay(int const value)
 {
      if (value<0)
      {
          return true;           //true or false
      }
     if(m_coins >= value)
     {
          m_coins = m_coins-value;
          return true;
     }
     return false;
 }


  int Player::getAttackStrength()
  {
     int attackStrength = m_level + m_force;
     return attackStrength;
  }