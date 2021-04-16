#include "floor.h"
#include <fstream>

using namespace std;

/*const int Floor::getFloorNum () {
    return this->floorNum;
}

const std::vector<std::vector<char>> Floor::getDisplay() {
    return this->display;
}

const std::shared_ptr<Player> Floor::getPC() {
    return this->PC;
}

const std::vector<std::shared_ptr<Enemy>> Floor::getEnemies() {
    return this->enemies;
}

const std::shared_ptr<Stair> Floor::getStair() {
    return this->stair;
}

const std::vector<std::shared_ptr<Potion>> Floor::getPotions() {
    return this->potions;
}

const std::vector<std::shared_ptr<Gold>> Floor::getGolds() {
    return this->golds;
}*/

struct Coordinate Floor::getRandomCoorinate() { // set a random row and col 
    std::vector<int> ranChamber = {0, 0, 1, 1, 2, 3, 4, 4, 5, 5}; // pick random chamber number from all chamber number
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::shuffle(ranChamber.begin(), ranChamber.end(), rng); // start to shuffle the order 
                                                             // and pick the first value in vector as our random value
    int chamberNum = ranChamber[0];
    int rowBegin = this->chambers[chamberNum]->getTop();   // locate the 4 info for the chamber we picked
    int rowEnd = this->chambers[chamberNum]->getBottom();   
    int colBegin = this->chambers[chamberNum]->getLeft();
    int colEnd = this->chambers[chamberNum]->getRight();
    std::vector<int> ranRow;                            
    for (rowBegin; rowBegin < rowEnd; rowBegin++) ranRow.emplace_back(rowBegin);  // setup a vector with coordinate in the selected chamber
    std::vector<int> ranCol;
    for (colBegin; colBegin < colEnd; colBegin++) ranCol.emplace_back(colBegin);

    std::shuffle(ranRow.begin(), ranRow.end(), rng);  // shuffle the order
    std::shuffle(ranCol.begin(), ranCol.end(), rng);
    int r = 0;
    int c = 0;
    while (true) {
        int row = ranRow[0];
        int col = ranCol[0];
        Coordinate coor {row, col};
        if (this->display[row][col] == '.') { 
        r = row; 
        c = col; 
        break;
        } else {
            std::shuffle(ranRow.begin(), ranRow.end(), rng);
            std::shuffle(ranCol.begin(), ranCol.end(), rng);
        }
    } // now we ger row and col
    Coordinate coor {r, c};
    return coor;

}


Floor::Floor(string map)  {
    // read all char in map to display
    this->floorNum = 0;
    this->setUpChamber();

    std::vector<int> ranFloor = {1, 2, 3, 4, 5};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::shuffle(ranFloor.begin(), ranFloor.end(), rng);
    this->bSuitFloor = ranFloor[0];

    ifstream gameMap {map};
    string s;
    int len;
    while (getline(gameMap, s)) {
        vector<char> row;
        len = s.length();
        for (int i = 0; i < len; ++i) {
            row.emplace_back(s[i]);
        }
        display.emplace_back(row);
	}
}


void Floor::setUpChamber() {
    auto chamber1 = make_shared<Chamber>(1);
    auto chamber2 = make_shared<Chamber>(2);
    auto chamber3 = make_shared<Chamber>(3);
    auto chamber4 = make_shared<Chamber>(4);
    auto chamber5 = make_shared<Chamber>(5);
    auto chamber6 = make_shared<Chamber>(6);

    std::vector<std::shared_ptr<Chamber>> chambers;
   
    chambers.emplace_back(chamber1);
    chambers.emplace_back(chamber2);
    chambers.emplace_back(chamber3);
    chambers.emplace_back(chamber4);
    chambers.emplace_back(chamber5);
    chambers.emplace_back(chamber6);
    this->chambers = chambers;
}


void Floor::wasAttack() {
    int luck;
    vector<int> index = {1,1,1,1,0,0,0,0};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::shuffle(index.begin(), index.end(), rng);
    luck = index[0];
    
    
    for (auto e : enemies) {
        if (luck == 1) {
            if (e->getIsHostile() == true) {
                if (display[e->getRow()-1][e->getCol()-1] == '@') {
                    e->attack(PC);
                    stringstream ss;
                    string s;
                    ss << e->getRepChar();
                    ss >> s;
                    std::string atkAct = s;
                    atkAct.append(" deals ");
                    stringstream ss1;
                    string s1;
                    ss1 << e->getCurAtk();
                    ss1 >> s1;
                    atkAct.append(s1);
                    atkAct.append(" damage to PC");
                    this->PC->addAction(atkAct);
                } else if (display[e->getRow()-1][e->getCol()] == '@') {
                    e->attack(PC);
                    stringstream ss;
                    string s;
                    ss << e->getRepChar();
                    ss >> s;
                    std::string atkAct = s;
                    atkAct.append(" deals ");
                    stringstream ss1;
                    string s1;
                    ss1 << e->getCurAtk();
                    ss1 >> s1;
                    atkAct.append(s1);
                    atkAct.append(" damage to PC");
                    this->PC->addAction(atkAct);
                } else if (display[e->getRow()-1][e->getCol()+1] == '@') {
                    e->attack(PC);
                    stringstream ss;
                    string s;
                    ss << e->getRepChar();
                    ss >> s;
                    std::string atkAct = s;
                    atkAct.append(" deals ");
                    stringstream ss1;
                    string s1;
                    ss1 << e->getCurAtk();
                    ss1 >> s1;
                    atkAct.append(s1);
                    atkAct.append(" damage to PC");
                    this->PC->addAction(atkAct);
                } else if (display[e->getRow()][e->getCol()-1] == '@') {
                    e->attack(PC);
                    stringstream ss;
                    string s;
                    ss << e->getRepChar();
                    ss >> s;
                    std::string atkAct = s;
                    atkAct.append(" deals ");
                    stringstream ss1;
                    string s1;
                    ss1 << e->getCurAtk();
                    ss1 >> s1;
                    atkAct.append(s1);
                    atkAct.append(" damage to PC");
                    this->PC->addAction(atkAct);
                } else if (display[e->getRow()][e->getCol()+1] == '@') {
                    e->attack(PC);
                    stringstream ss;
                    string s;
                    ss << e->getRepChar();
                    ss >> s;
                    std::string atkAct = s;
                    atkAct.append(" deals ");
                    stringstream ss1;
                    string s1;
                    ss1 << e->getCurAtk();
                    ss1 >> s1;
                    atkAct.append(s1);
                    atkAct.append(" damage to PC");
                    this->PC->addAction(atkAct);
                } else if (display[e->getRow()+1][e->getCol()-1] == '@') {
                    e->attack(PC);
                    stringstream ss;
                    string s;
                    ss << e->getRepChar();
                    ss >> s;
                    std::string atkAct = s;
                    atkAct.append(" deals ");
                    stringstream ss1;
                    string s1;
                    ss1 << e->getCurAtk();
                    ss1 >> s1;
                    atkAct.append(s1);
                    atkAct.append(" damage to PC");
                    this->PC->addAction(atkAct);
                } else if (display[e->getRow()+1][e->getCol()] == '@') {
                    e->attack(PC);
                    stringstream ss;
                    string s;
                    ss << e->getRepChar();
                    ss >> s;
                    std::string atkAct = s;
                    atkAct.append(" deals ");
                    stringstream ss1;
                    string s1;
                    ss1 << e->getCurAtk();
                    ss1 >> s1;
                    atkAct.append(s1);
                    atkAct.append(" damage to PC");
                    this->PC->addAction(atkAct);
                } else if (display[e->getRow()+1][e->getCol()+1] == '@') {
                    e->attack(PC);
                    stringstream ss;
                    string s;
                    ss << e->getRepChar();
                    ss >> s;
                    std::string atkAct = s;
                    atkAct.append(" deals ");
                    stringstream ss1;
                    string s1;
                    ss1 << e->getCurAtk();
                    ss1 >> s1;
                    atkAct.append(s1);
                    atkAct.append(" damage to PC");
                    this->PC->addAction(atkAct);
                }
            }
        }
        std::shuffle(index.begin(), index.end(), rng);
        luck = index[0];
    } 
}


