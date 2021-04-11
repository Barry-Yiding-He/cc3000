#include <iostream>
#include "floor.h"
using namespace std;


int main(int argc, char *argv[]) {
    cin.exceptions(ios::eofbit | ios::failbit);
    std::string cmd;
    Floor f;
    f.setFloor();
    cout << f;
    f.movePC("no");
    cout << f;
    f.movePC("so");
    cout << f;
    f.movePC("we");
    cout << f;
    f.movePC("ea");
    cout << f;
    f.movePC("ea");
    cout << f;

//    try {
//        cout << "Please pick a race to begin with:" << endl;
//        cout << "Human (type H)  Drawf (type D)  Elves (type E)  Orc (type O)" << endl;
//        while (true) {
//            if (cmd == "H") {
//                break;
//            } else if (cmd == "D") {
//                break;
//            } else if (cmd == "E") {
//                break;
//            } else if (cmd == "O") {
//                break;
//            } else {
//                cout << "Invalid race type, please choose from following:" << endl;
//                cout << "Human (type H)  Drawf (type D)  Elves (type E)  Orc (type O)" << endl;
//            }
//        }
//
//    } 
//    catch (ios::failure &) {
//    } // Any I/O failure quits
}