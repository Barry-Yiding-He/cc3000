#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "character.h"




class Player : public Character {
    protected:
    bool isArmed = false; // used to  show weather player is wearing the suit
    int goldTotal = 0; // used to show the total amount of the gold player have

    public:
//     constructer and destructor
    explicit Player(int HP = 100, int Atk = 20, int Def = 20, 
        std::string race = "default", int row = 10, int col = 10, bool isArmed = false, int goldTotal = 0);
    virtual ~Player();

    //
    
};


class Human : public Player {
    
public:
    Human(int HP = 100, int Atk = 20, int Def = 20, std::string race = "Human", int row = 10, int col = 10, bool isArmed = false, int goldTotal = 0);

};

class Drawf : public Player {
public:
    Drawf(int HP = 100 , int Atk = 20 , int Def = 30, std::string race = "Drawf", int row = 10, int col = 10, bool isArmed = false, int goldTotal = 0);
};

class Elves : public Player {
public:
    Elves(int HP = 140 , int Atk = 30 , int Def = 10, std::string race = "Elves", int row = 10, int col = 10, bool isArmed = false, int goldTotal = 0);
};

class Orc : public Player {
public:
    Orc(int HP = 180 , int Atk = 30 , int Def = 25, std::string race = "Orc", int row = 10, int col = 10, bool isArmed = false, int goldTotal = 0);
};


#endif
