#include "chamber.h"



Chamber::Chamber(int roomNum) {
    this->roomNum = roomNum;
    if (roomNum == 1) { // top left chamber
        this->top = 3;
        this->bottom = 6;
        this->left = 3;
        this->right = 29; 
    }

    if (roomNum == 2) { // half of top right chamber (upper half)
        this->top = 3;
        this->bottom = 6;
        this->left = 40;
        this->right = 76;
    }

    if (roomNum == 3) { // half of top right chamber (lower half)
        this->top = 7;
        this->bottom = 12;
        this->left = 62;
        this->right = 76;
    }

    if (roomNum == 4) { // mid chamber
        this->top = 10;
        this->bottom = 12;
        this->left = 39;
        this->right = 50;
    }

    if (roomNum == 5) { // bottom left chamber
        this->top = 15;
        this->bottom = 21;
        this->left = 5;
        this->right = 25;
    }

    if (roomNum == 6) { // bottom right chamber
        this->top = 16;
        this->bottom = 21;
        this->left = 38;
        this->right = 76;
    }

}

int Chamber::getRoomNum() {
    return this->roomNum;
}

int Chamber::getTop() {
    return this->top;
}

int Chamber::getBottom() {
    return this->bottom;
}

int Chamber::getLeft() {
    return this->left;
}

int Chamber::getRight() {
    return this->right;
}
