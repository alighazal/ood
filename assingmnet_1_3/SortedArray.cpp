
/*
* Assingment 1.3: OOD -- Prof. Kassas
* Student Name: Ali Ghazal
* Sudent ID: 900171722
* Deadline: 15/10/2021

* SortedArray Class Implementation
*/


#include "SortedArray.hpp"
#include "Utils.hpp"

using namespace std;


SortedArray::SortedArray()
    :arr_size(0),
    array(nullptr){ }

SortedArray::SortedArray(int size)
    :arr_size(size),
    array(nullptr){
    this->size(size);
    this->array = new unsigned int[this->size()];
    for (int i = 0; i < this->size(); i++){
        this->array[i] = UINT32_MAX;
    }
}

SortedArray::SortedArray(const SortedArray& copy) 
        :arr_size(copy.arr_size),
        array(nullptr)  {

    this->array = new unsigned int[this->arr_size];
    for (int i = 0; i < copy.size(); i++){
        this->array[i] = copy.getAt(i);
    }

}

SortedArray::SortedArray(SortedArray&& other) 
   :arr_size(0)
   ,array(nullptr)
{
    this->arr_size = other.arr_size;
    this->array = other.array;

    other.arr_size = 0;
    other.array = nullptr;

    cout << "Used Move Constructor :)" << endl; 
}


SortedArray& SortedArray::operator=(SortedArray&& other)
{
   cout << "In operator=(SortedArray&&) " << endl;

   if (this != &other)
   {
      // Free the existing resource.
      delete[] array;

      // Copy the data pointer and its length from the
      // source object.
      array = other.array;
      arr_size = other.arr_size;

      // Release the data pointer from the source object so that
      // the destructor does not free the memory multiple times.
      other.array = nullptr;
      other.arr_size = 0;
   }

   return *this;
}


void SortedArray::setAt(int index, unsigned int value){
    if (index > -1 && index < this->size()){
        this->array[index] = value;
        sortArray();
    }else{
        throw std::out_of_range("Exception: out of range");
    }
}

void SortedArray::insert(unsigned int value){
    
    int insertion_postion = -1;

    for (int i = 0; i < this->size(); i++){
        if ( this->array[i] > value ){
            insertion_postion = i;
            break;
        }
    }

    if (insertion_postion == -1) throw std::length_error("Exception: you exceded the length of the array \n");

    int temp = this->array[insertion_postion];

    for (int i = this->size() - 2; i >= insertion_postion ; i-- ){
        this->array[i+1] =  this->array[i];
    }

    this->array[insertion_postion] = value;
}

const unsigned int SortedArray::getAt(int index) const{
    if (index > -1 && index < this->size()){
        return this->array[index];
    }else{
        throw std::out_of_range("Exception: out of range \n");
    }
}

const unsigned int SortedArray::size() const{
    return this->arr_size;
}

unsigned int SortedArray::size(int size){

    if (size > 0){
        return this->arr_size = size;
    }else{
       throw std::invalid_argument("Exception: size must be greater than 0"); 
    }
}

SortedArray::Proxy SortedArray::operator[] (int index){

    if (index > -1 && index < this->size()){
        return Proxy(*this, index); 
    }else{
        throw std::out_of_range("Exception: out of range \n");
    }
    
}

const unsigned int& SortedArray::operator[] (int index) const{
    if (index > -1 && index < this->size()){
        return this->array[index];
    }else{
        throw std::out_of_range("Exception: out of range");
    }

    
}


void SortedArray::sortArray(){
    int start = 0;
    int end = this->size()-1;
    Utils::quickSort( this->array , start, end);
}

bool SortedArray::operator== (const SortedArray& another_array) {
    //TODO boundy checking
    bool isEqual = true;
    if (this->size() != another_array.size()) return false;

    for (int i = 0; i < this->size(); i++){
        if (this->array[i] != another_array[i])
            return false;
    }

    return true;
}


const void SortedArray::pretty_print() const{

    for (int i = 0; i < this->size(); i++){
        cout << i << "  -  " << this->getAt(i) << endl;
    }
    cout << " --------"  << endl;

}

SortedArray::~SortedArray() {
    delete[] this->array;
    this->array = nullptr;
}

