#include "Iterator.h"
                         
    Iterator::Iterator(Node *n): current(n) {             // point iterator to specific node
    }
    void Iterator::next() {                               // advance iterator to next node
        current = current->next;
    }
    void Iterator::prev() {                               // advance iterator to previous node
        current = current->prev;
    }
    bool Iterator::hasNext() {                            // return true if current is a valid node (not nullptr), false otherwise
        if(current != nullptr) { 
            return true; 
        } else {
            return false;
        }
    }
    bool Iterator::hasPrev() {                            // return true if current is a valid node (not nullptr), false otherwise
        if(current != nullptr) { 
            return true; 
        } else {
            return false;
        }
    }    
    Car& Iterator::getData() {                            // return a reference to the data stored in the current node
        return current->data;
    }