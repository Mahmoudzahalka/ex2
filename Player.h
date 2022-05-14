#ifndef EX2_PLAYER_H
#define EX2_PLAYER_H

#include <string>
//#include "Mtmchkin.h"

class Player {
private:
   std::string m_name;   //may be probmlematic in advance copy c'tor
   int m_level;
   int m_force;
   int m_maxHp;
   int m_hp ;
   int m_coins;
   friend class Mtmchkin;

public:
    Player(const char* name, int maxHp = 100, int force = 5);
    Player(const Player& copiedPlayer)=default;
    ~Player()=default;
    void printInfo();
    void levelUp();
    int getLevel();
    void buff(int extraForce);
    void heal(int extraHp);
    void damage(int hpDamage);
    bool isKnockedOut();
    void addCoins(int coins);
    bool pay(int value);
    int getAttackStrength();
    
};


#endif //EX2_PLAYER_H