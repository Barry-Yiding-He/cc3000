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

};

class Drawf : public Player {

};

class Elves : public Player {

};

class Orc : public Player {

};
#endif
