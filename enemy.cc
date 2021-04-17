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


void Enemy::attack(std::shared_ptr<Player> &PC) {
    int damage = this->getCurAtk();
    PC->loseHP(damage);
    
}