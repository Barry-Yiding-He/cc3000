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


Potion::Potion(int row, int col, int potionType): Item(row, col, 'P') {
    this->potionType = potionType;
}