#include "BitArray.h"
#include <math.h> 

using namespace std;

const int BIT_SIZE = 8;

BitArray::BitArray(int size) {

    // TODO handle bad initializations
    // initializations with negative sizes

    this->size = size;
    int number_of_bytes = ceil(size / static_cast<double>(BIT_SIZE)); 
    int number_of_unsigned_ints = ceil(number_of_bytes / static_cast<double>(sizeof(unsigned int)) ); 
    this->array = new unsigned int[number_of_unsigned_ints];

    for (int i = 0; i < number_of_unsigned_ints; i++) {
        this->array[i] = 0;
    }

    printInternals();

}


void BitArray::printInternals(){

    int number_of_bytes = ceil(this->size / static_cast<double>(BIT_SIZE)); 
    int number_of_unsigned_ints = ceil(number_of_bytes / static_cast<double>(sizeof(unsigned int)) ); 

    cout  << "number of bits:  " << this->size << endl;
    cout << "number of unsigned ints:  " <<  number_of_unsigned_ints << endl;
    cout << "number of bytes:  " <<   number_of_bytes << endl;
    
    cout << "array elements:   " << endl;
    for (int i = 0; i < number_of_unsigned_ints; i++) {
        cout << this->array[i]  << "   ";
    }
    cout << endl;
}