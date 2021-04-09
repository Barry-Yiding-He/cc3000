#ifndef FLOOR_H
#define FLOOR_H
#include <iostream>
#include <memory>
#include <player.h>
#include <enemy.h>
#include <item.h>
#include <stair.h>


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
};

#endif


