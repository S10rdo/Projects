#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Car.h"

class Node {
    private:
    Car data;                                                  
    Node *next;
    Node *prev;
    public: 
    Node();                     
    Node(const Car &d);
    friend class List;
    friend class Iterator;
                                    
};

#endif