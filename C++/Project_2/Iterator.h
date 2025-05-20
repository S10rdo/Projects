#ifndef ITERATOR_H
#define ITERATOR_H
#include "Node.h"

class Iterator {
private:
    Node *current;                            
public:                              
    Iterator(Node *n);
    void next();
    void prev();
    bool hasNext();
    bool hasPrev();
    Car& getData();
    friend class List;
};

#endif