#ifndef FLOOR_H
#define FLOOR_H
#include <iotstream>
#include <memory>
#include <player.h>
#include <enemy.h>
#include <item.h>
#include <stair.h>
class Floor {
    private:
    int floorNum;  // display current floor number
    int atRow; // store the row number of the floor
    int atCol; // store the col number of the floor
    bool floorDisplayer;  // used to show when PC has compass

    shared_ptr<Player> PC;  // player
    vector<shared_ptr<Enemy>> enemies; // 10
    shared_ptr<Stair> stair;  
    vector<shared_ptr<Potion>> potions; // 10
    vector<shared_ptr<Gold>> Golds; // 10
    shared_ptr<Compass> compass; // 1/floor
    shared_ptr<BarrierSuit> barrierSuit; // 1/game
    
    public:
};

#endif


