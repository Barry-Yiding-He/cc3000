#include "character.h"


int Character::getCurHP() {
    return this->curHP;
}

int Character::getHP() {
    return this->HP;
}

int Character::getAtk() {
    return this->Atk;
}

int Character::getDef() {
    return this->Def;
}

int Character::getRow() {
    return this->atRow;
}

int Character::getCol() {
    return this->atCol;
}

std::string Character::getRace() {
    return this->race;
}

void Character::restoreHP(int value) {
    this->curHP += value;
    if (this->curHP >= this->HP) {
        this->curHP = this->HP;
    }
}

void Character::loseHP(int value) {
    this->curHP -= value;
    if (this->curHP <= 0) {
        this->curHP = 0;
    }
}

void Character::increaseAtk(int value) {
    this->Atk += value;
}

void Character::decreaseAtk(int value) {
    this->Atk -= value;
    if (this->Atk <= 0) {
        this->Atk = 0;
    }
}

void Character::increaseDef(int value) {
    this->Def += value;
}

void Character::decreaseDef(int value) {
    this->Def -= value;
    if (this->Def <= 0) {
        this->Def = 0;
    }
}

