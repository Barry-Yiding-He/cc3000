#include "player.h"

Player::~Player() {}

Player::Player(int HP = 100 , int Atk = 20 , int Def = 20, 
                    std::string race = "default", int row = 10, int col = 10):
    Character(HP,Atk,Def,race,row,col) {
        this->isArmed = false;
        this->goldTotal = 0;
    }

