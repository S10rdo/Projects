#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "Iterator.h"


class List {       
private:                                        
    Node *head;                                 // pointer to the first node                                              
    Node *tail;                                 // pointer to the last node
    int size;
public:                                   
    List();     // constructor: construct an empty list
    ~List();

    Iterator begin();
    Iterator end();
    Iterator rbegin();
    Iterator rend();

    bool empty();
    Car& front();
    Car& back();

    void push_front(const Car &d);
    void push_back(const Car &d);
    void pop_front();
    void pop_back();

    Iterator insert(Iterator it, const Car &d);
    Iterator erase(Iterator it);

    void print();
    void printRev();
    void duplicate(List &a,List &b);                             
    Iterator find(const Car &d);
    int getSize() const;
    void clear();
    static void merge(List &s1, List &s2, List &list, bool comparator);
    static void mergeSort(List &list, bool comparator);
    static void reverse(List &list);
};

#endif