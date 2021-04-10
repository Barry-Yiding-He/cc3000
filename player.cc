#include "player.h"


Player::~Player() {}

Player::Player(int HP, int Atk, int Def, 
                    std::string race, int row, int col, bool isArmed, int goldTotal):
    Character(HP, Atk, Def, race, row, col) {
        isArmed = false;
        goldTotal = 0;
    }

Human::Human(int HP, int Atk, int Def, std::string race, int row, int col, bool isArmed, int goldTotal)  : Player(HP, Atk, Def, race, row, col, isArmed, goldTotal){
}


Drawf::Drawf(int HP , int Atk, int Def, std::string race, int row, int col, bool isArmed, int goldTotal) : Player(HP, Atk, Def, race, row, col, isArmed, goldTotal) {
    
}


Elves::Elves(int HP , int Atk, int Def, std::string race, int row, int col, bool isArmed, int goldTotal) : Player(HP, Atk, Def, race, row, col, isArmed, goldTotal) {
    
}

Orc::Orc(int HP , int Atk, int Def, std::string race, int row, int col, bool isArmed, int goldTotal) : Player(HP, Atk, Def, race, row, col, isArmed, goldTotal) {
    
}



void Player::move(std::string direction) {
    if ()
    if (direction == "no") {
        
    } else if (direction == "so") {
        
    } else if (direction == "we") {
        
    } else if (direction == "ea") {
        
    } else if (direction == "ne") {
        
    } else if (direction == "nw") {
        
    } else if (direction == "se") {
        
    } else if (direction == "sw") {
        
    }
}



