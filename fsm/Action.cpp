#include "Action.hpp"
#include "Utils.hpp"
#include <vector>

using namespace std;

void PrintStringAction::execute(unordered_map<string, int> & vars){
    cout << "print string action --> " << this->expression << endl;
};


void PrintExpressionAction::execute(unordered_map<string, int> & vars){
    if (vars.find(this->expression) == vars.end() ){
        throw out_of_range("this FSM used Variable \"" +  this->expression  + "\" that was not Decleared in the VARs Section");
    }
    cout << "print expression action --> " << vars[this->expression] << endl;
};

void ExpressionAction::executeExpression(unordered_map<string, int> & vars, string s){

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

    if (vars.find(expression_components[0]) == vars.end() ){
        throw out_of_range("this FSM used Variable \"" +  expression_components[0]  + "\" that was not Decleared in the VARs Section");
    }

    vars[expression_components[0]] = Utils::isNumber(expression_components[1])?  stoi(expression_components[1]) : vars[expression_components[1]];
    vars[expression_components[0]] += Utils::isNumber(expression_components[2])?  stoi(expression_components[2]) : vars[expression_components[2]];

    cout <<  '\t' <<"value of " << expression_components[0] << " = " << vars[expression_components[0]] << endl;
    
}

void ExpressionAction::execute(unordered_map<string, int> & vars){
    cout << "expression action --> " << this->expression << endl;
    this->expression = Utils::removeWhiteSpaces(this->expression);
    executeExpression(vars, this->expression);
};


void SleepAction::execute(unordered_map<string, int> & vars){
    cout << "sleeping for --> " << this->time << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(this->time * 1000));
};


void WaitAction::execute(unordered_map<string, int> & vars){
    cout << "waiting... " << endl;
};

void EndAction::execute(unordered_map<string, int> & vars){
    cout << "the end " << endl;
    exit(1);
};