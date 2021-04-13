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
        //cout << "in this " <<endl;
        if (display[PC->getRow()-1][PC->getCol()] == '.') {
            //cout << "sub" << endl;
            display[PC->getRow()-1][PC->getCol()] = '@';
            display[PC->getRow()][PC->getCol()] = '.';
            PC->addRow(-1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '/'){
            setFloor(race);
        } else {
            throw Invalid;
        }
    } else if (direction == "so") {
        if (display[PC->getRow()+1][PC->getCol()] == '.') {
            display[PC->getRow()+1][PC->getCol()] = '@';
            display[PC->getRow()][PC->getCol()] = '.';
            PC->addRow(1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '/'){
            setFloor(race);
        } else {
            throw Invalid;
        }
    } else if (direction == "we") {
        if (display[PC->getRow()][PC->getCol()-1] == '.') {
            display[PC->getRow()][PC->getCol()-1] = '@';
            display[PC->getRow()][PC->getCol()] = '.';
            PC->addCol(-1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '/'){
            setFloor(race);
        } else {
            throw Invalid;
        }
    } else if (direction == "ea") {
        if (display[PC->getRow()][PC->getCol() + 1] == '.') {
            display[PC->getRow()][PC->getCol() + 1] = '@';
            display[PC->getRow()][PC->getCol()] = '.';
            PC->addCol(1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '/'){
            setFloor(race);
        } else {
            throw Invalid;
        }
    } else if (direction == "ne") {
        if (display[PC->getRow()-1][PC->getCol()+1] == '.') {
            display[PC->getRow()-1][PC->getCol()+1] = '@';
            display[PC->getRow()][PC->getCol()] = '.';
            PC->addRow(-1);
            PC->addCol(1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '/'){
            setFloor(race);
        } else {
            throw Invalid;
        }
    } else if (direction == "nw") {
        if (display[PC->getRow()-1][PC->getCol()-1] == '.') {
            display[PC->getRow()-1][PC->getCol()-1] = '@';
            display[PC->getRow()][PC->getCol()] = '.';
            PC->addRow(-1);
            PC->addCol(-1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '/'){
            setFloor(race);
        } else {
            throw Invalid;
        }
    } else if (direction == "se") {
        if (display[PC->getRow()+1][PC->getCol()+1] == '.') {
            display[PC->getRow()+1][PC->getCol()+1] = '@';
            display[PC->getRow()][PC->getCol()] = '.';
            PC->addRow(+1);
            PC->addCol(+1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '/'){
            setFloor(race);
        } else {
            throw Invalid;
        }
    } else if (direction == "sw") {
        if (display[PC->getRow()+1][PC->getCol()-1] == '.') {
            display[PC->getRow()+1][PC->getCol()-1] = '@';
            display[PC->getRow()][PC->getCol()] = '.';
            PC->addRow(+1);
            PC->addCol(-1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '/'){
            setFloor(race);
        } else {
            throw Invalid;
        }
    }
}

void Floor::setFloor(std::string race) {
    this->floorNum++;
    generatePC(race);
    generateEnemies();
}

void Floor::generatePC(std::string race) {
    // we just set a default PC at a specific point here; random later
    /*int r = 5;
    int c = 6; */

////////////////////////////////////////////////////
////////////////////////////////////////////////////
// 下面这个generate函数感觉需要单独写个Fun 因为都要generate 方法是一样的   generate的下面的代码我测试过了没问题

    // set a random row and col for PC
    std::vector<int> ranChamber = {1, 2, 3, 4, 5, 6}; // pick random chamber number from all chamber number
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::shuffle(ranChamber.begin(), ranChamber.end(), rng); // start to shuffle the order 
                                                             // and pick the first value in vector as our random value
    int chamberNum = ranChamber[0];
    int rowBegin = this->chambers[chamberNum]->getTop();   // locate the 4 info for the chamber we picked
    int rowEnd = this->chambers[chamberNum]->getBottom();   // 不想写了怎么说 就是先随机出来chamber 在随机row和col inside the chamber 
    int colBegin = this->chambers[chamberNum]->getLeft();
    int colEnd = this->chambers[chamberNum]->getRight();
    std::vector<int> ranRow;                            
    for (rowBegin; rowBegin < rowEnd; rowBegin++) ranRow.emplace_back(rowBegin);
    std::vector<int> ranCol;
    for (colBegin; colBegin < colEnd; colBegin++) ranCol.emplace_back(colBegin);

    std::shuffle(ranRow.begin(), ranRow.end(), rng);
    std::shuffle(ranCol.begin(), ranCol.end(), rng);
    int r = 0;
    int c = 0;
    while (true) {
        int row = ranRow[0];
        int col = ranCol[0];
        if (display[row][col] == '.') { 
        r = row; 
        c = col; 
        break;
        } else {
            std::shuffle(ranRow.begin(), ranRow.end(), rng);
            std::shuffle(ranCol.begin(), ranCol.end(), rng);
        }
    }
    // end of random set of row and col

    if (race == "H") PC = make_shared<Human>();
    if (race == "D") PC = make_shared<Human>();
    if (race == "E") PC = make_shared<Human>();
    if (race == "O") PC = make_shared<Human>();
    display[r][c] = PC->getRepChar();
    PC->setRow(r);
    PC->setCol(c);
}


// generate one random enemy
void Floor::genOneEnemy() {
      // set a random row and col for PC
    std::vector<int> ranChamber = {1, 2, 3, 4, 5, 6}; // pick random chamber number from all chamber number
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::shuffle(ranChamber.begin(), ranChamber.end(), rng); // start to shuffle the order 
                                                             // and pick the first value in vector as our random value
    int chamberNum = ranChamber[0];
    int rowBegin = this->chambers[chamberNum]->getTop();   // locate the 4 info for the chamber we picked
    int rowEnd = this->chambers[chamberNum]->getBottom();   // 不想写了怎么说 就是先随机出来chamber 在随机row和col inside the chamber 
    int colBegin = this->chambers[chamberNum]->getLeft();
    int colEnd = this->chambers[chamberNum]->getRight();
    std::vector<int> ranRow;                            
    for (rowBegin; rowBegin < rowEnd; rowBegin++) ranRow.emplace_back(rowBegin);
    std::vector<int> ranCol;
    for (colBegin; colBegin < colEnd; colBegin++) ranCol.emplace_back(colBegin);
    std::shuffle(ranRow.begin(), ranRow.end(), rng);
    std::shuffle(ranCol.begin(), ranCol.end(), rng);
    int r = 0;
    int c = 0;

    while (true) {
        int row = ranRow[0];
        int col = ranCol[0];
        if (display[row][col] == '.') { 
        r = row; 
        c = col; 
        break;
        } else {
            std::shuffle(ranRow.begin(), ranRow.end(), rng);
            std::shuffle(ranCol.begin(), ranCol.end(), rng);
        }
    }

    std::vector<int> ranEnemy = {1, 2, 3, 4, 5, 6}; // all type of enemy except Dragon;
    std::shuffle(ranEnemy.begin(), ranEnemy.end(), rng);
    int enemyNum = ranEnemy[0];
    if (enemyNum == 1) this->enemies.emplace_back(std::make_shared<Vampire>());
    if (enemyNum == 2) this->enemies.emplace_back(std::make_shared<Werewolf>());
    if (enemyNum == 3) this->enemies.emplace_back(std::make_shared<Troll>());
    if (enemyNum == 4) this->enemies.emplace_back(std::make_shared<Goblin>());
    if (enemyNum == 5) this->enemies.emplace_back(std::make_shared<Merchant>());
    if (enemyNum == 6) this->enemies.emplace_back(std::make_shared<Phoenix>());
    display[r][c] = enemies.back()->getRepChar();
    enemies.back()->setRow(r);
    enemies.back()->setCol(c);
    // end of random set of row and col
}

void Floor::generateEnemies() {
    /*
    int r = 5;
    int c = 8;
    shared_ptr<Enemy> Gob = make_shared<Goblin>();
    display[r][c] = Gob->getRepChar();
    Gob->setRow(5);
    Gob->setCol(8);*/
    genOneEnemy();
    genOneEnemy();
    genOneEnemy();
    genOneEnemy();
    genOneEnemy();
    genOneEnemy();
    genOneEnemy();
    genOneEnemy();
    genOneEnemy();

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