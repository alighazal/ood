/*
* Assingment 1.3: OOD -- Prof. Kassas
* Student Name: Ali Ghazal
* Sudent ID: 900171722
* Deadline: 15/10/2021

* SortedArray Class Header File
*/


#ifndef SORTED_ARRAY
#define SORTED_ARRAY


#include <iostream>


class SortedArray {
    private:
        unsigned int * array;
        unsigned int arr_size;
        void sortArray();
        unsigned int size(int size);
    public:
        class Proxy{
            private:
                SortedArray &array;
                unsigned int index;
            public:
                Proxy(SortedArray &a, int i);
                operator unsigned int() const; 
                unsigned int operator= (int value);
                unsigned int value() {
                    return array.getAt(this->index);
                }
                friend std::ostream &operator<<( std::ostream &output, SortedArray::Proxy& el );
        };
       
        SortedArray();
        SortedArray(int size);
        SortedArray(const SortedArray& copy);
        SortedArray(SortedArray&& other);
        SortedArray& operator=(SortedArray&& other);
        void setAt(int index, unsigned int value);
        void insert(unsigned int value);
        const unsigned int getAt(int index) const;
        const unsigned int size() const;
        unsigned int operator= (unsigned int value);
        bool operator==(const SortedArray& another_array);
        Proxy operator[] (int index);
        const unsigned int& operator[] (int index) const;
        const void pretty_print() const;

        ~SortedArray();
        
};


#endif 