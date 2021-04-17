#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include <algorithm>
#include <memory>
#include <cmath>

class Player;
class Enemy;


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



class Enemy : public Character {
    
protected:
    bool isHostile; // used to check wheather enemy is hostile to PC
    bool isMoveable; // used to check wheather enemy is moveable
    bool compassHolder; // used to check wheather the enemy is the compass holder
    int goldNum; // indicate the number of the gold that enemy have : '1' = default  '4' = merchant 
    // note: slain the dragon will not drop gold
public:
    // constr
    Enemy (int HP = 100 , int Atk = 20 , int Def = 20, 
        std::string race = "default", char repChar = 'd', int row = 10, int col = 10, bool isHostile = true, bool isMoveable = true) : Character (HP, Atk, Def, race, repChar, row, col) {
            this->isHostile = isHostile;
            this->isMoveable = isMoveable;
            compassHolder = false;
        }
    
    ////////////
    
    // accessor
    bool getIsHostile();
    bool getGoldNum();
    char getChar();
    
    // Fun 
    void holdCompass();
    void changeHostile();
    void move();
    int attack(std::shared_ptr<Player> &PC);
    bool getMoveable();
    bool isHolder();
    
};


class Player : public Character {
protected:
    bool isArmed; // used to  show weather player is wearing the suit
    int goldTotal = 0; // used to show the total amount of the gold player have
    std::string action = "Player character has spawned"; // store the action
    
public:
    // constructer and destructor
    explicit Player(int HP = 100, int Atk = 20, int Def = 20, 
        std::string race = "default", char repChar = '@', int row = 10, int col = 10, bool isArmed = false, int goldTotal = 0);
    virtual ~Player();
    
    // Fun
    bool getIsArmed();
    void armSuit();
    int getGoldTotal();
    void collectGold(int goldType);
    std::string getAction();
    void changeAction(std::string action);
    void addAction(std::string newAct);
    int attack(std::shared_ptr<Enemy> &e);
    
};






#endif

