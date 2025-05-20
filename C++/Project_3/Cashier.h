#ifndef CASHIER_H
#define CASHIER_H
//Joseph 

#include <iostream>
#include <vector>
#include "Toy.h"
#include "Child.h"

class Cashier {
public:
    static std::vector<Toy*>::iterator findToy(std::vector<Toy*>& toys, int toyId);
    static void createToy(std::vector<Toy*>& toys, const std::string& type, int id, int maxToys);
    static void removeToy(std::vector<Toy*>& toys, Toy* toy, std::vector<Child*>& children);
};


#endif
