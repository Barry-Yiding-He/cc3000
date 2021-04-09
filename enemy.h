#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>




class Enemy : public Character {
    private:
    bool isHostile; // used to check wheather enemy is hostile to PC
    int goldNum; // indicate the number of the gold that enemy have : '1' = default  '4' = merchant 
                 // note: slain the dragon will not drop gold
    public:
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
