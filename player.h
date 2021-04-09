#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "character.h"




class Player : public Character {
    protected:
    bool isArmed; // used to  show weather player is wearing the suit
    int goldTotal; // used to show the total amount of the gold player have

    public:
    // constructer and destructor
    Player(int HP, int Atk, int Def, std::string race, int row, int col);
    virtual ~Player();

    //
    
};


class Human : public Player {
    Human(int HP = 140 , int Atk = 20 , int Def = 20, std::string race = "Human", int row = 10, int col = 10) {Player(HP, Atk, Def, race, row, col); }

};

class Drawf : public Player {
    Drawf(int HP = 100 , int Atk = 20 , int Def = 30, std::string race = "Drawf", int row = 10, int col = 10) {Player(HP, Atk, Def, race, row, col); }

};

class Elves : public Player {
    Elves(int HP = 140 , int Atk = 30 , int Def = 10, std::string race = "Elves", int row = 10, int col = 10) {Player(HP, Atk, Def, race, row, col); }
};

class Orc : public Player {
    Orc(int HP = 180 , int Atk = 30 , int Def = 25, std::string race = "Orc", int row = 10, int col = 10) {Player(HP, Atk, Def, race, row, col); }
};
#endif
