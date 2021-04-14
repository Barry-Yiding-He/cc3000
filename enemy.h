#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include "character.h"
#include <memory>
#include "player.h"




class Enemy : public Character {
    
    protected:
    bool isHostile; // used to check wheather enemy is hostile to PC
    bool isMoveable; // used to check wheather enemy is moveable
    bool compassHolder; // used to check wheather the enemy is the compass holder
    int goldNum; // indicate the number of the gold that enemy have : '1' = default  '4' = merchant 
                     // note: slain the dragon will not drop gold
    public:
    // constr
    Enemy (int HP = 100 , int Atk = 20 , int Def = 20, 
        std::string race = "default", char repChar = 'd', int row = 10, int col = 10, bool isHostile = true, bool isMoveable = true) : Character (HP, Atk, Def, race, repChar, row, col) {
        isHostile = isHostile;
        isMoveable = isMoveable;
        compassHolder = false;
    }

    ////////////

    // accessor
    bool getIsHostile();
    bool getGoldNum();

    // Fun 
    void holdCompass();
    void changeHostile();
    void move();
    void attack(std::shared_ptr<Player> &PC);
};


class Vampire : public Enemy {
public:
    Vampire(int HP = 50, int Atk = 25, int Def = 25, std::string race = "Vampire", char repChar = 'V', int row = 10, int col = 10, bool isHostile = true, bool isMoveable = true) : Enemy(HP, Atk, Def, race, repChar, row, col, isHostile, isMoveable) {
    }

};

class Werewolf : public Enemy {
public:
    Werewolf(int HP = 120, int Atk = 30, int Def = 5, std::string race = "Werewolf", char repChar = 'W', int row = 10, int col = 10, bool isHostile = true, bool isMoveable = true) : Enemy(HP, Atk, Def, race, repChar, row, col, isHostile, isMoveable) {
    }
};

class Troll : public Enemy {
public:
    Troll(int HP = 120, int Atk = 25, int Def = 15, std::string race = "Troll", char repChar = 'T', int row = 10, int col = 10, bool isHostile = true, bool isMoveable = true) : Enemy(HP, Atk, Def, race, repChar, row, col, isHostile, isMoveable){
        
    }
};

class Goblin : public Enemy {
public:
    Goblin(int HP = 70, int Atk = 5, int Def = 10, std::string race = "Goblin", char repChar = 'N', int row = 10, int col = 10, bool isHostile = true, bool isMoveable = true) : Enemy(HP, Atk, Def, race, repChar, row, col, isHostile, isMoveable) {
        
    }
    
};

class Merchant : public Enemy {
public:
    Merchant(int HP = 30, int Atk = 70, int Def = 5, std::string race = "Merchant", char repChar = 'M', int row = 10, int col = 10, bool isHostile = false, bool isMoveable = true) : Enemy(HP, Atk, Def, race, repChar, row, col, isHostile, isMoveable) {
        
    }

};

class Phoenix : public Enemy {
public:
    Phoenix(int HP = 50, int Atk = 35, int Def = 20, std::string race = "Phoenix", char repChar = 'X', int row = 10, int col = 10, bool isHostile = true, bool isMoveable = true) : Enemy(HP, Atk, Def, race, repChar, row, col, isHostile, isMoveable) {
        
    }

};

class Dragon : public Enemy {
public:
    Dragon(int HP = 150, int Atk = 20, int Def = 20, std::string race = "Dragon", char repChar = 'D', int row = 10, int col = 10, bool isHostile = true, bool isMoveable = true) : Enemy(HP, Atk, Def, race, repChar, row, col, isHostile, isMoveable) {
    }
};
#endif
