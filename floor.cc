#include "floor.h"
#include <fstream>

using namespace std;

int Floor::getFloorNum () {
    return floorNum;
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


