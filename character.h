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
    char repChar;

    int atRow; // store the row number 
    int atCol; // store the col number 
    public:

    // Accessor
    int getCurHP();
    int getHP();
    int getAtk();
    int getCurAtk();
    int getDef();
    int getCurDef();
    int getRow();
    void addRow(int step = 1);
    void setRow(int pos);
    int getCol();
    void addCol(int step = 1);
    void setCol(int pos);
    std::string getRace();
    char getRepChar();
    void setCurHP(int i);
    void setCurAtk(int i);
    void setCurDef(int i);
    

    // Fun for drink Potion/fight

    virtual void healHP(int value);
    virtual void loseHP(int value);
    virtual void increaseAtk(int value);
    virtual void decreaseAtk(int value);
    virtual void increaseDef(int value);
    virtual void decreaseDef(int value);

    //constructor and destructor 
    Character(int HP = 100 , int Atk = 20 , int Def = 20, 
        std::string race = "default", char repChar = '@', int row = 10, int col = 10);
    virtual ~Character();

};

#endif
