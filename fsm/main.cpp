#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "FSM.hpp"

using namespace std;


int main(){

    /*
        TODO: refactor classes into header and functions files
        TODO: clean up dipatching of functions
        TODO: handle corrupted files
        TODO: add copy and move constructors
        TODO: add copy and move assingments 
    */


    string body = "";
    std::ifstream file("test.fsm");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            body += line + '\n';
        }
        file.close();
    }

    FSM fsm = FSM(body);

    fsm.runSimulation();

    return 0;
}