void Floor::movePC(string direction, std::string race) {
    InvalidCommand Invalid;
    // first we check if we can move; if we can,  then we move
    if (direction == "no") {
        if ((PC->getRow()-1 == stair->getRow() && PC->getCol() == stair->getCol())){
            this->PC->changeAction("PC moves to the next Floor");
            PC->addRow(-1);
            clearFloor();
            setFloor(race);
        } else if (display[PC->getRow()-1][PC->getCol()] == '.') {
            this->PC->changeAction("PC moves North");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()-1][PC->getCol()] = '@';
            PC->addRow(-1);
            this->PC->changeAction("PC moves North");
        } else if (display[PC->getRow()-1][PC->getCol()] == '+') {
            this->PC->changeAction("PC moves North");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '+';
            display[PC->getRow()-1][PC->getCol()] = '@';
            PC->addRow(-1);
            this->PC->changeAction("PC moves North");
        } else if (display[PC->getRow()-1][PC->getCol()] == '#') {
            this->PC->changeAction("PC moves North");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '#';
            display[PC->getRow()-1][PC->getCol()] = '@';
            PC->addRow(-1);
        } else if (display[PC->getRow()-1][PC->getCol()] == 'G') {
            int goldNum = this->findGold(PC->getRow()-1, PC->getCol());
            if (this->golds[goldNum]->getPickable()) {
                 this->PC->changeAction("PC moves North");
                display[PC->getRow()][PC->getCol()] = orig;
                orig = '.';
                display[PC->getRow()-1][PC->getCol()] = '@';
                PC->addRow(-1);
                this->PC->collectGold(this->golds[goldNum]->getGoldType());
            } else {
                throw Invalid;
            }
        } else if (display[PC->getRow()-1][PC->getCol()] == 'B') {
            if (this->barrierSuit->getPickable()) {
                this->PC->changeAction("PC moves North and picked up the Barrier Suit");
                display[PC->getRow()][PC->getCol()] = orig;
                orig = '.';
                display[PC->getRow()-1][PC->getCol()] = '@';
                PC->addRow(-1);
                this->PC->armSuit();
            } else {
                throw Invalid;
            }
        } else if (display[PC->getRow()-1][PC->getCol()] == 'C') {
            this->PC->changeAction("PC moves South and picked up the Compass, the stair to the next floor has shown");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()-1][PC->getCol()] = '@';
            PC->addRow(-1);
            display[this->stair->getRow()][this->stair->getCol()] = '\\';
        } else {
            throw Invalid;
        }
    } else if (direction == "so") {
        if ((PC->getRow()+1 == stair->getRow() && PC->getCol() == stair->getCol())){
            this->PC->changeAction("PC moves to the next Floor");
            PC->addRow(1);
            clearFloor();
            setFloor(race);
        } else if (display[PC->getRow()+1][PC->getCol()] == '.') {
            this->PC->changeAction("PC moves South");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()+1][PC->getCol()] = '@';
            PC->addRow(1);
            this->PC->changeAction("PC moves South");
        } else if (display[PC->getRow()+1][PC->getCol()] == '+') {
            this->PC->changeAction("PC moves South");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '+';
            display[PC->getRow()+1][PC->getCol()] = '@';
            PC->addRow(1);
            this->PC->changeAction("PC moves South");
        } else if (display[PC->getRow()+1][PC->getCol()] == '#') {
            this->PC->changeAction("PC moves South");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '#';
            display[PC->getRow()+1][PC->getCol()] = '@';
            PC->addRow(1);
        } else if (display[PC->getRow()+1][PC->getCol()] == 'G') {
            int goldNum = this->findGold(PC->getRow()+1, PC->getCol());
            if (this->golds[goldNum]->getPickable()) {
                this->PC->changeAction("PC moves South");
                display[PC->getRow()][PC->getCol()] = orig;
                orig = '.';
                display[PC->getRow()+1][PC->getCol()] = '@';
                PC->addRow(1);
                this->PC->collectGold(this->golds[goldNum]->getGoldType());
            } else {
                throw Invalid;
            }
        } else if (display[PC->getRow()+1][PC->getCol()] == 'B') {
            if (this->barrierSuit->getPickable()) {
                this->PC->changeAction("PC moves South and picked up the Barrier Suit");
                display[PC->getRow()][PC->getCol()] = orig;
                orig = '.';
                display[PC->getRow()+1][PC->getCol()] = '@';
                PC->addRow(1);
                this->PC->armSuit();
            } else {
                throw Invalid;
            }
        } else if (display[PC->getRow()+1][PC->getCol()] == 'C') {
            this->PC->changeAction("PC moves South and picked up the Compass, the stair to the next floor has shown");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()+1][PC->getCol()] = '@';
            PC->addRow(1);
            display[this->stair->getRow()][this->stair->getCol()] = '\\';
        } else {
            throw Invalid;
        }
    } else if (direction == "we") {
        if ((PC->getRow() == stair->getRow() && PC->getCol()-1 == stair->getCol())){
            this->PC->changeAction("PC moves to the next Floor");
            PC->addCol(-1);
            clearFloor();
            setFloor(race);
        } else if (display[PC->getRow()][PC->getCol()-1] == '.') {
            this->PC->changeAction("PC moves West");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()][PC->getCol()-1] = '@';
            PC->addCol(-1);
            this->PC->changeAction("PC moves West");
        } else if (display[PC->getRow()][PC->getCol()-1] == '+') {
            this->PC->changeAction("PC moves West");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '+';
            display[PC->getRow()][PC->getCol()-1] = '@';
            PC->addCol(-1);
            this->PC->changeAction("PC moves West");
        } else if (display[PC->getRow()][PC->getCol()-1] == '#') {
            this->PC->changeAction("PC moves West");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '#';
            display[PC->getRow()][PC->getCol()-1] = '@';
            PC->addCol(-1);
        } else if (display[PC->getRow()][PC->getCol()-1] == 'G') {
            int goldNum = this->findGold(PC->getRow(), PC->getCol()-1);
            if (this->golds[goldNum]->getPickable()) {
                this->PC->changeAction("PC moves West");
                display[PC->getRow()][PC->getCol()] = orig;
                orig = '.';
                display[PC->getRow()][PC->getCol()-1] = '@';
                PC->addCol(-1);
                this->PC->collectGold(this->golds[goldNum]->getGoldType());
            } else {
                throw Invalid;
            }
        } else if (display[PC->getRow()][PC->getCol()-1] == 'B') {
            if (this->barrierSuit->getPickable()) {
                this->PC->changeAction("PC moves West and picked up the Barrier Suit");
                display[PC->getRow()][PC->getCol()] = orig;
                orig = '.';
                display[PC->getRow()][PC->getCol()-1] = '@';
                PC->addCol(-1);
                this->PC->armSuit();
            } else {
                throw Invalid;
            }
        } else if (display[PC->getRow()][PC->getCol()-1] == 'C') {
            this->PC->changeAction("PC moves South and picked up the Compass, the stair to the next floor has shown");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()][PC->getCol()-1] = '@';
            PC->addCol(-1);
            display[this->stair->getRow()][this->stair->getCol()] = '\\';
        } else {
            throw Invalid;
        }
    } else if (direction == "ea") {
        if ((PC->getRow() == stair->getRow() && PC->getCol()+1 == stair->getCol())){
            this->PC->changeAction("PC moves to the next Floor");
            PC->addCol(1);
            clearFloor();
            setFloor(race);
        } else if (display[PC->getRow()][PC->getCol()+1] == '.') {
            this->PC->changeAction("PC moves East");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()][PC->getCol()+1] = '@';
            PC->addCol(1);
            this->PC->changeAction("PC moves East");
        } else if (display[PC->getRow()][PC->getCol()+1] == '+') {
            this->PC->changeAction("PC moves East");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '+';
            display[PC->getRow()][PC->getCol()+1] = '@';
            PC->addCol(1);
            this->PC->changeAction("PC moves East");
        } else if (display[PC->getRow()][PC->getCol()+1] == '#') {
            this->PC->changeAction("PC moves East");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '#';
            display[PC->getRow()][PC->getCol()+1] = '@';
            PC->addCol(1);
        } else if (display[PC->getRow()][PC->getCol()+1] == 'G') {
            int goldNum = this->findGold(PC->getRow(), PC->getCol()+1);
            if (this->golds[goldNum]->getPickable()) {
                this->PC->changeAction("PC moves East");
                display[PC->getRow()][PC->getCol()] = orig;
                orig = '.';
                display[PC->getRow()][PC->getCol()+1] = '@';
                PC->addCol(1);
                this->PC->collectGold(this->golds[goldNum]->getGoldType());
            } else {
                throw Invalid;
            }
        } else if (display[PC->getRow()][PC->getCol()+1] == 'B') {
            if (this->barrierSuit->getPickable()) {
                this->PC->changeAction("PC moves East and picked up the Barrier Suit");
                display[PC->getRow()][PC->getCol()] = orig;
                orig = '.';
                display[PC->getRow()][PC->getCol()+1] = '@';
                PC->addCol(1);
                this->PC->armSuit();
            } else {
                throw Invalid;
            }
        } else if (display[PC->getRow()][PC->getCol()+1] == 'C') {
            this->PC->changeAction("PC moves South and picked up the Compass, the stair to the next floor has shown");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()][PC->getCol()+1] = '@';
            PC->addCol(1);
            display[this->stair->getRow()][this->stair->getCol()] = '\\';
        } else {
            throw Invalid;
        }
    } else if (direction == "ne") {
        if ((PC->getRow()-1 == stair->getRow() && PC->getCol()+1 == stair->getCol())){
            this->PC->changeAction("PC moves to the next Floor");
            PC->addRow(-1);
            PC->addCol(1);
            clearFloor();
            setFloor(race);
        } else if (display[PC->getRow()-1][PC->getCol()+1] == '.') {
            this->PC->changeAction("PC moves Northeast");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()-1][PC->getCol()+1] = '@';
            PC->addRow(-1);
            PC->addCol(1);
            this->PC->changeAction("PC moves Northeast");
        } else if (display[PC->getRow()-1][PC->getCol()+1] == '+') {
            this->PC->changeAction("PC moves Northeast");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '+';
            display[PC->getRow()-1][PC->getCol()+1] = '@';
            PC->addRow(-1);
            PC->addCol(1);
            this->PC->changeAction("PC moves Northeast");
        } else if (display[PC->getRow()-1][PC->getCol()+1] == '#') {
            this->PC->changeAction("PC moves Northeast");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '#';
            display[PC->getRow()-1][PC->getCol()+1] = '@';
            PC->addRow(-1);
            PC->addCol(1);
        } else if (display[PC->getRow()-1][PC->getCol()+1] == 'G') {
            int goldNum = this->findGold(PC->getRow()-1, PC->getCol()+1);
            if (this->golds[goldNum]->getPickable()) {
                this->PC->changeAction("PC moves Northeast");
                display[PC->getRow()][PC->getCol()] = orig;
                orig = '.';
                display[PC->getRow()-1][PC->getCol()+1] = '@';
                PC->addRow(-1);
                PC->addCol(1);
                this->PC->collectGold(this->golds[goldNum]->getGoldType());
            } else {
                throw Invalid;
            }
        } else if (display[PC->getRow()-1][PC->getCol()+1] == 'B') {
            if (this->barrierSuit->getPickable()) {
                this->PC->changeAction("PC moves Northeast and picked up the Barrier Suit");
                display[PC->getRow()][PC->getCol()] = orig;
                orig = '.';
                display[PC->getRow()-1][PC->getCol()+1] = '@';
                PC->addRow(-1);
                PC->addCol(1);
                this->PC->armSuit();
            } else {
                throw Invalid;
            }
        } else if (display[PC->getRow()-1][PC->getCol()+1] == 'C') {
            this->PC->changeAction("PC moves South and picked up the Compass, the stair to the next floor has shown");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()-1][PC->getCol()+1] = '@';
            PC->addRow(-1);
            PC->addCol(1);
            display[this->stair->getRow()][this->stair->getCol()] = '\\';
        } else {
            throw Invalid;
        }
    } else if (direction == "nw") {
        if ((PC->getRow()-1 == stair->getRow() && PC->getCol()-1 == stair->getCol())){
            this->PC->changeAction("PC moves to the next Floor");
            PC->addRow(-1);
            PC->addCol(-1);
            clearFloor();
            setFloor(race);
        } else if (display[PC->getRow()-1][PC->getCol()-1] == '.') {
            this->PC->changeAction("PC moves Northwest");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()-1][PC->getCol()-1] = '@';
            PC->addRow(-1);
            PC->addCol(-1);
            this->PC->changeAction("PC moves Northwest");
        } else if (display[PC->getRow()-1][PC->getCol()-1] == '+') {
            this->PC->changeAction("PC moves Northwest");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '+';
            display[PC->getRow()-1][PC->getCol()-1] = '@';
            PC->addRow(-1);
            PC->addCol(-1);
            this->PC->changeAction("PC moves Northwest");
        } else if (display[PC->getRow()-1][PC->getCol()-1] == '#') {
            this->PC->changeAction("PC moves Northwest");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '#';
            display[PC->getRow()-1][PC->getCol()-1] = '@';
            PC->addRow(-1);
            PC->addCol(-1);
        } else if (display[PC->getRow()-1][PC->getCol()-1] == 'G') {
            int goldNum = this->findGold(PC->getRow()-1, PC->getCol()-1);
            if (this->golds[goldNum]->getPickable()) {
                this->PC->changeAction("PC moves Northwest");
                display[PC->getRow()][PC->getCol()] = orig;
                orig = '.';
                display[PC->getRow()-1][PC->getCol()-1] = '@';
                PC->addRow(-1);
                PC->addCol(-1);
                this->PC->collectGold(this->golds[goldNum]->getGoldType());
            } else {
                throw Invalid;
            }
        } else if (display[PC->getRow()-1][PC->getCol()-1] == 'B') {
            if (this->barrierSuit->getPickable()) {
                this->PC->changeAction("PC moves Northwest and picked up the Barrier Suit");
                display[PC->getRow()][PC->getCol()] = orig;
                orig = '.';
                display[PC->getRow()-1][PC->getCol()-1] = '@';
                PC->addRow(-1);
                PC->addCol(-1);
                this->PC->armSuit();
            } else {
                throw Invalid;
            }
        } else if (display[PC->getRow()-1][PC->getCol()-1] == 'C') {
            this->PC->changeAction("PC moves South and picked up the Compass, the stair to the next floor has shown");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()-1][PC->getCol()-1] = '@';
            PC->addRow(-1);
            PC->addCol(-1);
            display[this->stair->getRow()][this->stair->getCol()] = '\\';
        } else {
            throw Invalid;
        }
    } else if (direction == "se") {
        if ((PC->getRow()+1 == stair->getRow() && PC->getCol()+1 == stair->getCol())){
            this->PC->changeAction("PC moves to the next Floor");
            PC->addRow(1);
            PC->addCol(1);
            clearFloor();
            setFloor(race);
        } else if (display[PC->getRow()+1][PC->getCol()+1] == '.') {
            this->PC->changeAction("PC moves Southeast");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()+1][PC->getCol()+1] = '@';
            PC->addRow(1);
            PC->addCol(1);
            this->PC->changeAction("PC moves Southeast");
        } else if (display[PC->getRow()+1][PC->getCol()+1] == '+') {
            this->PC->changeAction("PC moves Southeast");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '+';
            display[PC->getRow()+1][PC->getCol()+1] = '@';
            PC->addRow(1);
            PC->addCol(1);
            this->PC->changeAction("PC moves Southeast");
        } else if (display[PC->getRow()+1][PC->getCol()+1] == '#') {
            this->PC->changeAction("PC moves Southeast");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '#';
            display[PC->getRow()+1][PC->getCol()+1] = '@';
            PC->addRow(1);
            PC->addCol(1);
        } else if (display[PC->getRow()+1][PC->getCol()+1] == 'G') {
            int goldNum = this->findGold(PC->getRow()+1, PC->getCol()+1);
            if (this->golds[goldNum]->getPickable()) {
                this->PC->changeAction("PC moves Southeast");
                display[PC->getRow()][PC->getCol()] = orig;
                orig = '.';
                display[PC->getRow()+1][PC->getCol()+1] = '@';
                PC->addRow(1);
                PC->addCol(1);
                this->PC->collectGold(this->golds[goldNum]->getGoldType());
            } else {
                throw Invalid;
            }
        } else if (display[PC->getRow()+1][PC->getCol()+1] == 'B') {
            if (this->barrierSuit->getPickable()) {
                this->PC->changeAction("PC moves Southeast and picked up the Barrier Suit");
                display[PC->getRow()][PC->getCol()] = orig;
                orig = '.';
                display[PC->getRow()+1][PC->getCol()+1] = '@';
                PC->addRow(1);
                PC->addCol(1);
                this->PC->armSuit();
            } else {
                throw Invalid;
            }
        } else if (display[PC->getRow()+1][PC->getCol()+1] == 'C') {
            this->PC->changeAction("PC moves South and picked up the Compass, the stair to the next floor has shown");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()+1][PC->getCol()+1] = '@';
            PC->addRow(1);
            PC->addCol(1);
            display[this->stair->getRow()][this->stair->getCol()] = '\\';
        }else {
            throw Invalid;
        }
    } else if (direction == "sw") {
        if ((PC->getRow()+1 == stair->getRow() && PC->getCol()-1 == stair->getCol())){
            this->PC->changeAction("PC moves to the next Floor");
            PC->addRow(1);
            PC->addCol(-1);
            clearFloor();
            setFloor(race);
        } else if (display[PC->getRow()+1][PC->getCol()-1] == '.') {
            this->PC->changeAction("PC moves Southwest");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()+1][PC->getCol()-1] = '@';
            PC->addRow(1);
            PC->addCol(-1);
            this->PC->changeAction("PC moves Southwest");
        } else if (display[PC->getRow()+1][PC->getCol()-1] == '+') {
            this->PC->changeAction("PC moves Southwest");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '+';
            display[PC->getRow()+1][PC->getCol()-1] = '@';
            PC->addRow(1);
            PC->addCol(-1);
            this->PC->changeAction("PC moves Southwest");
        } else if (display[PC->getRow()+1][PC->getCol()-1] == '#') {
            this->PC->changeAction("PC moves Southwest");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '#';
            display[PC->getRow()+1][PC->getCol()-1] = '@';
            PC->addRow(1);
            PC->addCol(-1);
        } else if (display[PC->getRow()+1][PC->getCol()-1] == 'G') {
            int goldNum = this->findGold(PC->getRow()+1, PC->getCol()-1);
            if (this->golds[goldNum]->getPickable()) {
                this->PC->changeAction("PC moves Southwest");
                display[PC->getRow()][PC->getCol()] = '.';
                orig = '.';
                display[PC->getRow()+1][PC->getCol()-1] = '@';
                PC->addRow(1);
                PC->addCol(-1);
                this->PC->collectGold(this->golds[goldNum]->getGoldType());
            } else {
                throw Invalid;
            }
        } else if (display[PC->getRow()+1][PC->getCol()-1] == 'B') {
            if (this->barrierSuit->getPickable()) {
                this->PC->changeAction("PC moves Southwest and picked up the Barrier Suit");
                display[PC->getRow()][PC->getCol()] = '.';
                orig = '.';
                display[PC->getRow()+1][PC->getCol()-1] = '@';
                PC->addRow(1);
                PC->addCol(-1);
                this->PC->armSuit();
            } else {
                throw Invalid;
            }
        } else if (display[PC->getRow()+1][PC->getCol()-1] == 'C') {
            this->PC->changeAction("PC moves South and picked up the Compass, the stair to the next floor has shown");
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()+1][PC->getCol()-1] = '@';
            PC->addRow(+1);
            PC->addCol(-1);
            display[this->stair->getRow()][this->stair->getCol()] = '\\';
        } else {
            throw Invalid;
        }
    }
    randMoveAll();
    checkAround();
    wasAttack();
    

}


