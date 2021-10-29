
#ifndef STATE
#define STATE

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

class FSM;

class State{

    private:
        string name;
        vector<Action*> actions;
    public:
        State(  string name, vector<Action*> actions)
            : name(name) 
            , actions(actions){}

        State()
            :name(""){}

        void AddAction(Action* action){
            actions.push_back(action);
        }
        string getName(){
            return this->name;
        }
        void executeActions(){
            cout << "Executing state "  << this->name <<  " actions ..." 
                << endl << "----------" << endl;
            for (auto & action : actions ){
                action->execute();
            }
            cout << "---------------------------" << endl << endl;
        }
};



#endif 