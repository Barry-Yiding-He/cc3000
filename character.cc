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

int Character::getCurAtk() {
    return this->curAtk;
}

int Character::getDef() {
    return this->Def;
}

int Character::getCurDef() {
    return this->curDef;
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

void Character::healHP(int value) {
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
    this->curAtk += value;
}

void Character::decreaseAtk(int value) {
    this->curAtk -= value;
    if (this->curAtk <= 0) {
        this->curAtk = 0;
    }
}

void Character::increaseDef(int value) {
    this->curDef += value;
}

void Character::decreaseDef(int value) {
    this->curDef -= value;
    if (this->curDef <= 0) {
        this->curDef = 0;
    }
}

Character::Character(int HP = 100 , int Atk = 20 , int Def = 20, 
                    std::string race = "default", int row = 10, int col = 10):
    HP{HP}, Atk{Atk}, curAtk{Atk}, Def{Def}, curDef{Def}, race{race}, atRow{row}, atCol{col} {}

Character::~Character() {};
