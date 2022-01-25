#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "character.h"
#include <string>



class Human : public Player {
    
public:
    Human(int HP = 1400, int Atk = 200, int Def = 20, std::string race = "Human", char repChar = '@', int row = 10, int col = 10, bool isArmed = false, int goldTotal = 0);

};

class Drawf : public Player {
public:
    Drawf(int HP = 100 , int Atk = 20 , int Def = 30, std::string race = "Drawf", char repChar = '@', int row = 10, int col = 10, bool isArmed = false, int goldTotal = 0);
};

class Elves : public Player {
public:
    Elves(int HP = 140 , int Atk = 30 , int Def = 10, std::string race = "Elves", char repChar = '@', int row = 10, int col = 10, bool isArmed = false, int goldTotal = 0);
};

class Orc : public Player {
public:
    Orc(int HP = 180 , int Atk = 30 , int Def = 25, std::string race = "Orc", char repChar = '@', int row = 10, int col = 10, bool isArmed = false, int goldTotal = 0);
};


#endif
