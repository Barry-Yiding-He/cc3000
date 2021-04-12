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
    generateEnemy();
    
}

void Floor::generatePC(std::string race) {
    // we just set a default PC at a specific point here; random later
    int r = 5;
    int c = 6; 
    if (race == "H") PC = make_shared<Human>();
    if (race == "D") PC = make_shared<Human>();
    if (race == "E") PC = make_shared<Human>();
    if (race == "O") PC = make_shared<Human>();
    display[r][c] = PC->getRepChar();
    PC->setRow(5);
    PC->setCol(6);
}

void Floor::generateEnemy() {
    int r = 5;
    int c = 8;
    shared_ptr<Enemy> Gob = make_shared<Goblin>();
    display[r][c] = Gob->getRepChar();
    Gob->setRow(5);
    Gob->setCol(8);
    enemies.emplace_back(Gob);
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