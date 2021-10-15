/*
* Assingment 1.3: OOD -- Prof. Kassas
* Student Name: Ali Ghazal
* Sudent ID: 900171722
* Deadline: 15/10/2021

* SortedArray Class Header File
*/


#ifndef UTILS
#define UTILS


#include <iostream>


class Utils {

    private:

    void static swap(unsigned int& a, unsigned int& b) 
    { 
        unsigned int t = a; 
        a = b; 
        b = t; 
    } 

    int static partition (unsigned int* arr, int low, int high) 
    { 
        unsigned int pivot = arr[high]; // pivot 
        unsigned int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    
        for (int j = low; j <= high - 1; j++) 
        { 
            // If current element is smaller than the pivot 
            if (arr[j] < pivot) 
            { 
                i++; // increment index of smaller element 
                swap(arr[i], arr[j]); 
            } 
        } 
        swap(arr[i + 1], arr[high]); 
        return (i + 1); 
    } 

    public:

    void static quickSort(unsigned int* arr, int low, int high) 
    { 
        if (low < high) 
        { 
            /* pi is partitioning index, arr[p] is now 
            at right place */
            int pi = partition(arr, low, high); 
    
            // Separately sort elements before 
            // partition and after partition 
            quickSort(arr, low, pi - 1); 
            quickSort(arr, pi + 1, high); 
        } 
    } 

};

#endif 