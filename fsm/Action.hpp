
#ifndef ACTION
#define ACTION

using namespace std;
#include <iostream>
#include <thread>
#include <chrono>


class Action {
    public:
        virtual void execute() = 0; 
};

class PrintStringAction: public Action{
    private:
        string expression; 
    
    public:
        PrintStringAction(string s):expression(s) {}
        virtual void execute(){
            cout << "print string action --> " << this->expression << endl;
        };

};

class PrintExpressionAction: public Action{
    private:
        string expression; 
    
    public:
        PrintExpressionAction(string s):expression(s) {}
        virtual void execute(){
            cout << "print expression action --> " << this->expression << endl;
        };

};

class ExpressionAction: public Action{
    private:
        string expression; 
    
    public:
        ExpressionAction(string s):expression(s) {}
        virtual void execute(){
            cout << "expression action --> " << this->expression << endl;
        };

};

class SleepAction: public Action{
    private:
        int time; 
    
    public:
        SleepAction(int t):time(t) {}
        virtual void execute(){
            cout << "sleeping for --> " << this->time << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(this->time * 1000));
        };

};

class WaitAction: public Action{
    public:
        WaitAction(){}
        virtual void execute(){
            cout << "waiting... " << endl;
        };

};

class EndAction: public Action{
    public:
        EndAction(){}
        virtual void execute(){
            cout << "the end " << endl;
            exit(1);
        };
};



#endif 