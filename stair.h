#ifndef STAIR_H
#define STAIR_H
#include <iostream>




class Stair {
    private:

    int atRow = 0; // store the row number 
    int atCol = 0; // store the col number 
    bool StairDisplayer;  // used to show when PC has compass

    public:
    // constructer and destructor
    virtual ~Stair();

    Stair(int atRow, int atCol);
    // accessor
    int getRow();
    int getCol();
    bool getStairDisplayer();
    bool isSameCoor(int r, int c); // used to check if the given r and c are same coordinate
                                   // with stair;


};


#endif
