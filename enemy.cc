#include "enemy.h"

using namespace std;

bool Enemy::getIsHostile() {
    return this->isHostile;
}

bool Enemy::getGoldNum() {
    return this->goldNum;
}

void Enemy::changeHostile() {
    this->goldNum = !(this->goldNum);
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


int Enemy::attack(std::shared_ptr<Player> &PC) {
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
    return damge;
}

