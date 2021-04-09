#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>




class Player : public Character {
    private:
    bool isArmed; // used to  show weather player is wearing the suit
    int goldTotal; // used to show the total amount of the gold player have

    public:
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
