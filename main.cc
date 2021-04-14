#include <iostream>
#include "floor.h"
using namespace std;


int main(int argc, char *argv[]) {
    cin.exceptions(ios::eofbit | ios::failbit);
    std::string cmd;
    Floor f;
    std::string playerRace;

    try {
        cout << "Please pick a race to begin with:" << endl;
        cout << "Human (type H)  Drawf (type D)  Elves (type E)  Orc (type O)" << endl;
        while (true) {
            //cin >> cmd;
            cmd = "H";
            if (cmd == "H") {
                playerRace = cmd;
                f.setFloor(playerRace);
                break;
            } else if (cmd == "D") {
                playerRace = cmd;
                f.setFloor(playerRace);
                break;
            } else if (cmd == "E") {
                playerRace = cmd;
                f.setFloor(playerRace);
                break;
            } else if (cmd == "O") {
                playerRace = cmd;
                f.setFloor(playerRace);
                break;
            } else {
                cout << "Invalid race type, please choose from the following:" << endl;
                cout << "Human (type H)  Drawf (type D)  Elves (type E)  Orc (type O)" << endl;
            }
        }
        cout << f;
        cout << "'@' is your current location. Right now you are able to move, good luck!" << endl;
        exit(1);
        while (cin >> cmd) {
            try {
                if (cmd == "move") {
                    cout << "Please choose the direction to move: (no|so|ea|we|ne|nw|se|sw)" << endl;
                    while (true) {
                        cin >> cmd;
                        if (cmd == "no"|| cmd == "so"|| cmd == "ea"|| cmd == "we"||
                            cmd == "ne"|| cmd == "nw"|| cmd == "se"|| cmd == "sw") {
                                f.movePC(cmd, playerRace);
                                cout << f;
                                break;
                            } else {
                                cout << "Invalid direction, Please choose from the following" << endl;
                                cout << "(no|so|ea|we|ne|nw|se|sw)" << endl;
                            }
                    }
                }
            } catch (InvalidCommand) { 
                cout << "Invalid Command" << endl;
                cin >> cmd;
            } 
        }
    } 
    catch (ios::failure &) {
    } // Any I/O failure quits
}