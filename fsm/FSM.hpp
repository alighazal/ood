
#ifndef _FSM_
#define _FSM_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "Action.hpp"

using namespace std;
class FSM
{
private:
    class State
    {
        private:
            string name;
            vector<Action *> actions;
            FSM *fsm;

        public:
            State(FSM *fsm, string name, vector<Action *> actions)
                : name(name), actions(actions), fsm(fsm) {}

            string getName();
            State() : name("") {}
            void AddAction(Action *action);
            void executeActions();
    };

    string name;
    unordered_map<string, State> states_map;
    unordered_map<string, int> variables;
    unordered_map<string, unordered_map<int, string>> transitions_table;
    State currentState;

    vector<vector<string>> parseSections(vector<string> tokenized_lines);
    void parseStates(vector<vector<string>> states);
    void parse(string text);

public:
    FSM():name(""){};
    FSM(string text_body);
    string getName();
    void runSimulation();
};

#endif