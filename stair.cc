#include "stair.h"

Stair::Stair(int Row, int Col) {
    this->atRow = Row;
    this->atCol = Col;
    //this->StairDisplayer = false;
}

Stair::~Stair() {}

int Stair::getRow() {
    return this->atRow;
}


int Stair::getCol() {
    return this->atCol;
}


//bool Stair::getStairDisplayer() {
   // return this->StairDisplayer;
//}

bool Stair::isSameCoor(int r, int c) {
    if ((this->atRow == r) && (this->atCol == c)) return true;

    return false;
}