#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool isSpeparator(char c) {
    if (c == ' ' || c == ',' ||  c == '\0' || c == '\n')
        return true;
    else return false;
}

vector<string> tokenizer(string text){

    vector<string> tokens; 
    
    string buffer = "";
    bool cont = false;
    for (int i = 0; i <= text.length(); i++ ){
        if (isSpeparator(text[i]) && !cont ){
            if (buffer != "")
                tokens.push_back(buffer);
            buffer = "";
        }else{
            if (text[i] == '\"') cont = !cont;
            buffer += text[i];
        }
    }

    return tokens;
}

void parse(string text){
    string buffer;
    vector<string> sections;

    buffer = "";
    for( int i = 0; i <= text.length(); i++){
        if(text[i] != '\n'){
            buffer += text[i];
        }else{
            sections.push_back(buffer);
            buffer = "";
        }
    }

    vector<string> ss; 

    for (auto & v: sections){
        vector<string> temp = tokenizer(v);
        ss.insert( ss.end(), temp.begin(), temp.end() );
    }

    
    vector<int> sections_indecies; 
    for (int i = 0; i < ss.size(); i++){
        if (ss[i] == "FSM"  || ss[i] == "VAR" || ss[i] == "States:" || ss[i] == "Transitions:" ){
            sections_indecies.push_back(i);
        } 

    }
    sections_indecies.push_back(ss.size());


    vector<vector<string>> parsed_sections;

    for (int i = 0; i < sections_indecies.size()-1; i++ ){

        vector<string> temp = vector<string>(&ss[sections_indecies[i]] , &ss[sections_indecies[i+1] ]);
        parsed_sections.push_back(  temp );
    }

    for (vector<string> &v: parsed_sections ){
        if (v[0] == "FSM") cout << "name --> "  << v[1] << endl;
        else if ( v[0] == "VAR"){
            cout << "Vars \n";
            for (int j = 1; j < v.size(); j++){
                cout << '\t' << j << ": " << v[j] << endl;
            }
        }
        else if ( v[0] == "States:"){
            cout << "States: \n";
            vector<vector<string>> states;
            vector<int> states_indecies; 

            for (int j = 1; j < v.size(); j++){
                if (v[j][ v[j].length()-1 ] == ':' ){
                    states_indecies.push_back(j);
                }
            }
            states_indecies.push_back(v.size());

            for (int j = 0; j < states_indecies.size() - 1; j++){
                states.push_back(vector<string>( &v[states_indecies[j]], &v[states_indecies[j+1]] ));
            } 
        }else{
            cout << "Transitions: \n";

            for (int j = 1; j < v.size(); j+=3){
                cout << '\t'  << v[j] << "  " <<  v[j+1] << "  " << v[j+2] << endl;
            }
        }
    }
    
}




int main(){

    string body = "";

    std::ifstream file("test.fsm");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            body += line + '\n';
        }
        file.close();
    }

    parse(body);

   

    return 0;
}