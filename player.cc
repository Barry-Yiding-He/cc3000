#include "player.h"


Player::~Player() {}

Player::Player(int HP, int Atk, int Def, 
                    std::string race, char repChar, int row, int col, bool isArmed, int goldTotal):
    Character(HP, Atk, Def, race, repChar, row, col), isArmed(isArmed), goldTotal(goldTotal) {
    }

bool Player::getIsArmed() {
    return this->isArmed;
}

int Player::getGoldTotal() {
    return this->goldTotal;
}

std::string Player::getAction() {
    return this->action;
}

Human::Human(int HP, int Atk, int Def, std::string race, char repChar, int row, int col, bool isArmed, int goldTotal)  : Player(HP, Atk, Def, race, repChar, row, col, isArmed, goldTotal){
}


Drawf::Drawf(int HP , int Atk, int Def, std::string race, char repChar, int row, int col, bool isArmed, int goldTotal) : Player(HP, Atk, Def, race, repChar, row, col, isArmed, goldTotal) {
    
}


Elves::Elves(int HP , int Atk, int Def, std::string race, char repChar, int row, int col, bool isArmed, int goldTotal) : Player(HP, Atk, Def, race, repChar, row, col, isArmed, goldTotal) {
    
}

Orc::Orc(int HP , int Atk, int Def, std::string race, char repChar, int row, int col, bool isArmed, int goldTotal) : Player(HP, Atk, Def, race, repChar, row, col, isArmed, goldTotal) {
    
}






