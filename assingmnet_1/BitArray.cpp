#include "BitArray.hpp"
#include "headers.hpp"
#include <math.h>

using namespace std;


BitArray::BitArray(int size)
{

    if (size < 0){
        throw std::invalid_argument("Exception: size must be greater than or equal to 0");
    }

    this->size = size;
    int number_of_bytes = ceil(size / static_cast<double>(constants::BIT_SIZE));
    int number_of_unsigned_ints = ceil(number_of_bytes / static_cast<double>(sizeof(unsigned int)));
    this->array = new unsigned int[number_of_unsigned_ints];

    for( int i = 0; i < number_of_unsigned_ints; i++ ){
        this->array[i] = 0;
    } 

}

int BitArray::Value(int index) const
{

    int array_index = index / (constants::SIZE_UNSIGNED_INT);
    int bit_index = index % (constants::SIZE_UNSIGNED_INT);

    unsigned int mask = 1 << bit_index;

    return ((this->array[array_index] & mask) >> bit_index );
}

int BitArray::Value(int index, int value)
{

    int array_index = index / (constants::SIZE_UNSIGNED_INT);
    int bit_index = index % (constants::SIZE_UNSIGNED_INT);

    unsigned int mask = value << bit_index;

    (value == 1) ? this->array[array_index] |= mask : this->array[array_index] &= mask;

    return this->Value(index);

}

void BitArray::printInternals()
{

    int number_of_bytes = ceil(this->size / static_cast<double>(constants::BIT_SIZE));
    int number_of_unsigned_ints = ceil(number_of_bytes / static_cast<double>(sizeof(unsigned int)));

    cout << "number of bits:  " << this->size << endl;
    cout << "number of unsigned ints:  " << number_of_unsigned_ints << endl;
    cout << "number of bytes:  " << number_of_bytes << endl;

    cout << "array elements:   " << endl;
    for (int i = 0; i < number_of_unsigned_ints; i++)
    {
        cout << this->array[i] << "   ";
    }
    cout << endl;
}

BitArray::Proxy BitArray::operator[](int index) {
    return Proxy(*this, index); 
}

BitArray::~BitArray(){
    delete[] this->array;
}