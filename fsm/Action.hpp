
#ifndef ACTION
#define ACTION

using namespace std;
#include <iostream>
#include <thread>
#include <unordered_map>
#include <chrono>


class Action {
    public:
        virtual void execute( unordered_map<string, int> & vars ) = 0; 
};

class PrintStringAction: public Action{
    private:
        string expression; 
    
    public:
        PrintStringAction(string s):expression(s) {}
        virtual void execute(unordered_map<string, int> & vars);
        ~PrintStringAction(){
            this->expression = "";
        }

};

class PrintExpressionAction: public Action{
    private:
        string expression; 
    
    public:
        PrintExpressionAction(string s):expression(s) {}
        virtual void execute(unordered_map<string, int> & vars);
        ~PrintExpressionAction(){
            this->expression = "";
        }

};

class ExpressionAction: public Action{
    private:
        string expression; 
        void executeExpression(unordered_map<string, int> & vars, string s);
    
    public:
        ExpressionAction(string s):expression(s) {}
        virtual void execute(unordered_map<string, int> & vars);
        ~ExpressionAction(){
            this->expression = "";
        }

};

class SleepAction: public Action{
    private:
        int time; 
    
    public:
        SleepAction(int t):time(t) {}
        virtual void execute(unordered_map<string, int> & vars);
        ~SleepAction(){
            this->time = 0;
        }

};

class WaitAction: public Action{
    public:
        WaitAction(){}
        virtual void execute(unordered_map<string, int> & vars);
        ~WaitAction(){
        }

};

class EndAction: public Action{
    public:
        EndAction(){}
        virtual void execute(unordered_map<string, int> & vars);
        ~EndAction(){

        }
};

#endif 