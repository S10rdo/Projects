#include "List.h"
#include <cassert>

                                  
    List::List(): head(nullptr), tail(nullptr), size(0) {}     // constructor: construct an empty list  //Joseph
    List::~List()                                     // destructor: safe deletion of all nodes in the stack
    {
        Node *n = head;                         // point n to the first node
        Node *backup = nullptr;
        while(n != nullptr) {                   // advance n through all nodes in the list
            backup = n;                         // point backup to node n
            n = n->next;                        // advance n to the next node
            delete backup;                      // delete the backup node
        }
    }  
    Iterator List::begin() {                          // return an iterator pointing to the first node (for forward traversal)
        return Iterator(head);
    } 
    Iterator List::end() {                            // return an iterator to the value past the end of the list (nullptr)
        return Iterator(nullptr);
    }
    Iterator List::rbegin() {                         // return an iterator pointing to the tail node (for reverse traversal)
        return Iterator(tail);
    }                    
    Iterator List::rend() {                           // return an iterator to the value past the start of the list (nullptr)
        return Iterator(nullptr);
    }
    bool List::empty()                                // Return true if the list is empty, false otherwise                          
{
    if(head == nullptr) {                      
        return true;
    } else {
        return false;
    }
}
    // Return a reference to the data inside the first node
    Car& List::front() {
        return head->data;
}
    // Return a reference to the data inside the last node
    Car& List::back() {
        return tail->data;
}

    // Add a node to the front of the list   
    void List::push_front(const Car &d)            //Stanley
    {
        Node *n = new Node(d);                      // point n to a new node 
        if( empty() ) {                         // if list is empty, make n the first and last node
            head = tail = n;
        } else {
            n->next = head;                    // link n forward to the first node:    n  -> first
            head->prev = n;                    // link first node back to n:           n <-> first
            head = n;                          // n becomes the new first node
        }
        ++size;
    }
   // Add a node to the back of the list 
    void List::push_back(const Car &d)                   //Stanley            
    {
        if( empty() ) {                         // if list is empty: push_front and exit
            push_front(d);
            return;
        }
        
        Node *n = new Node(d);                      // point n to new node
        n->prev = tail;                        // link n backwards to the last node:       last <- n
        tail->next = n;                        // link last forward to n:                  last <-> n                     
        tail = n;                              // n becomes the new last node
        ++size;
    }
    // Remove the first node in the list
    void List::pop_front()                     //Hong Wei 
    {
        if(empty() ) {                         // if list is empty, exit
            return; 
        }

        Node *n = head;                        // point n to the first node
        head = head->next;                // second node becomes the new first node

        if(head == nullptr) {                  // if list will be empty, reset tail
            tail = nullptr;
        } else {
            head->prev = nullptr;              // if list will have data, link first node backwards to nullptr
            
        }
        delete n;                                   // delete the original first node 
        --size;
    }
    // Remove the last node in the list
    void List::pop_back()           //Hong Wei
    {
        if(empty() ) {                         // if list is empty, exit
            return;
        }

        Node *n = tail;                        // point n to the last node
        tail = tail->prev;                // point tail to the second to last node

        if(tail == nullptr) {                  // if list will be empty, reset head
            head = nullptr;
        } else {                                    // if list will have data, link new tail forwards to nullptr
            tail->next = nullptr;
        }

        delete n;                                   // remove the original last node
        --size;
    }
    // Add a new node before a specified node in the list
    // If successful, return an iterator to the new node, otherwise return the original iterator
    Iterator List::insert(Iterator it, const Car &d)    //Stanley
    {   
        if( empty() || it.current == nullptr ) {// if list is empty or iterator invalid, exit and return the original iterator       
            return it;                               
        }
    
        Node *n = new Node(d);                      // point n to a new node
        n->next = it.current;                       // link n forwards to the node after iterator:        n  -> it
        n->prev = it.current->prev;                 // link n backwards to iterator:                p <-  n  -> it
        it.current->prev = n;                       // link iterator backwards to node n:           p <-  n <-> it

        if(n->prev == nullptr) {                    // if n is first node, point head to n
            head = n;
            ++size;
        } else {                                    // if n is not the first node,
            n->prev->next = n;                      // link previous node forward to n              p <-> n <-> t
            ++size;
        }

        return Iterator(n);                         // return a pointer to the newly inserted node
    }
    // Remove a specified node from the list
    // If successful, return an iterator to the node after the erased node, if this is the end of list return an iterator to nullptr
    // If unsuccesful, return the original iterator
    Iterator List::erase(Iterator it)
    {
        if( empty() || it.current == nullptr ) {
            return it;                              // if list is empty or iterator invalid, exit, return original iterator  
        } else if( it.current == head) {       // if iterator points to the first node, pop_front, return new Iterator to new first node
            pop_front();
            return begin();
        } else if( it.current == tail ) {      // if iterator points to last node, pop_back, return nullptr
            pop_back();
            return Iterator(nullptr);
        }

        Node *n = it.current->next;                 // point n to node after iterator:                                  b <-> it <-> a
        it.current->prev->next = it.current->next;  // link node before iterator forwards to node after iterator:       b  -> a
        it.current->next->prev = it.current->prev;  // link node after iterator backwards to node before iterator:      b <-> a
        
        delete it.current;                          // remove the iterator node

        return Iterator(n);                         // return the node after the iterator node
    }
    // Print a list in forward order
    void List::print()                         // print the list
    {
        Iterator itr = begin();                // point iterator to the first node   
        while( itr.hasNext() ) {                    // advance the iterator forwards through all nodes in list   
            itr.getData().print();      // print the data of the iterator node
            itr.next();                             // point the iterator to the next node
        }   
        std::cout << "\n";    
    }
    // Print a list in reverse order
    void List::printRev()                       // print the list
    {
        Iterator itr = rbegin();               // point iterator to the last node   
        while( itr.hasPrev() ) {                    // advance the iterator backwards through all nodes in list   
            itr.getData().print();      // print the data of the iterator node
            itr.prev();                             // point the iterator to the previous node
        }   
        std::cout << "\n";    
    }
    // Copy one list to another list
    void List::duplicate(List &a,List &b)                              // duplicate list a contents into list b
    {
        Iterator itr = a.begin();                   // point iterator to the first node   
        while( itr.hasNext() ) {                  // advance the iterator through all nodes in list   
            b.push_back(itr.getData());             // copy the data of the iterator node from list A into list B
            itr.next();                           // point the iterator to the next node
        }   
    }
    // Determine if the value d is in the list. 
    // If successful, return an iterator to the node that stores data equivalent to d
    // if unsuccessful, return an interator pointing to nullptr
    Iterator List::find(const Car &d)             
    {
        Iterator itr = begin();                // point iterator to the first node   
        while( itr.hasNext() ) {                    // advance the iterator through all nodes in list  
            if(Equivalent(itr.getData(), d)) {              // if node n stores the equivalent of d, 
                return itr;                         // return an iterator to the node storing the equivalent of d
            }
            itr.next();                             // point iterator to the next node
        }   
        return Iterator(nullptr);                   // if data was not found, return iterator pointing to nullptr
    }
    int List::getSize() const   //Hong Wei
    {
        return size;
    }
    void List::clear() //Joseph
    {
        while(!empty()){
            pop_front();
        }
        size = 0;
    }
    void List::merge(List &s1, List &s2, List &list, bool comparator){ //Stanley
        Iterator it1 = s1.begin();
        Iterator it2 = s2.begin();
        while (it1.hasNext() && it2.hasNext()){
            if(Compare(it1.getData(), it2.getData(), comparator)){
                list.push_back(it1.getData());
                it1.next();
            }else{
                list.push_back(it2.getData());
                it2.next();
            }
        }
        while(it1.hasNext()){
            list.push_back(it1.getData());
            it1.next();
        }
        while(it2.hasNext()){
            list.push_back(it2.getData());
            it2.next();
        }
    }
    void List::mergeSort(List &list, bool comparator){ //Joseph
        assert(list.getSize()>=0);
        if (list.getSize() <= 1) {
            return;
        }
        List LIST1, LIST2;
        Iterator it = list.begin();

        int half = list.getSize()/2;
        int count = 0;

        while(count < half && it.hasNext()){
            LIST1.push_back(it.getData());
            it.next();
            ++count;
        }
        while(it.hasNext()){
            LIST2.push_back(it.getData());
            it.next();
        }
        list.clear();

        mergeSort(LIST1,comparator);
        mergeSort(LIST2,comparator);
        
        merge(LIST1, LIST2, list, comparator);
    }
    void List::reverse(List &list){ //Hong Wei
        Node* current = list.head;
        Node* temp = nullptr;
        Node* prev = nullptr;

        while (current != nullptr){
            temp = current->next;
            current->next = prev;
            current->prev = temp;

            prev = current;
            current = temp; 
        }
        temp = list.head;
        list.head = prev;
    }    