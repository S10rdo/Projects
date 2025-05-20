#ifndef FLOATARRAY_H         //Joseph Kim
#define FLOATARRAY_H

#include <iostream>
#include <cassert>

class floatArray {
private:
    int maxValues;
    int numValues;
    float *data;
    
public:
    floatArray();                //Default Constructor
    floatArray(int m, int n);    //Parameterized Constructor
    ~floatArray();               //Destructor
    bool empty();
    int size();
    int maxsize();
    void reserve(const int &n);
    void clear();
    void push_back(const float &value);
    void print();

    float& at(int index); 
    void resize(const int &n); 
    void pop_back();   
    void sortedInsert(const float &value);
    void erase(int start, int end);
};

#endif