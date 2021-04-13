#ifndef ITEM_H
#define ITEM_H
#include <iostream>

class Item {

    private:
    int atRow; // store the row number 
    int atCol; // store the col number
    char repChar;

    public:

    explicit Item(int row, int col, char repChar = '0');
    virtual ~Item();
    int getRow();
    int getCol();
    char getRepChar();
};


class Potion : public Item {
    int potionType; // indicate the type of the potion : 'RH' = 0 'BA' = 1 'BD' = 2
                    // 'PH' = 3 'WA' = 4 'WD' = 5
    public:
    Potion (int row, int col, int potionType);
};

/*class Gold : public Item {
    int goldType; // indicate the type of the gold : '1' = 6 '2' = 7 '4-merchant horde' = 8 '6-dragon horde' = 9
    bool pickable; // used to show when 周围有龙
};

class Compass : public Item {

};

class BarrierSuit : public Item {
    bool pickable; // used to show when 周围有龙
};
*/
#endif
