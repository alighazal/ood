#include <iostream>
#include <vector>
#include "SortedArray.hpp"
#include "Utils.hpp"

using namespace std;




int main () {


    SortedArray s(5);

    try{
        s.insert(4);
        s.insert(44);
        s.insert(444);
        s.insert(4444);
        s.insert(444444);
        s.insert(44444444);

    }catch(exception& e){
        cout << e.what();
    }

    try{
      cout << s[15] << endl;
    }catch(exception& e){
        cout << e.what();
    }

    s[1] = 55;
    cout << s[1] << endl;

    s.pretty_print();

    /* Testing the copy constructor */
    SortedArray k(s);
    k.pretty_print();

    /* Testing the move constructor */
    vector<SortedArray> v;
    v.push_back(SortedArray(10));
    v.push_back(SortedArray(14));
    v.insert(v.begin() + 1, SortedArray(14));

    return 0;
}