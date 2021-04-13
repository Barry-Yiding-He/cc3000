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


void Floor::movePC(string direction, std::string race) {
    InvalidCommand Invalid;
    // first we check if we can move; if we can,  then we move
    if (direction == "no") {
        if ((PC->getRow()-1 == stair->getRow() && PC->getCol() == stair->getCol())){
            setFloor(race);
        } else if (display[PC->getRow()-1][PC->getCol()] == '.') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()-1][PC->getCol()] = '@';
            PC->addRow(-1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '+') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '+';
            display[PC->getRow()-1][PC->getCol()] = '@';
            PC->addRow(-1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '#') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '#';
            display[PC->getRow()-1][PC->getCol()] = '@';
            PC->addRow(-1);
        } else {
            throw Invalid;
        }
    } else if (direction == "so") {
        if ((PC->getRow()+1 == stair->getRow() && PC->getCol() == stair->getCol())){
            setFloor(race);
        } else if (display[PC->getRow()+1][PC->getCol()] == '.') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()+1][PC->getCol()] = '@';
            PC->addRow(1);
        } else if (display[PC->getRow()+1][PC->getCol()] == '+') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '+';
            display[PC->getRow()+1][PC->getCol()] = '@';
            PC->addRow(1);
        } else if (display[PC->getRow()+1][PC->getCol()] == '#') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '#';
            display[PC->getRow()+1][PC->getCol()] = '@';
            PC->addRow(1);
        } else {
            throw Invalid;
        }
    } else if (direction == "we") {
        if ((PC->getRow() == stair->getRow() && PC->getCol()-1 == stair->getCol())){
            setFloor(race);
        } else if (display[PC->getRow()][PC->getCol()-1] == '.') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()][PC->getCol()-1] = '@';
            PC->addCol(-1);
        } else if (display[PC->getRow()][PC->getCol()-1] == '+') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '+';
            display[PC->getRow()][PC->getCol()-1] = '@';
            PC->addCol(-1);
        } else if (display[PC->getRow()][PC->getCol()-1] == '#') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '#';
            display[PC->getRow()][PC->getCol()-1] = '@';
            PC->addCol(-1);
        } else {
            throw Invalid;
        }
    } else if (direction == "ea") {
        if ((PC->getRow() == stair->getRow() && PC->getCol()+1 == stair->getCol())){
            setFloor(race);
        } else if (display[PC->getRow()][PC->getCol()+1] == '.') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()][PC->getCol()+1] = '@';
            PC->addCol(1);
        } else if (display[PC->getRow()][PC->getCol()+1] == '+') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '+';
            display[PC->getRow()][PC->getCol()+1] = '@';
            PC->addCol(1);
        } else if (display[PC->getRow()][PC->getCol()+1] == '#') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '#';
            display[PC->getRow()][PC->getCol()+1] = '@';
            PC->addCol(1);
        } else {
            throw Invalid;
        }
    } else if (direction == "ne") {
        if ((PC->getRow()-1 == stair->getRow() && PC->getCol()+1 == stair->getCol())){
            setFloor(race);
        } else if (display[PC->getRow()-1][PC->getCol()+1] == '.') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()-1][PC->getCol()+1] = '@';
            PC->addRow(-1);
            PC->addCol(1);
        } else if (display[PC->getRow()-1][PC->getCol()+1] == '+') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '+';
            display[PC->getRow()-1][PC->getCol()+1] = '@';
            PC->addRow(-1);
            PC->addCol(1);
        } else if (display[PC->getRow()-1][PC->getCol()+1] == '#') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '#';
            display[PC->getRow()-1][PC->getCol()+1] = '@';
            PC->addRow(-1);
            PC->addCol(1);
        } else {
            throw Invalid;
        }
    } else if (direction == "nw") {
        if ((PC->getRow()-1 == stair->getRow() && PC->getCol()-1 == stair->getCol())){
            setFloor(race);
        } else if (display[PC->getRow()-1][PC->getCol()-1] == '.') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()-1][PC->getCol()-1] = '@';
            PC->addRow(-1);
            PC->addCol(-1);
        } else if (display[PC->getRow()-1][PC->getCol()-1] == '+') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '+';
            display[PC->getRow()-1][PC->getCol()-1] = '@';
            PC->addRow(-1);
            PC->addCol(-1);
        } else if (display[PC->getRow()-1][PC->getCol()-1] == '#') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '#';
            display[PC->getRow()-1][PC->getCol()-1] = '@';
            PC->addRow(-1);
            PC->addCol(-1);
        } else {
            throw Invalid;
        }
    } else if (direction == "se") {
        if ((PC->getRow()+1 == stair->getRow() && PC->getCol()+1 == stair->getCol())){
            setFloor(race);
        } else if (display[PC->getRow()+1][PC->getCol()+1] == '.') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()+1][PC->getCol()+1] = '@';
            PC->addRow(1);
            PC->addCol(1);
        } else if (display[PC->getRow()+1][PC->getCol()+1] == '+') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '+';
            display[PC->getRow()+1][PC->getCol()+1] = '@';
            PC->addRow(1);
            PC->addCol(1);
        } else if (display[PC->getRow()+1][PC->getCol()+1] == '#') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '#';
            display[PC->getRow()+1][PC->getCol()+1] = '@';
            PC->addRow(1);
            PC->addCol(1);
        } else {
            throw Invalid;
        }
    } else if (direction == "sw") {
        if ((PC->getRow()+1 == stair->getRow() && PC->getCol()-1 == stair->getCol())){
            setFloor(race);
        } else if (display[PC->getRow()+1][PC->getCol()-1] == '.') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '.';
            display[PC->getRow()+1][PC->getCol()-1] = '@';
            PC->addRow(1);
            PC->addCol(-1);
        } else if (display[PC->getRow()+1][PC->getCol()-1] == '+') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '+';
            display[PC->getRow()+1][PC->getCol()-1] = '@';
            PC->addRow(1);
            PC->addCol(-1);
        } else if (display[PC->getRow()+1][PC->getCol()-1] == '#') {
            display[PC->getRow()][PC->getCol()] = orig;
            orig = '#';
            display[PC->getRow()+1][PC->getCol()-1] = '@';
            PC->addRow(1);
            PC->addCol(-1);
        } else {
            throw Invalid;
        }
    }
}


void Floor::setFloor(std::string race) {
    this->floorNum++;
    generatePC(race); 
    generateStair();
    generatePotions();
    generateEnemies();
}


void Floor::generatePC(std::string race) {
    // we just set a default PC at a specific point here; random later
    /*int r = 5;
    int c = 6; */

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
    if (enemyType == 5) this->enemies.emplace_back(std::make_shared<Merchant>());
    if (enemyType == 6) this->enemies.emplace_back(std::make_shared<Phoenix>());
    this->display[r][c] = enemies.back()->getRepChar();
    enemies.back()->setRow(r);
    enemies.back()->setCol(c);
}


void Floor::generateEnemies() {
    ///////////////////////////////////////////////////
    ///////////////////////////////////////////////////
    // 没有考虑龙 之后需要修改
    
    for (int i = 0; i < 20; i++) genOneEnemy();
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