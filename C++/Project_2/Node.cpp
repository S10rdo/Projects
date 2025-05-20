#include "Node.h"

    Node::Node(): data(Car()), next(nullptr), prev(nullptr) {}                      
    Node::Node(const Car &d): data(d), next(nullptr), prev(nullptr) {}                              
