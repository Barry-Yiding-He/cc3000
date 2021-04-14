#include "item.h"


Item::Item(int row, int col, char repChar) {
    this->atRow = row;
    this->atCol = col;
    this->repChar = repChar;
}

Item::~Item() {}

int Item::getRow() {
    return this->atRow;
}

int Item::getCol() {
    return this->atCol;
}

char Item::getRepChar() {
    return this->repChar;
}

int Potion::getPotionType() {
    return this->potionType;
}

Potion::Potion(int row, int col, int potionType) : Item(row, col, 'P') {
    this->potionType = potionType;
}

int Gold::getGoldType() {
    return this->goldType;
}

bool Gold::getPickable() {
    return this->pickable;
}

void Gold::canPick() {
    this->pickable = true;
}

Gold::Gold(int row, int col, int goldType, bool pickable) : Item(row, col, 'G') {
    this->goldType = goldType;
    this->pickable = pickable;
}

Compass::Compass(int row, int col) : Item(row, col, 'C') {}

int BarrierSuit::getPickable() {
    return this->pickable;
}

void BarrierSuit::canPick() {
    this->pickable = true;
}

BarrierSuit::BarrierSuit(int row, int col) : Item(row, col, 'B') {
    this->pickable = false;
}