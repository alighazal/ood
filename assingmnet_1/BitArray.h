#ifndef BIT_ARRAY
#define BIT_ARRAY


#include <iostream>

class BitArray {

    private:
        unsigned int* array; 
        int size;

    public:
        BitArray(int);

        int Value(int) const;
        int Value(int, int);
        void printInternals();
        int const operator[] (int) const;
        ~BitArray();
};


#endif 