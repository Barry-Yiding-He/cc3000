#include "player.h"


Player::~Player() {}

Player::Player(int HP, int Atk, int Def, 
                    std::string race, char repChar, int row, int col, bool isArmed, int goldTotal):
    Character(HP, Atk, Def, race, repChar, row, col), isArmed(isArmed), goldTotal(goldTotal) {
    }

bool Player::getIsArmed() {
    return this->isArmed;
}

void Player::armSuit() {
    this->isArmed = true;
}

int Player::getGoldTotal() {
    return this->goldTotal;
}

void Player::collectGold(int goldType) {
    if (goldType == 6) { 
        this->goldTotal++;
        std::string act = "collected 1 gold";
        this->addAction(act);
    }
    if (goldType == 7) {
        this->goldTotal += 2;
        std::string act = "collected 2 golds";
        this->addAction(act);
    }
    if (goldType == 8) {
        this->goldTotal += 4;
        std::string act = "collected 4 golds";
        this->addAction(act);
    }
    if (goldType == 9) {
        this->goldTotal += 6;
        std::string act = "collected 6 golds";
        this->addAction(act);
    }
}

std::string Player::getAction() {
    return this->action;
}

void Player::changeAction(std::string action) {
    this->action = action;
}

void Player::addAction(std::string newAct) {
    this->action.append(" and ");
    this->action.append(newAct);
}

Human::Human(int HP, int Atk, int Def, std::string race, char repChar, int row, int col, bool isArmed, int goldTotal)  : Player(HP, Atk, Def, race, repChar, row, col, isArmed, goldTotal){
}


Drawf::Drawf(int HP , int Atk, int Def, std::string race, char repChar, int row, int col, bool isArmed, int goldTotal) : Player(HP, Atk, Def, race, repChar, row, col, isArmed, goldTotal) {
    
}


Elves::Elves(int HP , int Atk, int Def, std::string race, char repChar, int row, int col, bool isArmed, int goldTotal) : Player(HP, Atk, Def, race, repChar, row, col, isArmed, goldTotal) {
    
}

Orc::Orc(int HP , int Atk, int Def, std::string race, char repChar, int row, int col, bool isArmed, int goldTotal) : Player(HP, Atk, Def, race, repChar, row, col, isArmed, goldTotal) {
    
}

void Player::attack(std::shared_ptr<Enemy> &e) {
    int pre = 0;
    if ((100/(100+e->getCurDef())) ==  0) {
        pre = 1;
    } else if (100/(100+e->getCurDef()) == 1) {
        pre = 2;
    }
    
//    std::cout << pre << std::endl;
    int damage = pre * getCurAtk();
    e->loseHP(damage);
}


int Player::damage(std::shared_ptr<Enemy> &e) {
    int pre = 0;
    if ((100/(100+e->getCurDef())) ==  0) {
        pre = 1;
    } else if (100/(100+e->getCurDef()) == 1) {
        pre = 2;
    }
    
    //    std::cout << pre << std::endl;
    int damage = pre * getCurAtk();
    return damage;
}

int Player::findChamberNum() {
    if ((this->getRow() >= 3) && (this->getRow() <= 6) &&
        (this->getCol() >= 3) && (this->getCol() <= 29)) {return 0;}
    else if ((this->getRow() >= 3) && (this->getRow() <= 6) &&
             (this->getCol() >= 40) && (this->getCol() <= 76)) {return 1;}
    else if ((this->getRow() >= 7) && (this->getRow() <= 12) &&
             (this->getCol() >= 62) && (this->getCol() <= 76)) {return 2;}
    else if ((this->getRow() >= 10) && (this->getRow() <= 12) &&
             (this->getCol() >= 39) && (this->getCol() <= 50)) {return 3;}
    else if ((this->getRow() >= 15) && (this->getRow() <= 21) &&
             (this->getCol() >= 5) && (this->getCol() <= 25)) {return 4;}
    else if ((this->getRow() >= 16) && (this->getRow() <= 21) &&
             (this->getCol() >= 38) && (this->getCol() <= 76)) {return 5;}
}