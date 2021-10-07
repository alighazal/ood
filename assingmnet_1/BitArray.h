#ifndef BIT_ARRAY
#define BIT_ARRAY


#include <iostream>

class BitArray {

    private:
        class BitsContainer{
            private:
                unsigned int bitContainer;

            public:
                BitsContainer();
                unsigned int& Value();
                BitsContainer& operator=(unsigned int);
                operator unsigned int() const { return this->bitContainer ; }
                unsigned int operator[] (int);

        };

        BitsContainer * array; 
        int size;

    public:
        BitArray(int);

        int Value(int) const;
        int Value(int, int);
        void printInternals();
        BitsContainer& operator[] (int);
        ~BitArray();
};


#endif 