#include "BitArray.h"
#include <stdexcept>

using namespace std;

#define BIT_SIZE 8
#define SIZE_UNSIGNED_INT sizeof(unsigned int) * BIT_SIZE


BitArray::BitsContainer::BitsContainer(){
    this->bitContainer = 0;
}

unsigned int& BitArray::BitsContainer::Value(){
    return this->bitContainer;
}

unsigned int BitArray::BitsContainer::operator[](int index){

    int bit_index = index % (SIZE_UNSIGNED_INT);
    unsigned int mask = 1 << bit_index;

    return (this->bitContainer & mask) >> bit_index;
}

BitArray::BitsContainer& BitArray::BitsContainer::operator=(unsigned int value ){
    if ( value != 0 && value != 1) {
        throw std::invalid_argument( "u are only allowed to assinged 0's and 1's" );
    }
    this->bitContainer = value;
    return *this;
}