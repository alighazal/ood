/*
* Assingment 1: OOD -- Prof. Kassas
* Student Name: Ali Ghazal
* Sudent ID: 900171722
* Deadline: 7/10/2021

* Proxy Class Implementation
*/


#include "SortedArray.hpp"
#include <iostream>

SortedArray::Proxy::Proxy(SortedArray &a, int i):array(a), index(i){}

SortedArray::Proxy::operator unsigned int() const{ // TODO make explicit
    return this->array.getAt(this->index); 
}

unsigned int SortedArray::Proxy::operator= (int value){
    
    this->array.setAt(this->index, value);
    return this->array.getAt(this->index);
}

std::ostream &operator<<( std::ostream &output, SortedArray::Proxy& el ) {
    output << el.value();
    return output;
}