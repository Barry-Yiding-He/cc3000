#ifndef CHAMBER_H
#define CHAMBER_H
#include <iostream>




class Chamber {
    private:

    int roomNum; // store the current room number
    int top; // store the upper bound of the current room
    int bottom; // stote the lower bound of the current room
    int left; // store the left margin of the current room
    int right; // store the right margin of the current room 

    public:
    // constructer and destructor
    Chamber(int roomNum);

    // accessor
    int getRoomNum();
    int getTop();
    int getBottom();
    int getLeft();
    int getRight();


};

#endif
