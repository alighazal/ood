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