void Floor::setFloor(std::string race) {
    this->dragonGoldNum = 0;
    this->floorNum++;
    if (this->floorNum == 1) generatePC(race); 
    generateStair();
    //std::cout << "the stair is " << this->stair->getRow() << " " << this->stair->getCol() << std::endl;
    generatePotions();
    generateGolds();
    generateEnemies();
    setUpCompass();
    if (this->bSuitFloor == this->floorNum) generateBarrierSuit();
}


void Floor::clearFloor(std::string map) {
    this->stair = nullptr;
    this->potions.clear();
    this->golds.clear();
    this->enemies.clear();
    PC->setCurDef(PC->getDef()-PC->getCurDef());
    PC->setCurAtk(PC->getAtk()-PC->getCurAtk());
    std::vector<std::vector<char>> newDisplay;
    ifstream gameMap {map};
    string s;
    int len;
    while (getline(gameMap, s)) {
        vector<char> row;
        len = s.length();
        for (int i = 0; i < len; ++i) {
            row.emplace_back(s[i]);
        }
        newDisplay.emplace_back(row);
	}
    newDisplay[this->PC->getRow()][this->PC->getCol()] = '@';
}


void Floor::generatePC(std::string race) {

    Coordinate coor = getRandomCoorinate();
    int r = coor.row;
    int c = coor.col;

    if (race == "H") PC = make_shared<Human>();
    if (race == "D") PC = make_shared<Drawf>();
    if (race == "E") PC = make_shared<Elves>();
    if (race == "O") PC = make_shared<Orc>();
    this->display[r][c] = PC->getRepChar();
    PC->setRow(r);
    PC->setCol(c);
}


