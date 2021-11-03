#include <iostream>

using namespace std;

class Action{
    public:
        virtual void execute() = 0;
};
class ExampleAction: public Action{
    private:
        string expression; 
    
    public:
        ExampleAction(string s):expression(s) {}
        virtual void execute(){
            cout << this->expression << endl;
        };

};


int main (){

    ExampleAction s = ExampleAction("sssss");

    s.execute();

    Action* a = &s;

    a->execute();

    cout << "hello world" << endl;

    return 0;
}