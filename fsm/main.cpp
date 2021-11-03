#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "FSM.hpp"

using namespace std;


int main(){

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