void Floor::generateStair() {
    Coordinate coor = getRandomCoorinate();
    int r = coor.row;
    int c = coor.col;
    this->stair = make_shared<Stair>(r, c);
}


void Floor::genOnePotion() {
    Coordinate coor;
    while (true) { // regenerate a coor if the point is on stair
        coor = getRandomCoorinate();
        int row = coor.row;
        int col = coor.col;
        if (!this->stair->isSameCoor(row, col)) break;
    }
    int r = coor.row;
    int c = coor.col;
    std::vector<int> ranPotion = {0, 1, 2, 3, 4, 5};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::shuffle(ranPotion.begin(), ranPotion.end(), rng); 
    int PotionType = ranPotion[0];
    this->potions.emplace_back(std::make_shared<Potion>(r, c, PotionType));
    this->display[r][c] = potions.back()->getRepChar();
}


void Floor::generatePotions() {
    for (int i = 0; i < 10; i++) {
        genOnePotion();
    }
}


void Floor::genOneGold() {
    Coordinate coor;
    while (true) { // regenerate a coor if the point is on stair
        coor = getRandomCoorinate();
        int row = coor.row;
        int col = coor.col;
        if (!this->stair->isSameCoor(row, col)) break;
    }
    int r = coor.row;
    int c = coor.col;
    std::vector<int> ranGold = {6, 6, 6, 6, 6, 7, 7, 9};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::shuffle(ranGold.begin(), ranGold.end(), rng); 
    int GoldType = ranGold[0];
    if (GoldType == 9) {
        this->golds.emplace_back(std::make_shared<Gold>(r, c, GoldType, false));
    } else {
        this->golds.emplace_back(std::make_shared<Gold>(r, c, GoldType, true));
    }
    this->display[r][c] = this->golds.back()->getRepChar();
}


