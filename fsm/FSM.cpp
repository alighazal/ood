#include "FSM.hpp"
#include "Utils.hpp"

using namespace std;

FSM::FSM(string text_body)
{
    this->parse(text_body);
}


string FSM::getName()
{
    return this->name;
}

vector<vector<string>> FSM::parseSections(vector<string> tokenized_lines){
    vector<int> sections_indecies;
    for (int i = 0; i < tokenized_lines.size(); i++)
    {
        if (tokenized_lines[i] == "FSM" || tokenized_lines[i] == "VAR" 
            || tokenized_lines[i] == "States:" || tokenized_lines[i] == "Transitions:")
        {
            sections_indecies.push_back(i);
        }
    }
    sections_indecies.push_back(tokenized_lines.size());

    vector<vector<string>> parsed_sections;

    for (int i = 0; i < sections_indecies.size() - 1; i++)
    {
        vector<string> temp = vector<string>(&tokenized_lines[sections_indecies[i]], &tokenized_lines[sections_indecies[i + 1]]);
        parsed_sections.push_back(temp);
    }

    return parsed_sections;

}

void FSM::parseStates(vector<vector<string>> states ){
    vector<State> StatesClass;
    for (int i = 0; i < states.size(); i++)
    {
        vector<Action *> actions;
        states[i][0].pop_back();
        for (int j = 1; j < states[i].size();)
        {
            if (states[i][j] == "out")
            {
                if (states[i][j + 1][0] == '"') // quote
                { 
                    PrintStringAction *temp = new PrintStringAction(states[i][j + 1]);
                    actions.push_back(temp);
                }
                else
                {
                    PrintExpressionAction *temp = new PrintExpressionAction(states[i][j + 1]);
                    actions.push_back(temp);
                }
                j += 2;
            }
            else if (states[i][j] == "sleep")
            {
                SleepAction *temp = new SleepAction(stoi(states[i][j + 1]));
                actions.push_back(temp);
                j += 2;
            }
            else if (states[i][j] == "wait")
            {
                WaitAction *temp = new WaitAction();
                actions.push_back(temp);
                j += 1;
            }
            else if (states[i][j] == "end")
            {
                EndAction *temp = new EndAction();
                actions.push_back(temp);
                j += 1;
            }
            else
            {
                ExpressionAction *temp = new ExpressionAction(states[i][j]);
                actions.push_back(temp);
                j += 1;
            }
        }

        State temp = State(this, states[i][0], actions);
        StatesClass.push_back(temp);
        this->states_map[states[i][0]] = temp;
        if (i == 0)
            this->currentState = this->states_map[states[i][0]];
    }
}


void FSM::parse(string text)
{

    if (text.length() == 0){
        throw invalid_argument("FSM file is Empty !!");
    }
    
    vector<string> lines = Utils::splitByLine(text);
    
    vector<string> tokenized_lines;
    for (auto &line : lines)
    {
        vector<string> temp = Utils::tokenizer(line);
        tokenized_lines.insert(tokenized_lines.end(), temp.begin(), temp.end());
    }


    /** Parsing Sections **/
    vector<vector<string>> parsed_sections = parseSections(tokenized_lines);
    
    vector<vector<string>> states;    
    for (vector<string> &v : parsed_sections)
    {
        if (v[0] == "FSM")
        {
            this->name = v[1];
        }

        else if (v[0] == "VAR")
        {
            for (int j = 1; j < v.size(); j++)
            {
                this->variables[v[j]] = 0;
            }
        }

        else if (v[0] == "States:")
        {
            vector<int> states_indecies;
            for (int j = 1; j < v.size(); j++)
            {
                if (v[j][v[j].length() - 1] == ':')
                {
                    states_indecies.push_back(j);
                }
            }
            states_indecies.push_back(v.size());

            for (int j = 0; j < states_indecies.size() - 1; j++)
            {
                states.push_back(vector<string>(&v[states_indecies[j]], &v[states_indecies[j + 1]]));
            }
        }
        else
        {
            for (int j = 1; j < v.size(); j += 3)
            {
                this->transitions_table[v[j]][stoi(v[j + 2])] = v[j + 1];
            }
        }
    }
 
    /** Initializing FSM's State Objects **/
    parseStates(states);
}

void FSM::runSimulation()
{

    cout << "running Simulation of " << this->getName() << endl;

    char value;

    while (true)
    {
        this->states_map[this->currentState.getName()].executeActions();

        cout << "inset value" << endl;
        cin >> value;

        if (!isdigit(value)){
            throw invalid_argument("State Transitions Should Only be Numbers");
        }

        if (this->transitions_table[this->currentState.getName()].find(atoi(&value)) != this->transitions_table[this->currentState.getName()].end()){
            this->currentState = this->states_map[this->transitions_table[this->currentState.getName()][atoi(&value)]];
        }else{
            cout << "!! Unsupported Transition. Please Enter a Valid One !!" << endl;

        }

    }
}

