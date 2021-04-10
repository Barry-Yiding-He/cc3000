#include "player.h"

Player::~Player() {}

Player::Player(int HP, int Atk, int Def, 
                    std::string race, int row, int col, bool isArmed, int goldTotal):
    Character(HP,Atk,Def,race,row,col) {
        isArmed = false;
        goldTotal = 0;
    }