void Floor::generateGolds() {
    for (int i = 0 ; i < 10 ; i++) {
        genOneGold();
    }
    for (auto gold : this->golds) {
        if (gold->getGoldType() == 9) {
            this->dragonGoldNum++;
            std::vector<int> ranPos = {1, 2, 3, 4, 5, 6, 7, 8};
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::default_random_engine rng{seed};
            std::shuffle(ranPos.begin(), ranPos.end(), rng); 
            int pos = ranPos[0];
            Coordinate coor;
            
            while (true) { 
                if (pos == 1) {
                    coor = {(gold->getRow() - 1), (gold->getCol() - 1)};
                }
                if (pos == 2) {
                    coor = {(gold->getRow() - 1), (gold->getCol())};
                }
                if (pos == 3) {
                    coor = {(gold->getRow() - 1), (gold->getCol() + 1)};
                }
                if (pos == 4) {
                    coor = {(gold->getRow()), (gold->getCol() - 1)};
                }
                if (pos == 5) {
                    coor = {(gold->getRow()), (gold->getCol() + 1)};
                }
                if (pos == 6) {
                    coor = {(gold->getRow() + 1), (gold->getCol() - 1)};
                }
                if (pos == 7) {
                    coor = {(gold->getRow() + 1), (gold->getCol())};
                }
                if (pos == 8) {
                    coor = {(gold->getRow() + 1), (gold->getCol() + 1)};
                }   
                int row = coor.row;
                int col = coor.col;
                if ((!this->stair->isSameCoor(row, col)) && 
                    (this->display[row][col] == '.')) { 
                        break; 
                } else {
                    std::shuffle(ranPos.begin(), ranPos.end(), rng); 
                    pos = ranPos[0];
                }

            }
            int r = coor.row;
            int c = coor.col;
            this->enemies.emplace_back(std::make_shared<Dragon>());
            this->display[r][c] = enemies.back()->getRepChar();
            enemies.back()->setRow(r);
            enemies.back()->setCol(c);
        }
    }
}


void Floor::genOneEnemy() {
    Coordinate coor;
    while (true) { // regenerate a coor if the point is on stair
        coor = getRandomCoorinate();
        int row = coor.row;
        int col = coor.col;
        if (!this->stair->isSameCoor(row, col)) break;
    }
    int r = coor.row;
    int c = coor.col;
    std::vector<int> ranEnemy = {1, 1, 1, 2, 2, 2, 2, 3, 3, 
                                    4, 4, 4, 4, 4, 5, 5, 6, 6};
                                     // all type of enemy except Dragon;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::shuffle(ranEnemy.begin(), ranEnemy.end(), rng);
    int enemyType = ranEnemy[0];
    if (enemyType == 1) this->enemies.emplace_back(std::make_shared<Vampire>());
    if (enemyType == 2) this->enemies.emplace_back(std::make_shared<Werewolf>());
    if (enemyType == 3) this->enemies.emplace_back(std::make_shared<Troll>());
    if (enemyType == 4) this->enemies.emplace_back(std::make_shared<Goblin>());
    if (enemyType == 5) {
        if (this->attackedMer) {
            this->enemies.emplace_back(std::make_shared<Merchant>(30, 70, 5, "Merchant", 'M', 10, 10, true,true));
        } else {
            this->enemies.emplace_back(std::make_shared<Merchant>());
        }
    }
    
    if (enemyType == 6) this->enemies.emplace_back(std::make_shared<Phoenix>());
    this->display[r][c] = enemies.back()->getRepChar();
    enemies.back()->setRow(r);
    enemies.back()->setCol(c);
}


void Floor::generateEnemies() {
    
    for (int i = 0; i < 20 - this->dragonGoldNum; i++) genOneEnemy();
}


