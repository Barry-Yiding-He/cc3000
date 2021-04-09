#include "enemy.h"

bool Enemy::getIsHostile() {
    return this->isHostile;
}

bool Enemy::getGoldNum() {
    return this->goldNum;
}

void Enemy::changeHostile() {
    this->goldNum = !(this->goldNum);
}

void Enemy::move() {

}

void Enemy::attack(std::shared_ptr<Player> &PC) {
    int damage = this->getCurAtk();
    PC->loseHP(damage);
}

