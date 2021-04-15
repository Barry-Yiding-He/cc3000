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
    std::vector<std::shared_ptr<Chamber>> chambers;
    char orig = '.';
    public:
    // constructor
    Floor(std::string map = "map.txt"); //////////////////////////

    // generate component of the game
    struct Coordinate getRandomCoorinate();
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

    // set floor
    void setFloor(std::string race);
    
    // move PC
    void movePC(std::string direction, std::string race);
    
    // PC was randomly attacked
    void wasAttack();
    
    // random move one
    void randMove(std::shared_ptr<Enemy> e);
    void randMoveAll();




    // here we have accessor and mutator
    /*const int getFloorNum ();
    const std::vector<std::vector<char>> getDisplay();
    const std::shared_ptr<Player> getPC(); 
    const std::vector<std::shared_ptr<Enemy>> getEnemies(); 
    const std::shared_ptr<Stair> getStair();
    const std::vector<std::shared_ptr<Potion>> getPotions(); 
    const std::vector<std::shared_ptr<Gold>> getGolds(); 
    */
    
    friend std::ostream &operator<<(std::ostream &out, const Floor &f); // print the floor
};



class InvalidCommand {};
#endif


