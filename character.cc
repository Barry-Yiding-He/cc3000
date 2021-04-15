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

void Character::addRow(int step) {
    atRow+= step;
}

void Character::setRow(int pos) {
    atRow = pos;
}

int Character::getCol() {
    return this->atCol;
}

void Character::addCol(int step) {
    atCol += step;
}

void Character::setCol(int pos) {
    atCol = pos;
}

std::string Character::getRace() {
    return this->race;
}

char Character::getRepChar() {
    return this->repChar;
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

Character::Character(int HP, int Atk, int Def, 
                    std::string race,  char repChar, int row, int col):
    HP{HP}, curHP{HP}, Atk{Atk}, curAtk{Atk}, Def{Def}, curDef{Def}, race{race}, repChar{repChar}, atRow{row}, atCol{col} {}

Character::~Character() {}




void Character::setCurHP(int i) {
    curHP += i;
    if (curHP > HP) {
        curHP = HP;
    } else if (curHP < 0) {
        curHP = 0;
    }
}

void Character::setCurAtk(int i) {
    curAtk += i;
    if (curAtk < 0) {
        curAtk = 0;
    }
}

void Character::setCurDef(int i) {
    curDef += i;
    if (curDef < 0) {
        curDef = 0;
    }
}
