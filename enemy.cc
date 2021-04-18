#include "enemy.h"

using namespace std;

bool Enemy::getIsHostile() {
    return this->isHostile;
}

int Enemy::getGoldNum() {
    return this->goldNum;
}

void Enemy::changeHostile() {
    this->isHostile = true;
}

void Enemy::holdCompass() {
    this->compassHolder = true;
}

void Enemy::move() {

}

char Enemy::getChar() {
    return repChar;
}


bool Enemy::getMoveable() {
    return isMoveable;
}

bool Enemy::isHolder() {
    return this->compassHolder;
}


void Enemy::attack(std::shared_ptr<Player> &PC) {
    int pre = 0;
    if ((100/(100+PC->getCurDef())) ==  0) {
        pre = 1;
    } else if (100/(100+PC->getCurDef()) == 1) {
        pre = 2;
    }
    
    int damge = pre * getCurAtk();
    if (PC->getIsArmed()) {
        damge /= 2;
        PC->loseHP(damge);
    } else {
        PC->loseHP(damge);
    }
}

int Enemy::damage(std::shared_ptr<Player> &PC) {
    int pre = 0;
    if ((100/(100+PC->getCurDef())) ==  0) {
        pre = 1;
    } else if (100/(100+PC->getCurDef()) == 1) {
        pre = 2;
    }
    
    int damge = pre * getCurAtk();
    if (PC->getIsArmed()) {
        damge /= 2;
    } else {
        
    }
    return damge;
}

