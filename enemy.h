#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include "character.h"
#include <memory>
#include "player.h"




class Enemy : public Character {
    protected:
    bool isHostile; // used to check wheather enemy is hostile to PC
    bool isMoveable; // used to check wheather enemy is moveable;
    int goldNum; // indicate the number of the gold that enemy have : '1' = default  '4' = merchant 
                 // note: slain the dragon will not drop gold
    public:
    // constr
    ////////////

    // accessor
    bool getIsHostile();
    bool getGoldNum();

    // Fun 
    void changeHostile();
    void move();
    void attack(std::shared_ptr<Player> &PC);
};


class Vampire : public Enemy {

};

class Werewolf : public Enemy {

};

class Troll : public Enemy {

};

class Goblin : public Enemy {
    
};

class Merchant : public Enemy {

};

class Phoenix : public Enemy {

};

class Dragon : public Enemy {

};
#endif
