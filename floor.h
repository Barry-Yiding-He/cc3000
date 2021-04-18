#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include <memory>
#include "enemy.h"
#include "item.h"
#include "stair.h"
#include "player.h"
#include <vector>
#include "character.h"
#include "chamber.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <sstream>

struct Coordinate {
    public:
    int row, col;
};

class Floor {
    private:
    int floorNum;  // display current floor number
    int dragonGoldNum; // display the number of dragon horde gold in current floor;
    int bSuitFloor; // store the floor number of the bSuitFloor;
    bool attackedMer = false;
    std::vector<std::vector<char>> display;
    std::shared_ptr<Player> PC;  // player
    std::vector<std::shared_ptr<Enemy>> enemies; // 10
    std::shared_ptr<Stair> stair;
    std::vector<std::shared_ptr<Potion>> potions; // 10
    std::vector<std::shared_ptr<Gold>> golds; // 10
    std::shared_ptr<BarrierSuit> barrierSuit;
    std::shared_ptr<Compass> compass;
    std::vector<std::shared_ptr<Chamber>> chambers;
    char orig = '.';
    public:
    // constructor
    Floor(std::string map = "map.txt"); 

    // generate component of the game
    struct Coordinate getRandomCoorinate(int num = 6);
    void setUpChamber();
    void setUpCompass();
    void genOneGold();
    void generateGolds();
    void genOneEnemy();
    void generateEnemies();
    void genOnePotion();
    void generatePotions();
    void generatePC(std::string race);
    void generateStair();
    void generateBarrierSuit();
    void checkAround();
    int findGold(int row, int col);

    // set floor
    void setFloor(std::string race);
    void clearFloor(std::string = "map.txt");
    
    // move PC
    void oneStep(int first, int second, std::string race, std::string direction);
    void movePC(std::string direction, std::string race);
    
    // PC was randomly attacked
    void wasAttack();
    
    // random move one
    void randMove(std::shared_ptr<Enemy> e);
    //random move all enemy after PC move
    void randMoveAll();
    
    // drink potion
    std::shared_ptr<Potion> findPotion(int row, int col);
    void drinkPotion();
    void usePotion(std::shared_ptr<Potion> p);
    
    // check if win
    bool isWin();
    
    // check if lose
    bool isLose();
    
    void lose();
    // battle
    void battle(std::string race);
    std::shared_ptr<Enemy> findEnemy(int r, int c);
    int findEnemyIndex(int r, int c);
    void attack(std::shared_ptr<Enemy> e, std::shared_ptr<Player> pc);
    
    friend std::ostream &operator<<(std::ostream &out, const Floor &f); // print the floor
};



class InvalidCommand {};
#endif


