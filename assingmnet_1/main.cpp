/*
* Assingment 1: OOD -- Prof. Kassas
* Student Name: Ali Ghazal
* Sudent ID: 900171722
* Deadline: 7/10/2021

* Main Fucntion -- includes testing
*/


#include<iostream>
#include "BitArray.hpp"

using namespace std;


void test() {
    int index = 32*3+5;
    int size = 32*4;

    BitArray c(size);
    c.Value( index , 1); 
    cout << c.Value(index) << endl; // 1
    cout << c[index] << endl;       // 1
    c.Value(index, 0);
    cout << c[index] << endl;       // 0
    c[index] = 1;
    cout << c[index] << endl;       // 1

    c[0] = 1;
    c[1] = 1;
    c[2] = 1;
    c[3] = 1;
    c[4] = 1;
    c[5] = 1;
    c[6] = 1;
    c[7] = 1;

    c.printInternals(); // [255, 0, 0, 32 ]

    try {
        BitArray d(-50);            // Exception
    } catch (exception& e){
        cout << e.what() << endl;
    }

    try {
        c[32*3 + 5] = 8;            // Exception
    } catch (exception& e){
        cout << e.what() << endl;
    }

}


int main() {

    test();
    return 0;

}