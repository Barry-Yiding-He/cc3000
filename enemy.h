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
    Enemy(bool isHostile = true, bool isMoveable = true) : Character(HP, Atk, Def, race, row, col) {
        Character(HP, Atk, Def, race,row, col);
    }
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
    Vampire(int HP = 50, int Atk = 25, int Def = 25, std::string race = "Vampire", int row = 10, int col = 10) : Character(HP, Atk, Def, race, row, col) {}

};

class Werewolf : public Enemy {
    Werewolf(int 120, int Atk = 30, int Def = 5, std::string race = "Werewolf", int row = 10, int col = 10) {Character(HP, Atk, Def, race, row, col);}

};

class Troll : public Enemy {
    Troll(int 120, int Atk = 25, int Def = 15, std::string race = "Troll", int row = 10, int col = 10) {Character(HP, Atk, Def, race, row, col);}

};

class Goblin : public Enemy {
    Goblin(int 70, int Atk = 5, int Def = 10, std::string race = "Goblin", int row = 10, int col = 10) {Character(HP, Atk, Def, race, row, col);}
    
};

class Merchant : public Enemy {
    Merchant(int 30, int Atk = 70, int Def = 5, std::string race = "Merchant", int row = 10, int col = 10) {Character(HP, Atk, Def, race, row, col);}

};

class Phoenix : public Enemy {
    Phoenix(int 50, int Atk = 35, int Def = 20, std::string race = "Phoenix", int row = 10, int col = 10) {Character(HP, Atk, Def, race, row, col);}

};

class Dragon : public Enemy {
    Dragon(int 150, int Atk = 20, int Def = 20, std::string race = "Dragon", int row = 10, int col = 10) {Character(HP, Atk, Def, race, row, col);}
};
#endif
