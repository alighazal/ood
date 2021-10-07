#ifndef BIT_ARRAY
#define BIT_ARRAY


#include <iostream>

#define BIT_SIZE 8
#define SIZE_UNSIGNED_INT sizeof(unsigned int) * BIT_SIZE

class BitArray {

    private:
        class Proxy{
            private:
                BitArray &array;
                int index;
            public:
                Proxy(BitArray &a, int i): array(a), index(i){}
                operator unsigned int() const {
                    return this->array.Value(this->index); 
                }
                unsigned int operator= (int value) { 
                    if (value != 0 && value != 1){
                        throw std::invalid_argument("Exception: you can only assign 0's and 1's");
                    }
                    this->array.Value(this->index, value);
                    return this->array.Value(this->index);
                }
        };

        unsigned int * array; 
        int size;

    public:
        BitArray(int);

        int Value(int) const;
        int Value(int, int);
        void printInternals();
        Proxy operator[] (int index);
        ~BitArray();
};


#endif 