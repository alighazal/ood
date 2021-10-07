#include<iostream>
#include "BitArray.h"

using namespace std;


int main() {

    BitArray c(32*4);
    c.Value(32*3+5, 1);
    cout << c[32*3+5] << endl;
    c.Value(32*3+5, 0);
    cout << c[32*3+5] << endl;
    c[32*3 + 5] = 1;
    cout << c[32*3+5] << endl;



    return 0;

}