#include<iostream>
#include "BitArray.h"

using namespace std;


int main() {

    BitArray c(32*4);
    cout << c.Value(32*3+5) << endl;
    c.Value(32*3+5, 1);
    cout << c.Value(32*3+5) << endl;
    
    c.Value(32*3+5, 0);
    cout << c.Value(32*3+5) << endl;

    return 0;

}