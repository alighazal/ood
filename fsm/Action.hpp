
#ifndef ACTION
#define ACTION

using namespace std;
#include <iostream>
#include <thread>
#include <chrono>

#include "FSM.hpp"

class Action {
    public:
        virtual void execute() = 0; 
};

class PrintStringAction: public Action{
    private:
        FSM *fsm;
        string expression; 
    
    public:
        PrintStringAction( FSM *fsm, string s):expression(s), fsm(fsm) {}
        virtual void execute(){
            cout << "print string action --> " << this->expression << endl;
        };

};

class PrintExpressionAction: public Action{
    private:
        FSM *fsm;
        string expression; 
    
    public:
        PrintExpressionAction(FSM *fsm, string s):expression(s), fsm(fsm) {}
        virtual void execute(){
            cout << "print expression action --> " << this->expression << endl;
        };

};

class ExpressionAction: public Action{
    private:
        FSM *fsm;
        string expression; 
    
    public:
        ExpressionAction(FSM *fsm, string s):expression(s), fsm(fsm) {}
        virtual void execute(){
            cout << "expression action --> " << this->expression << endl;
        };

};

class SleepAction: public Action{
    private:
        FSM *fsm;
        int time; 

    
    public:
        SleepAction(FSM *fsm, int t):time(t), fsm(fsm) {}
        virtual void execute(){
            cout << "sleeping for --> " << this->time << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(this->time * 1000));
        };

};

class WaitAction: public Action{
    private:
        FSM *fsm;
    public:
        WaitAction(FSM *fsm): fsm(fsm){}
        virtual void execute(){
            cout << "waiting... " << endl;
        };

};

class EndAction: public Action{
    private:
        FSM *fsm;
    public:
        EndAction(FSM *fsm): fsm(fsm){}
        virtual void execute(){
            cout << "the end " << endl;
            exit(1);
        };
};

#endif 