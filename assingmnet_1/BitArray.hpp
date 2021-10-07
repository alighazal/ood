/*
* Assingment 1: OOD -- Prof. Kassas
* Student Name: Ali Ghazal
* Sudent ID: 900171722
* Deadline: 7/10/2021

* BitArray Class Header File
*/


#ifndef BIT_ARRAY
#define BIT_ARRAY


#include <iostream>


class BitArray {

    private:

        unsigned int * array; 
        int size;
        
        class Proxy{
            private:
                BitArray &array;
                int index;
            public:
                Proxy(BitArray &a, int i);
                operator unsigned int() const;
                unsigned int operator= (int value);
        };
       
    public:
        BitArray(int);
        int Value(int) const;
        int Value(int, int);
        void printInternals();
        Proxy operator[] (int index);
        ~BitArray();
};


#endif 