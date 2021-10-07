#include "BitArray.hpp"

BitArray::Proxy::Proxy(BitArray &a, int i):array(a), index(i){}


BitArray::Proxy::operator unsigned int() const{
    return this->array.Value(this->index); 
}


unsigned int BitArray::Proxy::operator= (int value){
    if (value != 0 && value != 1){
        throw std::invalid_argument("Exception: you can only assign 0's and 1's");
    }
    this->array.Value(this->index, value);
    return this->array.Value(this->index);
}