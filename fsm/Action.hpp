
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
        virtual void execute(unordered_map<string, int> & vars){
            cout << "print string action --> " << this->expression << endl;
        };

};

class PrintExpressionAction: public Action{
    private:
        string expression; 
    
    public:
        PrintExpressionAction(string s):expression(s) {}
        virtual void execute(unordered_map<string, int> & vars){
            cout << "print expression action --> " << vars[this->expression] << endl;
        };

};

class ExpressionAction: public Action{
    private:
        string expression; 
        bool isNumber(const string& str) //TODO move to utilities 
        {
            for (char const &c : str) {
                if (std::isdigit(c) == 0) return false;
            }
            return true;
        }

        string removeWhiteSpaces(string s){
            string ns = "";
            for (int i = 0; i < s.length(); i++ ){
                if (s[i] != ' ') ns+=s[i];
            }
            return ns;
        }
        void executeExpression(unordered_map<string, int> & vars, string s){

            vector<string> expression_components;
            string temp = "";
            for (int i = 0; i < s.length(); i++){
                if (s[i] == '=' || s[i] == '+') {
                    expression_components.push_back(temp);
                    temp = "";
                }else{
                    temp += s[i];
                }
            }
            expression_components.push_back(temp);

            vars[expression_components[0]] = isNumber(expression_components[1])?  stoi(expression_components[1]) : vars[expression_components[1]];
            vars[expression_components[0]] += isNumber(expression_components[2])?  stoi(expression_components[2]) : vars[expression_components[2]];

            cout <<  '\t' <<"value of " << expression_components[0] << " = " << vars[expression_components[0]] << endl;
            
        }
    
    public:
        ExpressionAction(string s):expression(s) {}
        virtual void execute(unordered_map<string, int> & vars){
            cout << "expression action --> " << this->expression << endl;
            this->expression = removeWhiteSpaces(this->expression);
            executeExpression(vars, this->expression);
        };

};

class SleepAction: public Action{
    private:
        int time; 
    
    public:
        SleepAction(int t):time(t) {}
        virtual void execute(unordered_map<string, int> & vars){
            cout << "sleeping for --> " << this->time << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(this->time * 1000));
        };

};

class WaitAction: public Action{
    public:
        WaitAction(){}
        virtual void execute(unordered_map<string, int> & vars){
            cout << "waiting... " << endl;
        };

};

class EndAction: public Action{
    public:
        EndAction(){}
        virtual void execute(unordered_map<string, int> & vars){
            cout << "the end " << endl;
            exit(1);
        };
};



#endif 