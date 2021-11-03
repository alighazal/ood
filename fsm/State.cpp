#include "FSM.hpp"
#include "Utils.hpp"

using namespace std;

void FSM::State::AddAction(Action *action)
{
    actions.push_back(action);
}

string FSM::State::getName()
{
    return this->name;
}

void FSM::State::executeActions()
{
    cout << "Executing state " << Utils::Captialize(this->name) << " actions ..."
         << endl
         << "----------" << endl;

    for (auto &action : actions)
    {
        action->execute(this->fsm->variables);
    }

    cout << "---------------------------" << endl
         << endl;
}

void FSM::State::clear(){

    this->name = "";
    this->fsm = nullptr;
    this->actions.clear();
}

FSM::State::State(const State& copy){
    this->name = copy.name;
    this->fsm = copy.fsm;
    this->actions = copy.actions;
}

FSM::State& FSM::State::operator=(const State& copy){

    if (this != &copy)
    {
        this->name = copy.name;
        this->fsm = copy.fsm;
        this->actions = copy.actions;
    }

    return *this;

}

FSM::State::State(State&& other){

    this->name = other.name;
    this->fsm = other.fsm;
    this->actions = other.actions;

    other.name = "";
    other.fsm = nullptr;
    other.actions.clear();

}

FSM::State& FSM::State::operator=(State&& other){


    if (this != &other)
    {
        this->name = other.name;
        this->fsm = other.fsm;
        this->actions = other.actions;

        other.name = "";
        other.fsm = nullptr;
        other.actions.clear();
    }

    return *this;

}

FSM::State::~State(){
    this->clear();
}
