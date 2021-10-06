#include "BitArray.h"
#include <math.h>

using namespace std;

#define BIT_SIZE 8
#define SIZE_UNSIGNED_INT sizeof(unsigned int) * BIT_SIZE

BitArray::BitArray(int size)
{

    // TODO handle bad initializations
    // initializations with negative sizes

    this->size = size;
    int number_of_bytes = ceil(size / static_cast<double>(BIT_SIZE));
    int number_of_unsigned_ints = ceil(number_of_bytes / static_cast<double>(sizeof(unsigned int)));
    this->array = new unsigned int[number_of_unsigned_ints];

    for (int i = 0; i < number_of_unsigned_ints; i++)
    {
        this->array[i] = 0;
    }
}

int BitArray::Value(int index) const
{

    int array_index = index / (SIZE_UNSIGNED_INT);
    int bit_index = index % (SIZE_UNSIGNED_INT);

    unsigned int mask = 1 << bit_index;

    return ((this->array[array_index] & mask) >> bit_index);
}

int BitArray::Value(int index, int value)
{

    int array_index = index / (SIZE_UNSIGNED_INT);
    int bit_index = index % (SIZE_UNSIGNED_INT);

    unsigned int mask = value << bit_index;

    (value == 1) ? this->array[array_index] |= mask : this->array[array_index] &= mask;

    return this->Value(index);

}

void BitArray::printInternals()
{

    int number_of_bytes = ceil(this->size / static_cast<double>(BIT_SIZE));
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

int const BitArray::operator[](int index) const {
    return this->Value(index);
}

BitArray::~BitArray(){
    delete[] this->array;
}