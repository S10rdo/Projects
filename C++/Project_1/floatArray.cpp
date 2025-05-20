#include "floatArray.h"   

floatArray::floatArray():maxValues(5),numValues(0), data( new float [5]{} )//Default Constructor , maxValues = Capacity, numValues = size.    //Joseph
{}              
floatArray::floatArray(int m, int n):maxValues(m),numValues(n), data( new float [m]{} )     //Parameterized Constructor   //Joseph
{}
floatArray::~floatArray()  //Destructor   //Joseph
{
    delete [] data;
}
bool floatArray::empty() //Joseph
{
    if (numValues == 0){
        return true; 
    } else {
        return false;
    }
}
int floatArray::size() //Joseph
{
    
    return numValues;
}
int floatArray::maxsize() //Joseph
{

    return maxValues;
}   
void floatArray::reserve(const int &n) //Stanley, Joseph
{
    if(n<=numValues){
        return;
    }
    if(n > numValues) { 
        float *newspace = (new float [n]); // always gotta do pointer when dealing with dynamic arrays 
        for(int i = 0; i < numValues ; ++i){
            newspace[i] = data[i]; 
        }
        delete [] data; 
        data = newspace; 
        maxValues = n; 
    }
}
void floatArray::clear() //Hong Wei
{

    delete [] data;
    data = (new float [5]{});
    maxValues = 5;
    numValues = 0;

}
void floatArray::push_back(const float &value) //Stanley, Joseph
{
    if(numValues >= maxValues){
        reserve(maxValues*2);
    }
    data[numValues] = value;
    ++numValues;
}
void floatArray::print() //Hong Wei
{
    for(int i=0; i<numValues; ++i) {
        std::cout << data[i] << " ";
    }
        std::cout << "\n";
}

float& floatArray::at(int index){  //Joseph
    assert(index >= 0 && index < maxValues);
    return data[index];
}

void floatArray::resize(const int &n){ //Joseph ,Stanley, Hong Wei
    if( n == numValues){
        return;
    }
    if( n > numValues){
        if( n > maxValues){
            reserve(maxValues*2);
        }
        for(int i = numValues; i < n; ++i){
            data[i] = 0.0;
            numValues = n;
        }
    }
    if( n < numValues){
        assert(n >= 0);
        numValues = n;
    }
}

void floatArray::pop_back(){ //Hong Wei
    if(numValues == 0){
        return;
    } else{
        if(numValues > 0){
            --numValues;
        }
    }
}

void floatArray::sortedInsert(const float &value){ //Joseph , Stanley, Hong Wei
    if(numValues >= maxValues){
        reserve(maxValues*2);
    }
    int index = numValues;

    while(index > 0 && data[index-1] > value) {  
            data[index] = data[index-1];        
            --index;                     
    }
    data[index] = value;
    ++numValues;
}

void floatArray::erase(int start, int end){ //Stanley
    assert(start >= 0 && start < numValues);
    assert(end >= 0 && end < numValues);
    assert(start <= end);
    
    int arrayShift = end - start + 1; 
    for (int i = start; i < numValues - arrayShift; ++i){
        data[i] = data[i + arrayShift];
    }
    numValues -= arrayShift;
}