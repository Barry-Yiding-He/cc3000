#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include <memory>
#include "enemy.h"
#include "item.h"
#include "stair.h"
#include "player.h"
#include <vector>



class Floor {
    private:
    int floorNum;  // display current floor number
    std::vector<std::vector<char>> display;
    std::shared_ptr<Player> PC;  // player
    std::vector<std::shared_ptr<Enemy>> enemies; // 10
    std::shared_ptr<Stair> stair;
    std::vector<std::shared_ptr<Potion>> potions; // 10
    std::vector<std::shared_ptr<Gold>> Golds; // 10
    std::shared_ptr<Compass> compass; // 1/floor
    std::shared_ptr<BarrierSuit> barrierSuit; // 1/game
    
    public:
    // constructor
    Floor(std::string map = "map.txt"); //////////////////////////

    // generate component of the game
    void generateChamber();
    void generateGold();
    void generateEnemy();
    void generatePotion();
    void generatePC();
    void generateStair();

    // set floor
    void setFloor();
    
    // move PC
    void movePC(std::string direction);
    




    // here we have accessor and mutator
    int getFloorNum ();
    
    
    friend std::ostream &operator<<(std::ostream &out, const Floor &f); // print the floor
};

#endif


