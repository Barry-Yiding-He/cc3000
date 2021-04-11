#include "floor.h"
#include <fstream>

using namespace std;

int Floor::getFloorNum () {
    return this->floorNum;
}

Floor::Floor(string map)  {
    // read all char in map to display
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


void Floor::movePC(string direction) {
    // first we check if we can move; if we can,  then we move
    if (direction == "no") {
        cout << "in this " <<endl;
        if (display[PC->getRow()-1][PC->getCol()] == '.') {
            cout << "sub" << endl;
            display[PC->getRow()-1][PC->getCol()] = '@';
            display[PC->getRow()][PC->getCol()] = '.';
            PC->addRow(-1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '/'){
            setFloor();
        }
    } else if (direction == "so") {
        if (display[PC->getRow()+1][PC->getCol()] == '.') {
            display[PC->getRow()+1][PC->getCol()] = '@';
            display[PC->getRow()][PC->getCol()] = '.';
            PC->addRow(1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '/'){
            setFloor();
        }
    } else if (direction == "we") {
        if (display[PC->getRow()][PC->getCol()-1] == '.') {
            display[PC->getRow()][PC->getCol()-1] = '@';
            display[PC->getRow()][PC->getCol()] = '.';
            PC->addCol(-1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '/'){
            setFloor();
        }
    } else if (direction == "ea") {
        if (display[PC->getRow()][PC->getCol() + 1] == '.') {
            display[PC->getRow()][PC->getCol() + 1] = '@';
            display[PC->getRow()][PC->getCol()] = '.';
            PC->addCol(1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '/'){
            setFloor();
        }
    } else if (direction == "ne") {
        if (display[PC->getRow()-1][PC->getCol()+1] == '.') {
            display[PC->getRow()-1][PC->getCol()+1] = '@';
            display[PC->getRow()][PC->getCol()] = '.';
            PC->addRow(-1);
            PC->addCol(1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '/'){
            setFloor();
        }
    } else if (direction == "nw") {
        if (display[PC->getRow()-1][PC->getCol()-1] == '.') {
            display[PC->getRow()-1][PC->getCol()-1] = '@';
            display[PC->getRow()][PC->getCol()] = '.';
            PC->addRow(-1);
            PC->addCol(-1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '/'){
            setFloor();
        }
    } else if (direction == "se") {
        if (display[PC->getRow()+1][PC->getCol()+1] == '.') {
            display[PC->getRow()+1][PC->getCol()+1] = '@';
            display[PC->getRow()][PC->getCol()] = '.';
            PC->addRow(+1);
            PC->addCol(+1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '/'){
            setFloor();
        }
    } else if (direction == "sw") {
        if (display[PC->getRow()+1][PC->getCol()-1] == '.') {
            display[PC->getRow()+1][PC->getCol()-1] = '@';
            display[PC->getRow()][PC->getCol()] = '.';
            PC->addRow(+1);
            PC->addCol(-1);
        } else if (display[PC->getRow()-1][PC->getCol()] == '/'){
            setFloor();
        }
    }
}

void Floor::setFloor() {
    generatePC();
    generateEnemy();
    
}

void Floor::generatePC() {
    // we just set a default PC at a specific point here; random later
    int r = 5;
    int c = 6;
    display[r][c] = '@';
    PC = make_shared<Human>();
    PC->setRow(5);
    PC->setCol(6);
}

void Floor::generateEnemy() {
    int r = 5;
    int c = 8;
    display[r][c] = 'G';
    shared_ptr<Enemy> Gob = make_shared<Goblin>();
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
    return out;
}