void Floor::setUpCompass() {
    std::vector<int> ranEnemy;
    int curNum = 0;
    for(auto enemy : this->enemies) {
        ranEnemy.emplace_back(curNum);
        curNum++;
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::shuffle(ranEnemy.begin(), ranEnemy.end(), rng);  
    int pickedEnemy = ranEnemy[0];
    this->enemies[pickedEnemy]->holdCompass();
}


void Floor::generateBarrierSuit() {
    Coordinate coor;
    while (true) { // regenerate a coor if the point is on stair
        coor = getRandomCoorinate();
        int row = coor.row;
        int col = coor.col;
        if (!this->stair->isSameCoor(row, col)) break;
    }
    int r = coor.row;
    int c = coor.col;
    
    this->barrierSuit = std::make_shared<BarrierSuit>(r, c);
    this->display[r][c] = this->barrierSuit->getRepChar();

    std::vector<int> ranPos = {1, 2, 3, 4, 5, 6, 7, 8};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::shuffle(ranPos.begin(), ranPos.end(), rng); 
    int pos = ranPos[0];
    Coordinate coor1;
            
    while (true) { 
        if (pos == 1) {
            coor1 = {(barrierSuit->getRow() - 1), (barrierSuit->getCol() - 1)};
        }
        if (pos == 2) {
            coor1 = {(barrierSuit->getRow() - 1), (barrierSuit->getCol())};
        }
        if (pos == 3) {
            coor1 = {(barrierSuit->getRow() - 1), (barrierSuit->getCol() + 1)};
        }
        if (pos == 4) {
            coor1 = {(barrierSuit->getRow()), (barrierSuit->getCol() - 1)};
        }
        if (pos == 5) {
            coor1 = {(barrierSuit->getRow()), (barrierSuit->getCol() + 1)};
        }
        if (pos == 6) {
            coor1 = {(barrierSuit->getRow() + 1), (barrierSuit->getCol() - 1)};
        }
        if (pos == 7) {
            coor1 = {(barrierSuit->getRow() + 1), (barrierSuit->getCol())};
        }
        if (pos == 8) {
            coor1 = {(barrierSuit->getRow() + 1), (barrierSuit->getCol() + 1)};
        }   
        int row = coor1.row;
        int col = coor1.col;
        if ((!this->stair->isSameCoor(row, col)) && 
            (this->display[row][col] == '.')) { 
                break; 
        } else {
            std::shuffle(ranPos.begin(), ranPos.end(), rng); 
            pos = ranPos[0];
        }

    }
    int r1 = coor.row;
    int c1 = coor.col;
    this->enemies.emplace_back(std::make_shared<Dragon>());
    this->display[r1][c1] = enemies.back()->getRepChar();
    enemies.back()->setRow(r1);
    enemies.back()->setCol(c1);
    
}


void Floor::checkAround() {
    int goldNum = 0;
    int potionNum = 0;
    int enemyNum = 0;
    int BSNum = 0;
    int staNum = 0;
    int passNum = 0;
    int checkAct = 0;
    int merNum = 0;
    int r = this->PC->getRow() - 1;
    int c = this->PC->getCol() - 1;
    if (display[r][c] == 'P') {
        potionNum++;
    } else if (display[r][c] == 'G') {
        goldNum++;
    } else if (display[r][c] == 'B') {
        BSNum++; 
    } else if (display[r][c] == '\\') {
        staNum++;
    } else if (display[r][c] == '+') {
        passNum++;
    } else if ((display[r][c] == 'M') && 
               (this->attackedMer)) {
        merNum++;
    } else if ((display[r][c] != '.') &&
               (display[r][c] != '-') &&
               (display[r][c] != '|') &&
               (display[r][c] != ' ') &&
               (display[r][c] != '#')) {
        enemyNum++;           
    }

    r = this->PC->getRow() - 1;
    c = this->PC->getCol();
    if (display[r][c] == 'P') {
        potionNum++;
    } else if (display[r][c] == 'G') {
        goldNum++;
    } else if (display[r][c] == 'B') {
        BSNum++; 
    } else if (display[r][c] == '\\') {
        staNum++;
    } else if (display[r][c] == '+') {
        passNum++;
    } else if ((display[r][c] == 'M') && 
               (this->attackedMer)) {
        merNum++;
    } else if ((display[r][c] != '.') &&
               (display[r][c] != '-') &&
               (display[r][c] != '|') &&
               (display[r][c] != ' ') &&
               (display[r][c] != '#')) {
        enemyNum++;           
    }

    r = this->PC->getRow() - 1;
    c = this->PC->getCol() + 1;
    if (display[r][c] == 'P') {
        potionNum++;
    } else if (display[r][c] == 'G') {
        goldNum++;
    } else if (display[r][c] == 'B') {
        BSNum++; 
    } else if (display[r][c] == '\\') {
        staNum++;
    } else if (display[r][c] == '+') {
        passNum++;
    } else if ((display[r][c] == 'M') && 
               (this->attackedMer)) {
        merNum++;
    } else if ((display[r][c] != '.') &&
               (display[r][c] != '-') &&
               (display[r][c] != '|') &&
               (display[r][c] != ' ') &&
               (display[r][c] != '#')) {
        enemyNum++;           
    }

    r = this->PC->getRow();
    c = this->PC->getCol() - 1;
    if (display[r][c] == 'P') {
        potionNum++;
    } else if (display[r][c] == 'G') {
        goldNum++;
    } else if (display[r][c] == 'B') {
        BSNum++; 
    } else if (display[r][c] == '\\') {
        staNum++;
    } else if (display[r][c] == '+') {
        passNum++;
    } else if ((display[r][c] == 'M') && 
               (this->attackedMer)) {
        merNum++;
    } else if ((display[r][c] != '.') &&
               (display[r][c] != '-') &&
               (display[r][c] != '|') &&
               (display[r][c] != ' ') &&
               (display[r][c] != '#')) {
        enemyNum++;           
    }

    r = this->PC->getRow();
    c = this->PC->getCol() + 1;
    if (display[r][c] == 'P') {
        potionNum++;
    } else if (display[r][c] == 'G') {
        goldNum++;
    } else if (display[r][c] == 'B') {
        BSNum++; 
    } else if (display[r][c] == '\\') {
        staNum++;
    } else if (display[r][c] == '+') {
        passNum++;
    } else if ((display[r][c] == 'M') && 
               (this->attackedMer)) {
        merNum++;
    } else if ((display[r][c] != '.') &&
               (display[r][c] != '-') &&
               (display[r][c] != '|') &&
               (display[r][c] != ' ') &&
               (display[r][c] != '#')) {
        enemyNum++;           
    }

    r = this->PC->getRow() + 1;
    c = this->PC->getCol() - 1;
    if (display[r][c] == 'P') {
        potionNum++;
    } else if (display[r][c] == 'G') {
        goldNum++;
    } else if (display[r][c] == 'B') {
        BSNum++; 
    } else if (display[r][c] == '\\') {
        staNum++;
    } else if (display[r][c] == '+') {
        passNum++;
    } else if ((display[r][c] == 'M') && 
               (this->attackedMer)) {
        merNum++;
    } else if ((display[r][c] != '.') &&
               (display[r][c] != '-') &&
               (display[r][c] != '|') &&
               (display[r][c] != ' ') &&
               (display[r][c] != '#')) {
        enemyNum++;           
    }

    r = this->PC->getRow() + 1;
    c = this->PC->getCol();
    if (display[r][c] == 'P') {
        potionNum++;
    } else if (display[r][c] == 'G') {
        goldNum++;
    } else if (display[r][c] == 'B') {
        BSNum++; 
    } else if (display[r][c] == '\\') {
        staNum++;
    } else if (display[r][c] == '+') {
        passNum++;
    } else if ((display[r][c] == 'M') && 
               (this->attackedMer)) {
        merNum++;
    } else if ((display[r][c] != '.') &&
               (display[r][c] != '-') &&
               (display[r][c] != '|') &&
               (display[r][c] != ' ') &&
               (display[r][c] != '#')) {
        enemyNum++;           
    }

    r = this->PC->getRow() + 1;
    c = this->PC->getCol() + 1;
    if (display[r][c] == 'P') {
        potionNum++;
    } else if (display[r][c] == 'G') {
        goldNum++;
    } else if (display[r][c] == 'B') {
        BSNum++; 
    } else if (display[r][c] == '\\') {
        staNum++;
    } else if (display[r][c] == '+') {
        passNum++;
    } else if ((display[r][c] == 'M') && 
               (this->attackedMer)) {
        merNum++;
    } else if ((display[r][c] != '.') &&
               (display[r][c] != '-') &&
               (display[r][c] != '|') &&
               (display[r][c] != ' ') &&
               (display[r][c] != '#')) {
        enemyNum++;           
    }
    string act = "sees ";
    if (goldNum == 1) {
        act.append("a gold");
        checkAct++;
    } else if (goldNum > 1) {
        stringstream ss1;
        string s1;
        ss1 << goldNum;
        ss1 >> s1;
        act.append(s1);
        act.append(" golds");
        checkAct++;
    }
    if (potionNum == 1) {
        if (checkAct != 0) act.append(", ");
        act.append("an unknown potion");
        checkAct++;
    } else if (potionNum > 1) {
        if (checkAct != 0) act.append(", ");
        stringstream ss1;
        string s1;
        ss1 << potionNum;
        ss1 >> s1;
        act.append(s1);
        act.append(" unknown potions");
        checkAct++;
    }
    if (BSNum == 1) {
        if (checkAct != 0) act.append(", ");
        act.append("a Barrier Suit");
        checkAct++;
    } 
    if (merNum == 1) {
        if (checkAct != 0) act.append(", ");
        act.append("a friendly merchant");
        checkAct++;
    } else if (merNum > 1) {
        if (checkAct != 0) act.append(", ");
        stringstream ss1;
        string s1;
        ss1 << merNum;
        ss1 >> s1;
        act.append(s1);
        act.append(" friendly merchant");
        checkAct++;
    }
    if (enemyNum == 1) {
        if (checkAct != 0) act.append(", ");
        act.append("an enemy");
        checkAct++;
    } else if (enemyNum > 1) {
        if (checkAct != 0) act.append(", ");
        stringstream ss1;
        string s1;
        ss1 << enemyNum;
        ss1 >> s1;
        act.append(s1);
        act.append(" enemies");
        checkAct++;
    }
    if (passNum == 1) {
        if (checkAct != 0) act.append(", ");
        act.append("a door connect to other chamber");
        checkAct++;
    } else if (passNum > 1) {
        if (checkAct != 0) act.append(", ");
        stringstream ss1;
        string s1;
        ss1 << passNum;
        ss1 >> s1;
        act.append(s1);
        act.append(" doors connect to other chamber");
        checkAct++;
    }
    if (staNum == 1) {
        if (checkAct != 0) act.append(", ");
        act.append("a stair to next floor");
        checkAct++;
    }
    if (checkAct > 0) {
        this->PC->addAction(act);
    }
}


int Floor::findGold(int row, int col) {
    int goldNum = 0;
    for (auto gold : this->golds) {
        if((gold->getRow() == row) && (gold->getCol() == col)) {
            return goldNum;
        } else {
            goldNum++;
        }
    }
    return -1;
}


std::ostream &operator<<(std::ostream &out, const Floor &g) {
   for (auto r : g.display) {
        for (auto c : r) {
            out << c;
        }
        out << endl;
    }

    out << "Race: " << g.PC->getRace() << " Gold: " 
                    << g.PC->getGoldTotal() << "                                                  Floor " << g.floorNum << endl;
    out << "HP: " << g.PC->getCurHP() << endl;
    out << "Atk: " << g.PC->getCurAtk() << endl;
    out << "Def: " << g.PC->getCurDef() << endl;
    out << "Action: " << g.PC->getAction() << "." << endl;
    return out;
}


void Floor::randMove(shared_ptr<Enemy> e) {
    vector<int> index1 = {-1,0,1};
    vector<int> index2 = {-1,0,1};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::shuffle(index1.begin(), index1.end(), rng);
    std::shuffle(index2.begin(), index2.end(), rng);
    int first = index1[0];
    int second = index2[0];
    
    // in case some char cannot move
    for(int i = 0; i < 100; i++) {
        if (e->getMoveable()) {
            if (e->getRow()+first == stair->getRow() &&
                e->getCol()+second == stair->getCol()) {
                }
            else {
                if (display[e->getRow()+first][e->getCol()+second] == '.') {
                    display[e->getRow()][e->getCol()]  = '.';
                    e->setRow(e->getRow()+first);
                    e->setCol(e->getCol()+second);
                    display[e->getRow()][e->getCol()]  = e->getChar();
                    break;
                }
            }
        }
    }
}


void Floor::randMoveAll() {
    for (auto e: enemies) {
        randMove(e);
    }
}


shared_ptr<Potion> Floor::findPotion(int row, int col) {
    for (auto p : potions) {
        if (p->getRow() == row && p->getCol() == col) {
            return p;
        }
    }
    return nullptr;
}


void Floor::usePotion(shared_ptr<Potion> p) {
    
    if (p->getPotionType() == 0) {
        PC->setCurHP(10);
        PC->changeAction("Restore health (RH): restore up 10 HP");
    } else if (p->getPotionType() == 1) {
        PC->setCurAtk(5);
        PC->changeAction("Boost Atk (BA): increase Atk by 5");
    } else if (p->getPotionType() == 2) {
        PC->setCurDef(5);
        PC->changeAction("Boost Def (BD): increase Def by 5");
    } else if (p->getPotionType() == 3) {
        PC->setCurHP(-10);
        PC->changeAction("Poison health (PH): lose up to 10 HP (cannot fall below 0 HP)");
    } else if (p->getPotionType() == 4) {
        PC->setCurAtk(-5);
        PC->changeAction("Wound Atk (WA): decrease Atk by 5");
    } else if (p->getPotionType() == 5) {
        PC->setCurDef(-5);
        PC->changeAction("Wound Def (WD): decrease Def by 5");
    }
    
    display[p->getRow()][p->getCol()] = '.';
    
}


void Floor::drinkPotion() {
    InvalidCommand invalid;
    string direction;
    cout << "please give the direction of the potion you want to use (no|so|ea|we|ne|nw|se|sw): ";
    cin >> direction;
    if (direction == "no") {
        shared_ptr<Potion> p = findPotion(PC->getRow()-1, PC->getCol());
        if (display[PC->getRow()-1][PC->getCol()] != 'P') {
            cout << "Sorry, no potion in the no!" << endl;
            return;
        } else {
            usePotion(p);
        }
    } else if (direction == "so") {
        shared_ptr<Potion> p = findPotion(PC->getRow()+1, PC->getCol());
        if (display[PC->getRow()+1][PC->getCol()] != 'P') {
            cout << "Sorry, no potion in the so!" << endl;
            return;
        } else {
            usePotion(p);
        }
    } else if (direction == "we") {
        shared_ptr<Potion> p = findPotion(PC->getRow(), PC->getCol()-1);
        if (display[PC->getRow()][PC->getCol()-1] != 'P') {
            cout << "Sorry, no potion in the " << direction << "!" << endl;
            return;
        } else {
            usePotion(p);
        }
    } else if (direction == "ea") {
        shared_ptr<Potion> p = findPotion(PC->getRow(), PC->getCol()+1);
        if (display[PC->getRow()][PC->getCol()+1] != 'P') {
            cout << "Sorry, no potion in the " << direction << "!" << endl;
            return;
        } else {
            usePotion(p);
        }
    } else if (direction == "nw") {
        shared_ptr<Potion> p = findPotion(PC->getRow()-1, PC->getCol()-1);
        if (display[PC->getRow()-1][PC->getCol()-1] != 'P') {
            cout << "Sorry, no potion in the " << direction << "!" << endl;
            return;
        } else {
            usePotion(p);
        }
    } else if (direction == "ne") {
        shared_ptr<Potion> p = findPotion(PC->getRow()-1, PC->getCol()+1);
        if (display[PC->getRow()-1][PC->getCol()+1] != 'P') {
            cout << "Sorry, no potion in the " << direction << "!" << endl;
            return;
        } else {
            usePotion(p);
        }
    } else if (direction == "sw") {
        shared_ptr<Potion> p = findPotion(PC->getRow()+1, PC->getCol()-1);
        if (display[PC->getRow()+1][PC->getCol()-1] != 'P') {
            cout << "Sorry, no potion in the " << direction << "!" << endl;
            return;
        } else {
            usePotion(p);
        }
    } else if (direction == "se") {
        shared_ptr<Potion> p = findPotion(PC->getRow()+1, PC->getCol()+1);
        if (display[PC->getRow()+1][PC->getCol()+1] != 'P') {
            cout << "Sorry, no potion in the " << direction << "!" << endl;
            return;
        } else {
            usePotion(p);
        }
    } else {
        throw invalid;
    }
    
}


// used after every move
bool Floor::isWin() {
    if (floorNum > 5) {
        return true;
    }
    return false;
}


// used after every move and combat
bool Floor::isLose() {
    if (PC->getCurHP() <= 0) {
        return true;
    } else {
        return false;
    }
}


shared_ptr<Enemy> Floor::findEnemy(int r, int c) {
    
    for (auto e : enemies) {
        if (e->getRow() == r && e->getCol() == c) {
            return e;
        }
    }
    return nullptr;
}

int Floor::findEnemyIndex(int r, int c) {
    int i = 0;
    for (auto e : enemies) {
        if (e->getRow() == r && e->getCol() == c) {
            return i;
        } else {
            i++;
        }
    }
    return i;
}


void Floor::printFloor() {
    for (auto r : display) {
        for (auto c : r) {
            cout << c;
        }
        cout << endl;
    }
    
    cout << "Race: " << PC->getRace() << " Gold: " 
    << PC->getGoldTotal() << "                                                  Floor " << floorNum << endl;
    cout << "HP: " << PC->getCurHP() << endl;
    cout << "Atk: " << PC->getCurAtk() << endl;
    cout << "Def: " << PC->getCurDef() << endl;
    cout << "Action: " << PC->getAction() << "." << endl;
}

void Floor::attack(shared_ptr<Enemy> e, shared_ptr<Player> pc) {
    pc->attack(e);
    if (e->getCurHP() <= 0) {
        cout << e->getRepChar() << " dies! Good Job!" << endl;
        
        if (e->isHolder()) {
            display[e->getRow()][e->getCol()] = 'C';
            compass = make_shared<Compass>(e->getRow(),e->getCol());
        } else if (e->getRepChar() == 'D') {
            display[e->getRow()][e->getCol()] = '.';
            // set gold pickable
            for (auto g :  golds) {
                if ((g->getRow() - e->getRow()) <=1 && 
                    (g->getRow() - e->getRow()) >=-1 && 
                    (g->getCol() - e->getCol()) <=1 &&
                    (g->getCol()-e->getCol() >= -1)) {
                        g->canPick();
                    }
            }
            
            // set barrier suite pickable
            if (floorNum == bSuitFloor) {
                if ((barrierSuit->getRow() - e->getRow()) <=1 && 
                    (barrierSuit->getRow() - e->getRow()) >=-1 && 
                    (barrierSuit->getCol() - e->getCol()) <=1 &&
                    (barrierSuit->getCol()-e->getCol() >= -1)) {
                        barrierSuit->canPick();
                    }
            }
        } else {
            display[e->getRow()][e->getCol()] = '.';
        }
        printFloor();
    } else {
        cout << "You attack " << e->getRepChar() << ": Current HP: " << e->getCurHP() << endl;
        wasAttack();
        cout << "You Current HP: " << PC->getCurHP() << endl;
    }
}

void Floor::battle(string race) {
    for (auto e : enemies) {
        cout << e->getRepChar() << ": " << e->getRow() << ", " << e->getCol() << ", " << e->getIsHostile() << endl;
    }
    
    cout << "PC: " << PC->getRow() << ", " << PC->getCol() << endl;
    
    InvalidCommand invalid;
    string direction;
    
    cout << "please give the direction you want to attack (no|so|ea|we|ne|nw|se|sw): ";
    cin >> direction;
    if (direction == "no") {
        shared_ptr<Enemy> e = findEnemy(PC->getRow()-1, PC->getCol());
        int i = findEnemyIndex(PC->getRow()-1, PC->getCol());
        if (e == nullptr) {
            cout << "Sorry, no enemy in the no!" << endl;
            return;
        } else {
            attack(e, PC);
            if (e->getCurHP() <= 0) {
                enemies.erase(enemies.begin()+i);
            }
        }
    } else if (direction == "so") {
        shared_ptr<Enemy> e = findEnemy(PC->getRow()+1, PC->getCol());
        int i = findEnemyIndex(PC->getRow()+1, PC->getCol());
        if (e == nullptr) {
            cout << "Sorry, no enemy in the so!" << endl;
            return;
        } else {
            attack(e, PC);
            if (e->getCurHP() <= 0) {
                enemies.erase(enemies.begin()+i);
            }
        }
    } else if (direction == "we") {
        shared_ptr<Enemy> e = findEnemy(PC->getRow(), PC->getCol()-1);
        int i = findEnemyIndex(PC->getRow(), PC->getCol()-1);
        if (e == nullptr) {
            cout << "Sorry, no enemy in the " << direction << "!" << endl;
            return;
        } else {
            attack(e, PC);
            if (e->getCurHP() <= 0) {
                enemies.erase(enemies.begin()+i);
            }
        }
    } else if (direction == "ea") {
        shared_ptr<Enemy> e = findEnemy(PC->getRow(), PC->getCol()+1);
        int i = findEnemyIndex(PC->getRow(), PC->getCol()+1);
        if (e == nullptr) {
            cout << "Sorry, no enemy in the " << direction << "!" << endl;
            return;
        } else {
            attack(e, PC);
            if (e->getCurHP() <= 0) {
                enemies.erase(enemies.begin()+i);
            }
        }
    } else if (direction == "nw") {
        shared_ptr<Enemy> e = findEnemy(PC->getRow()-1, PC->getCol()-1);
        int i = findEnemyIndex(PC->getRow()-1, PC->getCol()-1);
        if (e == nullptr) {
            cout << "Sorry, no enemy in the " << direction << "!" << endl;
            return;
        } else {
            attack(e, PC);
            if (e->getCurHP() <= 0) {
                enemies.erase(enemies.begin()+i);
            }
        }
    } else if (direction == "ne") {
        shared_ptr<Enemy> e = findEnemy(PC->getRow()-1, PC->getCol()+1);
        int i = findEnemyIndex(PC->getRow()-1, PC->getCol()+1);
        if (e == nullptr) {
            cout << "Sorry, no enemy in the " << direction << "!" << endl;
            return;
        } else {
            attack(e, PC);
            if (e->getCurHP() <= 0) {
                enemies.erase(enemies.begin()+i);
            }
        }
    } else if (direction == "sw") {
        shared_ptr<Enemy> e = findEnemy(PC->getRow()+1, PC->getCol()-1);
        int i = findEnemyIndex(PC->getRow()+1, PC->getCol()-1);
        if (e == nullptr) {
            cout << "Sorry, no enemy in the " << direction << "!" << endl;
            return;
        } else {
            attack(e, PC);
            if (e->getCurHP() <= 0) {
                enemies.erase(enemies.begin()+i);
            }
        }
    } else if (direction == "se") {
        shared_ptr<Enemy> e = findEnemy(PC->getRow()+1, PC->getCol()+1);
        int i = findEnemyIndex(PC->getRow()+1, PC->getCol()+1);
        if (e == nullptr) {
            cout << "Sorry, no enemy in the " << direction << "!" << endl;
            return;
        } else {
            attack(e, PC);
            if (e->getCurHP() <= 0) {
                enemies.erase(enemies.begin()+i);
            }
        }
    } else {
        throw invalid;
    }
}





