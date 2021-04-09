#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>



class Character {
    
    protected:
    int HP;
    int curHP;
    int Atk;
    int curAtk;
    int Def;
    int curDef;
    std::string race;

    int atRow; // store the row number 
    int atCol; // store the col number 
    public:
    // constr;
    /////////////////

    // Accessor
    int getCurHP();
    int getHP();
    int getAtk();
    int getCurAtk();
    int getDef();
    int getCurDef();
    int getRow();
    int getCol();
    std::string getRace();

    // Fun for drink Potion/fight

    virtual void healHP(int value);
    virtual void loseHP(int value);
    virtual void increaseAtk(int value);
    virtual void decreaseAtk(int value);
    virtual void increaseDef(int value);
    virtual void decreaseDef(int value);

    //constructor and destructor 
    Character(int HP, int Atk, int Def, std::string race, int row, int col);
    virtual ~Character();

};

#endif
