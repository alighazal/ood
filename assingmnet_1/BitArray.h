#ifndef BIT_ARRAY
#define BIT_ARRAY


#include <iostream>

class BitArray {

    private:
        unsigned int* array; 
        int size;
        
        void printInternals();

    public:
        BitArray(int);
};


#endif 