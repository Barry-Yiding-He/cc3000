#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include "character.h"
#include <memory>
#include <vector>
#include <random>
#include <chrono>



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
    Dragon(int HP = 150, int Atk = 20, int Def = 20, std::string race = "Dragon", char repChar = 'D', int row = 10, int col = 10, bool isHostile = true, bool isMoveable = false) : Enemy(HP, Atk, Def, race, repChar, row, col, isHostile, isMoveable) {
    }
};
#endif
